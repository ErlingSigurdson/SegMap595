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
#include <cstring>


/*************** GLOBAL VARIABLES ***************/

SegMap595Class SegMap595;


/******************* FUNCTIONS ******************/

/*--- Constructor ---*/

SegMap595Class::SegMap595Class()
{
}


/*--- Methods ---*/

int32_t SegMap595Class::init(const char *map_str, bool display_common_pin)
{
    _status = check_map_str(map_str);

    if (_status < 0) {
        return _status;
    }

    _status = read_map_str();

    if (_status < 0) {
        return _status;
    }

    map_characters(display_common_pin);
    
    return _status;
}

int32_t SegMap595Class::check_map_str(const char *map_str)
{
    if (map_str == nullptr) {
        return SEGMAP595_STATUS_ERR_NULLPTR;
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

void SegMap595Class::map_characters(bool display_common_pin)
{
    for (size_t i = 0; i < SEGMAP595_CHAR_NUM; ++i) {
        for (size_t j = 0; j < SEGMAP595_SEG_NUM; ++j) {
            uint8_t mask = static_cast<uint8_t>(1u << _bit_pos[j]);
            if ((_mapped_alphabetical[i] << j) & SEGMAP595_ONLY_MSB_SET) {
                _mapped_characters[i] |= mask;
            } else {
                _mapped_characters[i] &= ~mask;
            }
        }
    }

    if (display_common_pin != SEGMAP595_COMMON_CATHODE) {
        for (size_t i = 0; i < SEGMAP595_CHAR_NUM; ++i) {
            _mapped_characters[i] ^= static_cast<uint8_t>(SEGMAP595_ALL_BITS_SET_MASK);  // Toggle all bits.
        }
    }
}

int32_t SegMap595Class::get_status()
{
    return _status;
}

uint8_t SegMap595Class::get_mapped_character(uint32_t index)
{
    if (_status < 0 || index >= SEGMAP595_CHAR_NUM) {
        return 0;
    }

    return _mapped_characters[index];
}

uint32_t SegMap595Class::get_dot_bit_pos()
{
    if (_status < 0) {
        return SEGMAP595_MSB + 1;
    } else {
        return _bit_pos[0];  /* Dot (represented by the @ sign) is the first character
                              * whose position is determined when a map string gets analyzed.
                              */
    }
}

const char* SegMap595Class::get_map_str()
{
    if (_status == SEGMAP595_STATUS_OK) {  // If character mapping was successful.
        return _map_str;
    } else {
        return nullptr;
    }
}
