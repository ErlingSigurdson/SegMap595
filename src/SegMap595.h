/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A class for mapping the outputs of a 74HC595 shift register IC
 *           to the segments of a 7-segment display.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595_H
#define SEGMAP595_H


/*--- Includes ---*/

// Macros/constants related to glyphs and mapping.
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

#define SEGMAP595_SEG_NUM           8  // Including a dot segment.

#define SEGMAP595_MSB               7
#define SEGMAP595_ONLY_MSB_SET_MASK (1u << SEGMAP595_MSB)
#define SEGMAP595_ONLY_LSB_SET_MASK 0x01
#define SEGMAP595_ALL_BITS_SET_MASK 0xFF

#define SEGMAP595_COMMON_CATHODE    0
#define SEGMAP595_COMMON_ANODE      1

#define SEGMAP595_GLYPH_SET_MAX_CHAR_NUM 40  // Highest number of glyphs among all provided glyph sets.
#define SEGMAP595_GLYPH_SETS_PROVIDED    2
#define SEGMAP595_GLYPH_SET_1            1
#define SEGMAP595_GLYPH_SET_2            2

// Function return codes. Also serve as possible mapping status values.
#define SEGMAP595_STATUS_INITIAL                 -1
#define SEGMAP595_STATUS_ERR_GLYPH_SET_NUM       -2
#define SEGMAP595_STATUS_ERR_NULLPTR             -3
#define SEGMAP595_STATUS_ERR_MAP_STR_LEN         -4
#define SEGMAP595_STATUS_ERR_MAP_STR_CHAR        -5
#define SEGMAP595_STATUS_ERR_MAP_STR_DUPLICATION -6
#define SEGMAP595_STATUS_ERR_BIT_POS_SET         -7
#define SEGMAP595_STATUS_OK                       0


/****************** DATA TYPES ******************/

class SegMap595Class {
    struct GlyphSet {
        const uint8_t       abc_bytes[SEGMAP595_GLYPH_SET_MAX_CHAR_NUM];
        const unsigned char valid_chars[SEGMAP595_GLYPH_SET_MAX_CHAR_NUM];
        const size_t        glyph_num;
    };

    public:
        /*--- Methods ---*/

        // Default constructor.
        SegMap595Class();

        /* "Load" a map string into an object, specify a display type (based on its common pin) and select a glyph set.
         *
         * Returns:
         * zero if mapping was successful (that is, if the passed map string was valid, the bytes were
         * successfully mapped and the passed glyph set number was valid), negative integer otherwise
         * (see the preprocessor macros list for possible values).
         *
         * If the second parameter equals zero, a common-cathode display is assumed.
         * Otherwise a common-anode display is assumed.
         *
         * The third parameter (if passed) must be an integer from 1 and up to SEGMAP595_GLYPH_SETS_PROVIDED.
         * Glyph set #1 is used by default.
         *
         * Multiple calls to this method are valid, each call will lead to a fresh byte mapping.
         */
        int32_t  init(const char *map_str, int32_t display_common_pin, uint32_t glyph_set_num = SEGMAP595_GLYPH_SET_1);

        /* Get the last mapping status.
         *
         * Returns: zero if mapping was successful, negative integer otherwise
         * (see the preprocessor macros list for possible values).
         */
        int32_t  get_status();

        /* Get a mapped byte (overload #1).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed index is within the array bounds,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(size_t index);

        /* Get a mapped byte (overload #2).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed index is within the array bounds,
         * zero otherwise.
         */
        #if defined(UINT32_MAX) && defined(SIZE_MAX) && (UINT32_MAX > SIZE_MAX)
        uint8_t  get_mapped_byte(uint32_t index);
        #endif

        /* Get a mapped byte (overload #3).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed character is represented in the selected glyph set,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(char represented_char);

        /* Get a mapped byte (overload #4).
         *
         * Returns: a mapped byte if mapping was successful
         * and the passed character is represented in the selected glyph set,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(unsigned char represented_char);

        /* Get the position of the bit that represents a dot segment.
         *
         * Returns: integer less or equal to SEGMAP595_MSB if mapping was successful,
         * bigger integer otherwise.
         */
        uint32_t get_dot_bit_pos();

        /* Get the number of glyphs in the selected glyph set.
         *
         * Returns: a positive integer if mapping was successful,
         * zero otherwise.
         */
        size_t   get_glyph_num();

