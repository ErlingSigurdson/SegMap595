/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.cpp
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A class for mapping the parallel outputs of a 74HC595 shift
 *           register IC to the segments of a 7-segment display.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

// This source file's own header file.
#include "SegMap595.h"

// Relevant standard libraries.
#if defined ARDUINO_ARCH_AVR || defined ARDUINO_ARCH_MEGAAVR
    #include <string.h>
#else
    #include <cstring>
#endif


/*************** GLOBAL VARIABLES ***************/

SegMap595Class SegMap595;


/******************* FUNCTIONS ******************/

/*--- Constructors ---*/

SegMap595Class::SegMap595Class() {}


/*--- Public methods ---*/

int32_t SegMap595Class::init(const char *map_str, DisplayType display_common_pin, GlyphSetId glyph_set_id)
{
    _status = select_glyph_set(glyph_set_id);  /* Inside this call the passed glyph set ID
                                                * gets copied into a private member variable.
                                                */

    if (_status < 0) {
        return _status;
    }

    _status = check_map_str(map_str);          /* Inside this call the passed map string
                                                * gets copied into a private member buffer.
                                                */

    if (_status < 0) {
        return _status;
    }

    _status = read_map_str();

    if (_status < 0) {
        return _status;
    }

    _status = map_bytes(display_common_pin);   /* Inside this call the value that defines the display type
                                                * gets copied into a private member variable.
                                                */

    return _status;
}

int32_t SegMap595Class::get_status()
{
    return _status;
}

uint8_t SegMap595Class::get_mapped_byte(size_t index)
{
    if (_status < 0 || index >= _glyph_set_selected->glyph_num) {
        return 0;
    }

    return _mapped_bytes[index];
}

#if defined(UINT32_MAX) && defined(SIZE_MAX) && (UINT32_MAX > SIZE_MAX)
uint8_t SegMap595Class::get_mapped_byte(uint32_t index)
{
    return get_mapped_byte(static_cast<size_t>(index));
}
#endif

uint8_t SegMap595Class::get_mapped_byte(char represented_char)
{
    if (_status < 0) {
        return 0;
    }

    constexpr int32_t ascii_code_diff = 'a' - 'A';
    if (represented_char >= 'a' && represented_char <= 'z') {
        represented_char -= ascii_code_diff;
    }

    for (size_t i = 0; i < _glyph_set_selected->glyph_num; ++i) {
        if (represented_char == _glyph_set_selected->chars[i]) {
            return _mapped_bytes[i];
        }
    }

    return 0;
}

uint8_t SegMap595Class::get_mapped_byte(unsigned char represented_char)
{
    return get_mapped_byte(static_cast<char>(represented_char));
}

int32_t SegMap595Class::get_dot_bit_pos()
{
    if (_status < 0) {
        return _status;
    } else {
        return _bit_pos[0];  /* Dot (represented by @) is the first character
                              * whose position is checked when a map string gets analyzed.
                              */
    }
}

size_t SegMap595Class::get_glyph_num()
{
    if (_status < 0) {
        return 0;
    } else {
        return _glyph_set_selected->glyph_num;
    }
}

char SegMap595Class::get_represented_char(size_t index)
{
    if (_status < 0 || index >= _glyph_set_selected->glyph_num) {
        return 0;
    }

    return _glyph_set_selected->chars[index];
}

#if defined(UINT32_MAX) && defined(SIZE_MAX) && (UINT32_MAX > SIZE_MAX)
char SegMap595Class::get_represented_char(uint32_t index)
{
    return get_represented_char(static_cast<size_t>(index));
}
#endif

const char* SegMap595Class::get_byte_bin_notation_as_str(unsigned char byte_to_write_down)
{
    // Standard (since GCC 4.3 and C++14) binary number notation prefix "0b".
    constexpr size_t bin_notation_prefix_len = 2;

    // Binary notation length for a byte: prefix + 8 bits.
    constexpr size_t notation_len = bin_notation_prefix_len + SEGMAP595_SEG_NUM;

    static char buf[notation_len + 1] = {0};  // Plus one byte for the null terminator.
    buf[0] = '0';
    buf[1] = 'b';

    for (int32_t bit_pos = SEGMAP595_MSB; bit_pos >= 0; --bit_pos) {
        uint8_t shifted = byte_to_write_down >> bit_pos;
        if ((shifted & SEGMAP595_ONLY_LSB_SET_MASK) != 0) {
            buf[bin_notation_prefix_len + SEGMAP595_MSB - bit_pos] = '1';
        } else {
            buf[bin_notation_prefix_len + SEGMAP595_MSB - bit_pos] = '0';
        }
    }
    buf[notation_len] = '\0';

    return buf;
}

