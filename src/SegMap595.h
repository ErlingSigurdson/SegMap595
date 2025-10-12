/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A class for mapping the outputs of a 74HC595 IC
 *           to the segments of a 7-segment display.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:    The init() method's first parameter is a map string, that is,
 *           a C-style (null-terminated) string that must reflect the actual
 *           (physical) order of connections made between parallel outputs
 *           of a 74HC595 and segment control pins of a 7-segment display.
 *
 *           The map string must consist of exactly 8 ASCII characters:
 *           @, A, B, C, D, E, F and G. Every character corresponds to a single
 *           segment (@ stands for a dot). The first (leftmost) character
 *           in the map string corresponds to the 7th bit of the IC's parallel
 *           output (Q7 output), the second character corresponds to the 6th
 *           bit (Q6 output), etc.
 *
 *           Uppercase characters may be replaced with their lowercase
 *           counterparts. Any other characters are invalid. Duplicating
 *           characters in the map string is invalid.
 *
 *           If the map string is valid, mapped characters (custom formed bytes
 *           that correspond to symbols to be output on a 7-segment display)
 *           will be placed in a member array in the ascending order:
 *           from 0 to 9, from A to Z, dash and underscore on top. Undisplayable
 *           symbols ('M', 'V', 'W', 'X') are omitted. The mapped characters
 *           can be then retrieved using get_mapped_character() method.
 *
 *           The dot bit will be in an "off" state (cleared for a common cathode
 *           display, set for a common anode display) in all mapped characters,
 *           therefore you will have to manipulate this bit in your code
 *           as necessary. The dot bit position within a byte is indicated
 *           by get_dot_bit_pos() method return value.
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595_H
#define SEGMAP595_H


/*--- Includes ---*/

//Macros/constants related to characters to be mapped.
#include "SegMap595Characters.h"

// Relevant standard libraries.
#if defined ARDUINO_ARCH_AVR
    #include <stdint.h>
#else
    #include <cstdint>
#endif


/*--- Misc ---*/

#define SEGMAP595_SEG_NUM           8     // Including a dot segment.
#define SEGMAP595_CHAR_NUM          34

#define SEGMAP595_MSB               7
#define SEGMAP595_ONLY_MSB_SET      (1u << SEGMAP595_MSB)

#define SEGMAP595_COMMON_CATHODE    0
#define SEGMAP595_COMMON_ANODE      1

#define SEGMAP595_ALL_BITS_SET_MASK 0xFF

// Function return codes.
#define SEGMAP595_STATUS_INIT                    -1
#define SEGMAP595_STATUS_ERR_NULLPTR             -2
#define SEGMAP595_STATUS_ERR_MAP_STR_LEN         -3
#define SEGMAP595_STATUS_ERR_MAP_STR_CHAR        -4
#define SEGMAP595_STATUS_ERR_MAP_STR_DUPLICATION -5
#define SEGMAP595_STATUS_ERR_BIT_POS_SET         -6
#define SEGMAP595_STATUS_OK                       0


/****************** DATA TYPES ******************/

class SegMap595Class {
    public:
        /*--- Methods ---*/

        // Default constructor.
        SegMap595Class();

        /* "Load" a map string into an object.
         * Returns: 0 if the passed map string was valid and the characters were successfully mapped,
         * negative integer otherwise (see preprocessor macros list for possible values).
         *
         * If the second parameter equals zero, a common cathode display is assumed.
         * Otherwise a common anode display is assumed.
         *
         * Multiple calls for this method are valid, each call will lead to a fresh character mapping.
         */
        int32_t  init(const char *map_str, int32_t display_common_pin);

        /* Get the mapping status (whether the passed map string was valid and the characters were successfully mapped).
         * Returns: 0 if the passed map string was valid and the characters were successfully mapped,
         * negative integer otherwise (see preprocessor macros list for possible values).
         */
        int32_t  get_status();

        /* Get a mapped character (overload #1).
         * Returns: a mapped character (custom formed byte) if the passed map string was valid,
         * the characters were successfully mapped and the passed index is within the array bounds,
         * zero otherwise.
         */
        uint8_t  get_mapped_character(uint32_t index);

        /* Get a mapped character (overload #2).
         * Returns: a mapped character (custom formed byte) if the passed map string was valid,
         * the characters were successfully mapped and the character specified to be retrieved is valid,
         * zero otherwise.
         */
        uint8_t  get_mapped_character(char char_to_get);

        /* Get the position of the bit that represents the dot segment.
         * Returns: integer less or equal to SEGMAP595_MSB if the passed map string was valid
         * and the characters were successfully mapped, bigger integer otherwise.
         */
        uint32_t get_dot_bit_pos();

        /* Get a pointer to an object's internal buffer that holds the passed map string.
         * Returns: a pointer to the string if the passed map string was valid and the characters were successfully
         * mapped, nullptr otherwise (although the buffer always has a valid address in memory, nullptr serves
         * as an error indicator).
         */
        const char* get_map_str();

    private:
        /*--- Variables ---*/

        // Array of bytes formed as if the map string is "@ABCDEFG" (@ is for dot).
        const uint8_t _mapped_alphabetical[SEGMAP595_CHAR_NUM] = {SEGMAP595_MAP_ALPHABETICAL_ALL_CHARS};

        // Internal buffer.
        char     _map_str[SEGMAP595_SEG_NUM + 1] = {0};

        // Mapping status. See preprocessor macros list for possible values.
        int32_t  _status = SEGMAP595_STATUS_INIT;

        /* Resulting array.
         * If the passed map string was valid and the characters were successfully mapped,
         * this array will hold the mapped characters.
         */
        uint8_t  _mapped_characters[SEGMAP595_CHAR_NUM] = {0};

        // Array of values that indicate a bit position number for every display segment.
        uint32_t _bit_pos[SEGMAP595_SEG_NUM] = {0xFFFFFFFF};  // Initial values, intentionally invalid.


        /*--- Methods ---*/

        /* Check the passed map string validity and, if it's valid, copy its contents to the internal buffer.
         * Returns: 0 if the passed map string is valid, negative integer otherwise (see preprocessor macros
         * list for possible values).
         */
        int32_t check_map_str(const char *map_str);

        /* Indicate bit positions for every display segment.
         * Returns: 0 if all bit positions are indicated, negative integer otherwise (see preprocessor macros
         * list for possible values).
         *
         * The map string isn't passed because it's already copied
         * to the internal buffer by the moment of this method call. 
         */
        int32_t read_map_str();

        /* Do the main job of mapping the characters.
         * Returns: nothing.
         */
        void    map_characters(int32_t display_common_pin);
};


/*************** GLOBAL VARIABLES ***************/

/* An Arduino-style singleton object.
 * More instances of the same class can be created if necessary.
 */
extern SegMap595Class SegMap595;


#endif  // Include guards.