        /* Get the character represented by a glyph by its index (overload #1).
         *
         * Returns: resprective ASCII code if mapping was successful
         * and the passed index is within the array bounds,
         * zero otherwise.
         */
        char     get_represented_char(size_t index);

        /* Get the character represented by a glyph by its index (overload #2).
         *
         * Returns: resprective ASCII code if mapping was successful
         * and the passed index is within the array bounds,
         * zero otherwise.
         */
        #if defined(UINT32_MAX) && defined(SIZE_MAX) && (UINT32_MAX > SIZE_MAX)
        char     get_represented_char(uint32_t index);
        #endif

        /* Get the pointer to a string that represents a standard (since GCC 4.3 or C++14)
         * binary number notation for a given byte (overload #1).
         *
         * Returns: a pointer to a string if mapping was successful,
         * nullptr otherwise (although the buffer always has a valid
         * address in memory, nullptr serves as an error indicator).
         *
         * String buffer is static and therefore a pointer to it can be returned correctly.
         */
        const char* get_byte_bin_notation_as_str(char byte_to_write_down);

        /* Get the pointer to a string that represents a standard (since GCC 4.3 or C++14)
         * binary number notation for a given byte (overload #2).
         *
         * Returns: a pointer to a string if mapping was successful,
         * nullptr otherwise (although the buffer always has a valid
         * address in memory, nullptr serves as an error indicator).
         *
         * String buffer is static and therefore a pointer to it can be returned correctly.
         */
        const char* get_byte_bin_notation_as_str(unsigned char byte_to_write_down);

        /* Get the pointer to an object's internal buffer that holds the passed map string.
         *
         * Returns: a pointer to a string if mapping was successful,
         * nullptr otherwise (although the buffer always has a valid
         * address in memory, nullptr serves as an error indicator).
         */
        const char* get_map_str();

    private:
        /*--- Variables ---*/

        /* Glyph sets.
         * Aggregate initialization.
         */
        GlyphSet  _glyph_set_1 = {
                                  {SEGMAP595_GLYPH_SET_1_ABC_BYTES},
                                  {SEGMAP595_GLYPH_SET_1_CHARS},
                                  SEGMAP595_GLYPH_SET_1_GLYPH_NUM
                                 };
        GlyphSet  _glyph_set_2 = {
                                  {SEGMAP595_GLYPH_SET_2_ABC_BYTES},
                                  {SEGMAP595_GLYPH_SET_2_CHARS},
                                  SEGMAP595_GLYPH_SET_2_GLYPH_NUM
                                 };
        GlyphSet *_glyph_set_selected;

        // Internal buffer that holds the passed map string.
        char     _map_str[SEGMAP595_SEG_NUM + 1] = {0};

        // Mapping status. See the preprocessor macros list for possible values.
        int32_t  _status = SEGMAP595_STATUS_INITIAL;

        /* Display type (display common pin).
         * Zero for a common-cathode display, any other value for a common-anode display.
         */
        int32_t  _display_common_pin;

        /* Resulting array.
         * If mapping was successful, this array will hold the mapped bytes.
         */
        uint8_t  _mapped_bytes[SEGMAP595_GLYPH_SET_MAX_CHAR_NUM] = {0};

        // Array of values that indicate a bit position number for every display segment.
        uint32_t _bit_pos[SEGMAP595_SEG_NUM] = {0xFFFFFFFF};  // Initial values are intentionally invalid.


        /*--- Methods ---*/

        /* Check the passed glyph set number and "load" the selected glyph set.
         *
         * Returns: zero if the passed glyph set number is valid, negative integer otherwise
         * (see the preprocessor macros list for possible values).
         */
        int32_t select_glyph_set(uint32_t glyph_set_num);

        /* Check the passed map string validity and, if it's valid, copy its contents to the internal buffer.
         *
         * Returns: zero if the passed map string is valid, negative integer otherwise
         * (see the preprocessor macros list for possible values).
         */
        int32_t check_map_str(const char *map_str);

        /* Indicate a bit position for every display segment.
         *
         * Returns: zero if all bit positions were indicated, negative integer otherwise
         * (see the preprocessor macros list for possible values).
         *
         * The map string doesn't get passed because it's already copied
         * to the internal buffer by the moment this method is called.
         */
        int32_t read_map_str();

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
