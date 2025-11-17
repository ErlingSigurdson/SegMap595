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

// Glyph set-specific macros.
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

#define SEGMAP595_SEG_NUM 8  // Including a dot segment, also known as a decimal point or 'DP'.

#define SEGMAP595_GLYPH_SET_MAX_GLYPH_NUM 40  // Highest number of glyphs among all provided glyph sets.

#define SEGMAP595_MSB               7
#define SEGMAP595_ONLY_LSB_SET_MASK 0x01u
#define SEGMAP595_ONLY_MSB_SET_MASK (SEGMAP595_ONLY_LSB_SET_MASK << SEGMAP595_MSB)
#define SEGMAP595_ALL_BITS_SET_MASK 0xFF

// Mapping status codes. Double as return codes for some methods.
#define SEGMAP595_STATUS_INITIAL                      -1
#define SEGMAP595_STATUS_ERR_GLYPH_SET_ID             -2
#define SEGMAP595_STATUS_ERR_MAP_STR_NULLPTR          -3
#define SEGMAP595_STATUS_ERR_MAP_STR_LEN              -4
#define SEGMAP595_STATUS_ERR_MAP_STR_INVALID_CHAR     -5
#define SEGMAP595_STATUS_ERR_MAP_STR_CHAR_DUPLICATION -6
#define SEGMAP595_STATUS_ERR_BIT_POS_SET              -7
#define SEGMAP595_STATUS_OK                            0


/****************** DATA TYPES ******************/

class SegMap595Class {
    public:
        /*--- Data types ---*/

        enum class DisplayType {
            CommonCathode = 0,
            CommonAnode   = 1
        };

        enum class GlyphSetId {
            GlyphSet1 = 1,
            GlyphSet2 = 2
        };


        /*--- Methods ---*/

        // Default constructor.
        SegMap595Class();

        /* "Load" a map string into an object, specify a display type (based on its common pin) and select a glyph set.
         *
         * Returns: zero if mapping was successful (that is, if the passed map string is valid and the bytes were
         * successfully mapped), a negative integer otherwise (see the preprocessor macros list for possible values).
         *
         * The third parameter can be omitted. In this case, glyph set #1 will be selected by default.
         *
         * Multiple calls to this method are valid, each call leads to a fresh byte mapping.
         */
        int32_t  init(const char *map_str,
                      DisplayType display_common_pin,
                      GlyphSetId glyph_set_id = GlyphSetId::GlyphSet1);

        /* Get the last mapping status.
         *
         * Returns: zero if mapping was successful, a negative integer otherwise
         * (see the preprocessor macros list for possible values).
         */
        int32_t  get_status();

        /* Get a mapped byte (overload #1).
         *
         * Returns: a mapped byte if mapping was successful and
         * the passed index is within the array bounds,
         * zero otherwise.
         */
        uint8_t  get_mapped_byte(size_t index);

        /* Get a mapped byte (overload #2).
         *
         * Returns: a mapped byte if mapping was successful and
         * the passed index is within the array bounds,
         * zero otherwise.
         */
        #if defined(UINT32_MAX) && defined(SIZE_MAX) && (UINT32_MAX > SIZE_MAX)
        uint8_t  get_mapped_byte(uint32_t index);
        #endif

        /* Get a mapped byte (overload #3).
         *
         * Returns: a mapped byte if mapping was successful and
         * the passed character is represented in the selected glyph set,
         * zero otherwise.
         *
         * Case-insensitive (lowercase letters will be converted to their uppercase counterparts).
         */
        uint8_t  get_mapped_byte(char represented_char);

        /* Get a mapped byte (overload #4).
         *
         * Returns: a mapped byte if mapping was successful and
         * the passed character is represented in the selected glyph set,
         * zero otherwise.
         *
         * Case-insensitive (lowercase letters will be converted to their uppercase counterparts).
         */
        uint8_t  get_mapped_byte(unsigned char represented_char);

        /* Get the position of the bit that represents a dot segment.
         *
         * Returns: an integer from zero to SEGMAP595_MSB (inclusive) if mapping was successful,
         * a negative integer otherwise.
         */
        int32_t  get_dot_bit_pos();

        /* Get the number of glyphs in the selected glyph set.
         *
         * Returns: a positive integer if mapping was successful,
         * zero otherwise.
         */
        size_t   get_glyph_num();

        /* Get the character represented by a glyph by its index (overload #1).
         *
         * Returns: the respective ASCII code if mapping was successful and
         * the passed index is within the array bounds,
         * zero otherwise.
         */
        char     get_represented_char(size_t index);

        /* Get the character represented by a glyph by its index (overload #2).
         *
         * Returns: the respective ASCII code if mapping was successful and
         * the passed index is within the array bounds,
         * zero otherwise.
         */
        #if defined(UINT32_MAX) && defined(SIZE_MAX) && (UINT32_MAX > SIZE_MAX)
        char     get_represented_char(uint32_t index);
        #endif

