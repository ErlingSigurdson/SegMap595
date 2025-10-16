/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A class for mapping the outputs of a 74HC595 IC
 *           to the segments of a 7-segment display.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595_H
#define SEGMAP595_H


/*--- Includes ---*/

// Specific macros/constants related to mapping and glyphs.
#include "SegMap595_glyph_set_1.h"
#include "SegMap595_glyph_set_2.h"

// Relevant standard libraries.
#if defined ARDUINO_ARCH_AVR
    #include <stdint.h>
#else
    #include <cstdint>
#endif


/*--- Misc ---*/

#define SEGMAP595_SEG_NUM             8  // Including a dot segment.
#define SEGMAP595_GLYPH_SETS_PROVIDED 2

#define SEGMAP595_MSB                 7
#define SEGMAP595_ONLY_MSB_SET        (1u << SEGMAP595_MSB)
#define SEGMAP595_ALL_BITS_SET_MASK   0xFF

#define SEGMAP595_COMMON_CATHODE      0
#define SEGMAP595_COMMON_ANODE        1

// Function return codes.
#define SEGMAP595_STATUS_INIT                    -1
#define SEGMAP595_STATUS_ERR_GLYPH_SET_NUMBER    -2
#define SEGMAP595_STATUS_ERR_NULLPTR             -3
#define SEGMAP595_STATUS_ERR_MAP_STR_LEN         -4
#define SEGMAP595_STATUS_ERR_MAP_STR_CHAR        -5
#define SEGMAP595_STATUS_ERR_MAP_STR_DUPLICATION -6
#define SEGMAP595_STATUS_ERR_BIT_POS_SET         -7
#define SEGMAP595_STATUS_OK                       0


/****************** DATA TYPES ******************/

class SegMap595Class {
    public:
        /*--- Methods ---*/

        // Default constructor.
        SegMap595Class();

        /* "Load" a map string into an object, specify a display type and pick a glyph set.
         *
         * Returns:
         * 0 if mapping was successful (that is, if the passed map string was valid, the bytes were
         * successfully mapped and the passed glyph set number was valid), negative integer otherwise
         * (see preprocessor macros list for possible values).
         *
         * If the second parameter equals zero, a common cathode display is assumed.
         * Otherwise a common anode display is assumed.
         *
         * The third parameter must be an integer from 1 and up to SEGMAP595_GLYPH_SETS_PROVIDED.
         *
         * Multiple calls to this method are valid, each call will lead to a fresh byte mapping.
         */
        int32_t  init(const char *map_str, int32_t display_common_pin, uint32_t chosen_glyph_set_number = 1);

        /* Get the mapping status.
         * 
         * Returns: 0 if mapping was successful, negative integer otherwise
         * (see preprocessor macros list for possible values).
         */
        int32_t  get_status();

        /* Get a mapped byte (overload #1).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed index is within the array bounds,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(uint32_t index);

        /* Get a mapped byte (overload #2).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed character is represented in the chosen glyph set,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(unsigned char char_represented);

        /* Get a mapped byte (overload #3).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed character is represented in the chosen glyph set,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(char char_represented);

        /* Get the position of the bit that represents the dot segment.
         *
         * Returns: integer less or equal to SEGMAP595_MSB if mapping was successful,
         * bigger integer otherwise.
         */
        uint32_t get_dot_bit_pos();

        /* Get a pointer to an object's internal buffer that holds the passed map string.
         *
         * Returns: a pointer to the string if mapping was successful,
         * nullptr otherwise (although the buffer always has a valid
         * address in memory, nullptr serves as an error indicator).
         */
        const char* get_map_str();

    private:
        /*--- Variables ---*/

        /* Array of bytes mapped as if the map string is "@ABCDEFG" (@ is for a dot).
         * Set #1.
         */
        const uint8_t _mapped_alphabetically_glyph_set_1[] = {SEGMAP595_GLYPH_SET_1_MAPPED_ALPHABETICALLY_ALL};

        /* Same as previous variable, but for another glyph set.
         * Set #2.
         */
        const uint8_t _mapped_alphabetically_glyph_set_2[] = {SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_ALL};

        uint8_t *_mapped_alphabetical_chosen = nullptr;

        // Internal buffer.
        char     _map_str[SEGMAP595_SEG_NUM + 1] = {0};

        // Mapping status. See preprocessor macros list for possible values.
        int32_t  _status = SEGMAP595_STATUS_INIT;

        /* Resulting array.
         * If the passed map string was valid and the characters were successfully mapped,
         * this array will hold the mapped characters.
         */
        uint8_t  _mapped_bytes[SEGMAP595_CHAR_NUM] = {0};

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