const char* SegMap595Class::get_byte_bin_notation_as_str(char byte_to_write_down)
{
    return get_byte_bin_notation_as_str(static_cast<unsigned char>(byte_to_write_down));
}

const char* SegMap595Class::get_map_str()
{
    if (_status < 0) {
        return nullptr;
    } else {
        return _map_str;
    }
}


/* --- Private methods ---*/

int32_t SegMap595Class::select_glyph_set(GlyphSetId glyph_set_id)
{
    switch (glyph_set_id) {
        case SegMap595GlyphSet1:
            _glyph_set_selected = &_glyph_set_1;
            break;

        case SegMap595GlyphSet2:
            _glyph_set_selected = &_glyph_set_2;
            break;

        default:
            return SEGMAP595_STATUS_ERR_GLYPH_SET_ID;
    }

    return SEGMAP595_STATUS_OK;
}

int32_t SegMap595Class::check_map_str(const char *map_str)
{
    if (map_str == nullptr) {
        return SEGMAP595_STATUS_ERR_MAP_STR_NULLPTR;
    }

    size_t str_len = strlen(map_str);
    if (str_len != SEGMAP595_SEG_NUM) {
        return SEGMAP595_STATUS_ERR_MAP_STR_LEN;
    }

    // Copy to the internal buffer.
    memcpy(_map_str, map_str, SEGMAP595_SEG_NUM);
    _map_str[SEGMAP595_SEG_NUM] = '\0';

    // Convert to uppercase.
    constexpr int32_t ascii_code_diff = 'a' - 'A';
    for (size_t i = 0; i < SEGMAP595_SEG_NUM; ++i) {
        if (_map_str[i] >= 'a' && _map_str[i] <= 'g') {
            _map_str[i] -= ascii_code_diff;
        }
    }

    // Check for invalid characters.
    for (size_t i = 0; i < SEGMAP595_SEG_NUM; ++i) {
        if (_map_str[i] < '@' || _map_str[i] > 'G') {  // Only ASCII characters from '@' to 'G' are valid.
            return SEGMAP595_STATUS_ERR_MAP_STR_INVALID_CHAR;
        }
    }

    // Check for character duplication.
    for (size_t i = 0; i < SEGMAP595_SEG_NUM; ++i) {
        for (size_t j = i + 1u; j < SEGMAP595_SEG_NUM; ++j) {
            if (_map_str[i] == _map_str[j]) {
                return SEGMAP595_STATUS_ERR_MAP_STR_CHAR_DUPLICATION;
            }
        }
    }

    return SEGMAP595_STATUS_OK;
}

int32_t SegMap595Class::read_map_str()
{
    int32_t bit_pos_set = 0;
    char current_char = '@';
    for (size_t i = 0; i < SEGMAP595_SEG_NUM; ++i, ++current_char) {
        for (size_t j = 0; j < SEGMAP595_SEG_NUM; ++j) {
            if (_map_str[j] == current_char) {
                _bit_pos[i] = SEGMAP595_MSB - j;
                ++bit_pos_set;
                break;
            }
        }
    }

    // Bit positions must be set for all segments. If not, that's an error.
    if (bit_pos_set == SEGMAP595_SEG_NUM) {
        return SEGMAP595_STATUS_OK;
    } else {
        return SEGMAP595_STATUS_ERR_BIT_POS_SET;
    }
}

int32_t SegMap595Class::map_bytes(DisplayType display_common_pin)
{
    if (display_common_pin != SegMap595CommonCathode && display_common_pin != SegMap595CommonAnode) {
        return SEGMAP595_STATUS_ERR_INVALID_DISPLAY_TYPE;
    } else {
        _display_common_pin = display_common_pin;
    }

    for (size_t i = 0; i < _glyph_set_selected->glyph_num; ++i) {
        for (size_t j = 0; j < SEGMAP595_SEG_NUM; ++j) {
            uint8_t mask = static_cast<uint8_t>(1u << _bit_pos[j]);
            if ((_glyph_set_selected->abc_bytes[i] << j) & SEGMAP595_ONLY_MSB_SET_MASK) {
                _mapped_bytes[i] |= mask;
            } else {
                _mapped_bytes[i] &= ~mask;
            }
        }
    }

    if (_display_common_pin == SegMap595CommonAnode) {
        for (size_t i = 0; i < _glyph_set_selected->glyph_num; ++i) {
            _mapped_bytes[i] ^= static_cast<uint8_t>(SEGMAP595_ALL_BITS_SET_MASK);  // Toggle all bits.
        }
    }

    return SEGMAP595_STATUS_OK;
}