        /* Get a pointer to a string that represents a standard (since GCC 4.3 or C++14)
         * binary number notation for a given byte (overload #1).
         *
         * Returns: a pointer to a string.
         *
         * The string buffer is static, and therefore a pointer to it can be returned correctly.
         * Every call to this method rewrites the buffer contents.
         *
         * This method is a utility, not a part of per-instance (per-object) state,
         * therefore it may be used regardless of whether mapping was performed and
         * whether it was successful. However, that also means that the buffer is shared
         * by all class instances.
         *
         * If you need to preserve the buffer contents for further use, consider copying them
         * into an outer buffer at least 11 ("0b" prefix + 8 bits + the null terminator) bytes in size.
         */
        static const char* get_byte_bin_notation_as_str(char byte_to_write_down);

        /* Get a pointer to a string that represents a standard (since GCC 4.3 or C++14)
         * binary number notation for a given byte (overload #2).
         *
         * Returns: a pointer to a string.
         *
         * The string buffer is static, and therefore a pointer to it can be returned correctly.
         * Every call to this method rewrites the buffer contents.
         *
         * This method is a utility, not a part of per-instance (per-object) state,
         * therefore it may be used regardless of whether mapping was performed and
         * whether it was successful. However, that also means that the buffer is shared
         * by all class instances.
         *
         * If you need to preserve the buffer contents for further use, consider copying them
         * into an outer buffer at least 11 ("0b" prefix + 8 bits + the null terminator) bytes in size.
         */
        static const char* get_byte_bin_notation_as_str(unsigned char byte_to_write_down);

        /* Get a pointer to an object's internal buffer that holds the passed map string.
         *
         * Returns: a pointer to a string if mapping was successful,
         * nullptr otherwise (although the buffer always has a valid
         * address in memory, nullptr serves as an error indicator).
         */
        const char* get_map_str();

    private:
        /*--- Data types ---*/

        struct GlyphSet {
            const size_t        glyph_num;
            const uint8_t       abc_bytes[SEGMAP595_GLYPH_SET_MAX_GLYPH_NUM];
            const unsigned char chars[SEGMAP595_GLYPH_SET_MAX_GLYPH_NUM];
        };


        /*--- Variables ---*/

        // Glyph sets aggregate initialization.
        GlyphSet  _glyph_set_1 = {
                                  SEGMAP595_GLYPH_SET_1_GLYPH_NUM,
                                  {SEGMAP595_GLYPH_SET_1_ABC_BYTES},
                                  {SEGMAP595_GLYPH_SET_1_CHARS}
                                 };
        GlyphSet  _glyph_set_2 = {
                                  SEGMAP595_GLYPH_SET_2_GLYPH_NUM,
                                  {SEGMAP595_GLYPH_SET_2_ABC_BYTES},
                                  {SEGMAP595_GLYPH_SET_2_CHARS}
                                 };
        GlyphSet *_glyph_set_selected = nullptr;

        // Internal buffer that holds the passed map string.
        char     _map_str[SEGMAP595_SEG_NUM + 1] = {0};

        // Mapping status. See the preprocessor macros list for possible values.
        int32_t  _status = SEGMAP595_STATUS_INITIAL;

        // Display type (based on a display common pin).
        DisplayType _display_common_pin;

        /* Resulting array.
         * If mapping was successful, this array will hold the mapped bytes.
         */
        uint8_t  _mapped_bytes[SEGMAP595_GLYPH_SET_MAX_GLYPH_NUM] = {0};

        // Array of values that indicate a bit position number for every display segment.
        uint32_t _bit_pos[SEGMAP595_SEG_NUM] = {0xFFFFFFFF};  // Initial values are intentionally invalid.


        /*--- Methods ---*/

        /* Check the passed glyph set number and "load" the selected glyph set.
         *
         * Returns: zero if the passed glyph set number is valid, a negative integer otherwise
         * (see the preprocessor macros list for possible values).
         */
        int32_t select_glyph_set(GlyphSetId glyph_set_id);

        /* Check the passed map string validity and, if it's valid, copy its contents to the internal buffer.
         *
         * Returns: zero if the passed map string is valid, a negative integer otherwise
         * (see the preprocessor macros list for possible values).
         */
        int32_t check_map_str(const char *map_str);

        /* Indicate the bit position for every display segment.
         *
         * Returns: zero if all bit positions were indicated, a negative integer otherwise
         * (see the preprocessor macros list for possible values).
         *
         * The map string isn't passed because it's already copied
         * to the internal buffer by the moment this method is called.
         */
        int32_t read_map_str();

        /* Do the main job of mapping the bytes.
         *
         * Returns: nothing.
         */
        void    map_bytes(DisplayType display_common_pin);
};

// Class-related aliases.
constexpr SegMap595Class::DisplayType SegMap595CommonCathode = SegMap595Class::DisplayType::CommonCathode;
constexpr SegMap595Class::DisplayType SegMap595CommonAnode   = SegMap595Class::DisplayType::CommonAnode;
constexpr SegMap595Class::GlyphSetId  SegMap595GlyphSet1     = SegMap595Class::GlyphSetId::GlyphSet1;
constexpr SegMap595Class::GlyphSetId  SegMap595GlyphSet2     = SegMap595Class::GlyphSetId::GlyphSet2;


/*************** GLOBAL VARIABLES ***************/

/* An Arduino-style singleton object.
 * More instances of the same class can be created if necessary.
 */
extern SegMap595Class SegMap595;


#endif  // Include guards.
