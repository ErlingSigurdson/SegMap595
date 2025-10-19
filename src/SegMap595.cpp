/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.cpp
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A class for mapping the outputs of a 74HC595 IC
 *           to the segments of a 7-segment display.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

// This source file's own header file.
#include "SegMap595.h"

// Relevant standard libraries.
#if defined ARDUINO_ARCH_AVR
    #include <string.h>
#else
    #include <cstring>
#endif


/*************** GLOBAL VARIABLES ***************/

SegMap595Class SegMap595;


/******************* FUNCTIONS ******************/

/*--- Constructor ---*/

SegMap595Class::SegMap595Class() {}


/*--- Methods ---*/

int32_t SegMap595Class::init(const char *map_str, int32_t display_common_pin, uint32_t glyph_set_num)
{
    // Default value of glyph_set_num is 1.
    _status = choose_glyph_set(glyph_set_num);  /* Within this call the passed glyph set number
                                                 * gets copied into a private member variable.
                                                 */

    if (_status < 0) {
        return _status;
    }

    _status = check_map_str(map_str);           /* Within this call the passed map string
                                                 * gets copied into a private member buffer.
                                                 */

    if (_status < 0) {
        return _status;
    }

    _status = read_map_str();

    if (_status < 0) {
        return _status;
    }

    map_bytes(display_common_pin);              /* Within this call the value that defines the display type
                                                 * gets copied into a private member variable.
                                                 */

    return _status;
}

int32_t SegMap595Class::choose_glyph_set(uint32_t glyph_set_num)
{
    if (glyph_set_num < 1 || glyph_set_num > SEGMAP595_GLYPH_SETS_PROVIDED) {
        return _status = SEGMAP595_STATUS_ERR_GLYPH_SET_NUM;
    }

    switch (glyph_set_num) {
        case SEGMAP595_GLYPH_SET_1:
            _glyph_set_chosen = &_glyph_set_1;
            break;

        case SEGMAP595_GLYPH_SET_2:
            _glyph_set_chosen = &_glyph_set_2;
            break;

        default:
            break;  // Do nothing and hail MISRA.
    }

    return SEGMAP595_STATUS_OK;
}

int32_t SegMap595Class::check_map_str(const char *map_str)
{
    if (map_str == nullptr) {
        return _status = SEGMAP595_STATUS_ERR_NULLPTR;
    }

    size_t str_len = strlen(map_str);
    if (str_len != SEGMAP595_SEG_NUM) {
        return _status = SEGMAP595_STATUS_ERR_MAP_STR_LEN;
    }

    // Copy to internal buffer.
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
            return _status = SEGMAP595_STATUS_ERR_MAP_STR_CHAR;
        }
    }

    // Check for character duplication.
    for (size_t i = 0; i < SEGMAP595_SEG_NUM; ++i) {
        for (size_t j = i + 1u; j < SEGMAP595_SEG_NUM; ++j) {
            if (_map_str[i] == _map_str[j]) {
                return _status = SEGMAP595_STATUS_ERR_MAP_STR_DUPLICATION;
            }
        }
    }

    return _status = SEGMAP595_STATUS_OK;
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

    // Bit position must be set for all segments. If not, that's an error.
    if (bit_pos_set == SEGMAP595_SEG_NUM) {
        return SEGMAP595_STATUS_OK;
    } else {
        return SEGMAP595_STATUS_ERR_BIT_POS_SET;
    }
}

void SegMap595Class::map_bytes(int32_t display_common_pin)
{
    _display_common_pin = display_common_pin;

    for (size_t i = 0; i < _glyph_set_chosen->glyph_num; ++i) {
        for (size_t j = 0; j < SEGMAP595_SEG_NUM; ++j) {
            uint8_t mask = static_cast<uint8_t>(1u << _bit_pos[j]);
            if ((_glyph_set_chosen->abc_bytes[i] << j) & SEGMAP595_ONLY_MSB_SET_MASK) {
                _mapped_bytes[i] |= mask;
            } else {
                _mapped_bytes[i] &= ~mask;
            }
        }
    }

    if (_display_common_pin != SEGMAP595_COMMON_CATHODE) {
        for (size_t i = 0; i < _glyph_set_chosen->glyph_num; ++i) {
            _mapped_bytes[i] ^= static_cast<uint8_t>(SEGMAP595_ALL_BITS_SET_MASK);  // Toggle all bits.
        }
    }
}

int32_t SegMap595Class::get_status()
{
    return _status;
}

uint8_t SegMap595Class::get_mapped_byte(size_t index)
{
    if (_status < 0 || index >= _glyph_set_chosen->glyph_num) {
        return 0;
    }

    return _mapped_bytes[index];
}

uint8_t SegMap595Class::get_mapped_byte(uint32_t index)
{
    return get_mapped_byte(static_cast<size_t>(index));
}

uint8_t SegMap595Class::get_mapped_byte(unsigned char char_represented)
{
    if (_status < 0) {
        return 0;
    }

    constexpr int32_t ascii_code_diff = 'a' - 'A';
    if (char_represented >= 'a' && char_represented <= 'z') {
        char_represented -= ascii_code_diff;
    }

    for (size_t i = 0; i < _glyph_set_chosen->glyph_num; ++i) {
        if (char_represented == _glyph_set_chosen->valid_chars[i]) {
            return _mapped_bytes[i];
        }
    }

    return 0;
}

uint8_t SegMap595Class::get_mapped_byte(char char_represented)
{
    return get_mapped_byte(static_cast<unsigned char>(char_represented));
}

uint32_t SegMap595Class::get_dot_bit_pos()
{
    if (_status < 0) {
        return SEGMAP595_MSB + 1;
    } else {
        return _bit_pos[0];  /* Dot (represented by @ sign) is the first character
                              * whose position is determined when a map string gets analyzed.
                              */
    }
}

size_t SegMap595Class::get_glyph_num()
{
    if (_status < 0) {
        return 0;
    } else {
        return _glyph_set_chosen->glyph_num;
    }
}

const char* SegMap595Class::get_map_str()
{
    if (_status < 0) {
        return nullptr;
    } else {
        return _map_str;
    }
}
