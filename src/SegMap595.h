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

// Specific macros/constants related to glyphs and mapping.
#include "SegMap595_glyph_set_1.h"
#include "SegMap595_glyph_set_2.h"

// Relevant standard libraries.
#if defined ARDUINO_ARCH_AVR || defined ARDUINO_ARCH_MEGAAVR
    #include <stddef.h>  // For size_t.
    #include <stdint.h>  // For fixed-width types.
#else
    #include <cstddef>   // For size_t.
    #include <cstdint>   // For fixed-width types.
#endif


/*--- Misc ---*/

#define SEGMAP595_SEG_NUM             8  // Including a dot segment.

#define SEGMAP595_MSB                 7
#define SEGMAP595_ONLY_MSB_SET_MASK   (1u << SEGMAP595_MSB)
#define SEGMAP595_ALL_BITS_SET_MASK   0xFF

#define SEGMAP595_COMMON_CATHODE      0
#define SEGMAP595_COMMON_ANODE        1

#define SEGMAP595_GLYPH_SET_MAX_CHAR_NUM 40  // Highest number of characters among all provided glyph sets.
#define SEGMAP595_GLYPH_SETS_PROVIDED    2
#define SEGMAP595_GLYPH_SET_1            1
#define SEGMAP595_GLYPH_SET_2            2

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

        /* "Load" a map string into an object, specify a display type and (optionally) choose a glyph set.
         *
         * Returns:
         * 0 if mapping was successful (that is, if the passed map string was valid, the bytes were
         * successfully mapped and the passed glyph set number was valid), negative integer otherwise
         * (see preprocessor macros list for possible values).
         *
         * If the second parameter equals zero, a common cathode display is assumed.
         * Otherwise a common anode display is assumed.
         *
         * The third parameter must be an integer from 1 and up to the number of provided glyph sets.
         *
         * Multiple calls to this method are valid, each call will lead to a fresh byte mapping.
         */
        int32_t  init(const char *map_str, int32_t display_common_pin, uint32_t glyph_set_num = 1);

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

        /* Get the position of the bit that represents a dot segment.
         *
         * Returns: integer less or equal to SEGMAP595_MSB if mapping was successful,
         * bigger integer otherwise.
         */
        uint32_t get_dot_bit_pos();

        /* Get a pointer to an object's internal buffer that holds the passed map string.
         *
         * Returns: a pointer to a string if mapping was successful,
         * nullptr otherwise (although the buffer always has a valid
         * address in memory, nullptr serves as an error indicator).
         */
        const char* get_map_str();

        /* Get a number of glyphs in the chosen set.
         *
         * Returns: a positive integer if mapping was successful,
         * zero otherwise.
         */
        size_t get_glyph_num();

    private:
        /*--- Variables ---*/

            /*--- Glyph set #1 ---*/

            // Number of glyphs in the set.
            const size_t  _glyph_set_1_char_num = SEGMAP595_GLYPH_SET_1_CHAR_NUM;

            /* Array of bytes mapped as if the map string is "@ABCDEFG" (@ is for a dot).
             */
            const uint8_t _glyph_set_1_mapped_alphabetically[SEGMAP595_GLYPH_SET_1_CHAR_NUM] =
                                                            {SEGMAP595_GLYPH_SET_1_MAPPED_ALPHABETICALLY_ALL};

            const unsigned char _glyph_set_1_valid_chars[SEGMAP595_GLYPH_SET_1_CHAR_NUM] =
                                                        {SEGMAP595_GLYPH_SET_1_CHAR_ALL};


            /*--- Glyph set #2 ---*/

            // Same logic for another set.
            const size_t  _glyph_set_2_char_num = SEGMAP595_GLYPH_SET_2_CHAR_NUM;
            const uint8_t _glyph_set_2_mapped_alphabetically[SEGMAP595_GLYPH_SET_2_CHAR_NUM] =
                                                            {SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_ALL};
            const unsigned char _glyph_set_2_valid_chars[SEGMAP595_GLYPH_SET_2_CHAR_NUM] =
                                                        {SEGMAP595_GLYPH_SET_2_CHAR_ALL};


            /*--- Chosen glyph set ---*/

            uint32_t _glyph_set_chosen;
            size_t   _glyph_set_chosen_char_num;
            const uint8_t       *_glyph_set_chosen_mapped_alphabetically = nullptr;
            const unsigned char *_glyph_set_chosen_valid_chars;


            /*--- Misc ---*/

            // Internal buffer.
            char     _map_str[SEGMAP595_SEG_NUM + 1] = {0};

            // 0 means common cathode, any other value means common anode.
            int32_t  _display_common_pin;

            // Mapping status. See preprocessor macros list for possible values.
            int32_t  _status = SEGMAP595_STATUS_INIT;

            /* Resulting array.
             * If mapping was successful, this array will hold the mapped bytes.
             */
            uint8_t  _mapped_bytes[SEGMAP595_GLYPH_SET_MAX_CHAR_NUM] = {0};

            // Array of values that indicate a bit position number for every display segment.
            uint32_t _bit_pos[SEGMAP595_SEG_NUM] = {0xFFFFFFFF};  // Initial values are intentionally invalid.


        /*--- Methods ---*/

        /* Check the passed map string validity and, if it's valid, copy its contents to the internal buffer.
         *
         * Returns: 0 if the passed map string is valid, negative integer otherwise
         * (see preprocessor macros list for possible values).
         */
        int32_t check_map_str(const char *map_str);

        /* Indicate bit positions for every display segment.
         *
         * Returns: 0 if all bit positions are indicated, negative integer otherwise
         * (see preprocessor macros list for possible values).
         *
         * The map string isn't passed because it's already copied
         * to the internal buffer by the moment this method is called. 
         */
        int32_t read_map_str();

        /* Check a passed .
         *
         * Returns: 0 if the number of chosen glyph set is valid, negative integer otherwise
         * (see preprocessor macros list for possible values). 
         */
        int32_t choose_glyph_set(uint32_t glyph_set_chosen);


        /* Do the main job of mapping the bytes.
         *
         * Returns: nothing.
         */
        void    map_bytes(int32_t display_common_pin);
};


/*************** GLOBAL VARIABLES ***************/

/* An Arduino-style singleton object.
 * More instances of the same class can be created if necessary.
 */
extern SegMap595Class SegMap595;


#endif  // Include guards.
