/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A class for mapping the outputs of a 74HC595 IC
 *           to the segments of a 7-segment display.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:    The init method takes a single argument - a map string, that is,
 *           a C-style (null-terminated) string that must reflect the order
 *           of connections made between parallel outputs of a 74HC595
 *           and segment control pins of a 7-segment display.
 *
 *           The map string must consist of exactly 8 characters: @, A, B, C, D,
 *           E, F and G. Every character corresponds to a single segment
 *           (@ stands for a dot). The first (leftmost) character in the
 *           map string corresponds to the 7th bit of the IC's parallel output
 *           (Q7 output), the second character corresponds to the 6th bit
 *           (Q6 output), etc.
 *
 *           Uppercase characters may be substituted for their lowercase
 *           counterparts. Any other characters are invalid. Duplicating
 *           characters in the map string is invalid.
 *
 *           If the map string is valid, mapped characters (custom formed bytes
 *           which correspond to symbols to be output on a 7-segment display)
 *           will be placed to a member array in the ascending order
 *           (from 0 to 9, from A to Z, but symbols that cannot be displayed
 *           properly on a 7-segment display are not represented). Resulting
 *           mapped characters are accessed via get_mapped_character() method.
 *
 *           The dot bit will be in "off" state in all mapped character
 *           bytes, therefore you will have to manipulate this bit in your
 *           implementation if necessary (get_dot_bit_pos() method can be
 *           helpful).
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595_H
#define SEGMAP595_H


/*--- Includes ---*/

// Relevant standard libraries.
#include <cstdint>


/*--- Misc ---*/

#define SEGMAP595_SEG_NUM           8     // Including a dot segment.
#define SEGMAP595_CHAR_NUM          32

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

/* Bytes formed as if the map string is "@ABCDEFG" (@ is for dot).
 * In reality the map string is highly unlikely to be like that,
 * and alphabetically mapped bytes are just a set of default
 * combinations used in the actual mapping process.
 */
#define SEGMAP595_MAP_ALPHABETICAL_0 0b01111110
#define SEGMAP595_MAP_ALPHABETICAL_1 0b00110000
#define SEGMAP595_MAP_ALPHABETICAL_2 0b01101101
#define SEGMAP595_MAP_ALPHABETICAL_3 0b01111001
#define SEGMAP595_MAP_ALPHABETICAL_4 0b00110011
#define SEGMAP595_MAP_ALPHABETICAL_5 0b01011011
#define SEGMAP595_MAP_ALPHABETICAL_6 0b01011111
#define SEGMAP595_MAP_ALPHABETICAL_7 0b01110000
#define SEGMAP595_MAP_ALPHABETICAL_8 0b01111111
#define SEGMAP595_MAP_ALPHABETICAL_9 0b01111011
#define SEGMAP595_MAP_ALPHABETICAL_A 0b01110111
#define SEGMAP595_MAP_ALPHABETICAL_B 0b00011111
#define SEGMAP595_MAP_ALPHABETICAL_C 0b01001110
#define SEGMAP595_MAP_ALPHABETICAL_D 0b00111101
#define SEGMAP595_MAP_ALPHABETICAL_E 0b01001111
#define SEGMAP595_MAP_ALPHABETICAL_F 0b01000111
#define SEGMAP595_MAP_ALPHABETICAL_G 0b01011110
#define SEGMAP595_MAP_ALPHABETICAL_H 0b00110111
#define SEGMAP595_MAP_ALPHABETICAL_I 0b00110000
#define SEGMAP595_MAP_ALPHABETICAL_J 0b00111100
#define SEGMAP595_MAP_ALPHABETICAL_K 0b01010111  // Barely resembles actual 'K', but still usable.
#define SEGMAP595_MAP_ALPHABETICAL_L 0b00001110
#define SEGMAP595_MAP_ALPHABETICAL_N 0b00010101
#define SEGMAP595_MAP_ALPHABETICAL_O 0b00011101  // Stylized as lowercase to distinguish from zero.
#define SEGMAP595_MAP_ALPHABETICAL_P 0b01100111
#define SEGMAP595_MAP_ALPHABETICAL_Q 0b01110011
#define SEGMAP595_MAP_ALPHABETICAL_R 0b00000101
#define SEGMAP595_MAP_ALPHABETICAL_S 0b01011011
#define SEGMAP595_MAP_ALPHABETICAL_T 0b00001111
#define SEGMAP595_MAP_ALPHABETICAL_U 0b00111110
#define SEGMAP595_MAP_ALPHABETICAL_Y 0b00111011
#define SEGMAP595_MAP_ALPHABETICAL_Z 0b01101101
#define SEGMAP595_MAP_ALPHABETICAL_ALL_CHARS SEGMAP595_MAP_ALPHABETICAL_0, \
                                             SEGMAP595_MAP_ALPHABETICAL_1, \
                                             SEGMAP595_MAP_ALPHABETICAL_2, \
                                             SEGMAP595_MAP_ALPHABETICAL_3, \
                                             SEGMAP595_MAP_ALPHABETICAL_4, \
                                             SEGMAP595_MAP_ALPHABETICAL_5, \
                                             SEGMAP595_MAP_ALPHABETICAL_6, \
                                             SEGMAP595_MAP_ALPHABETICAL_7, \
                                             SEGMAP595_MAP_ALPHABETICAL_8, \
                                             SEGMAP595_MAP_ALPHABETICAL_9, \
                                             SEGMAP595_MAP_ALPHABETICAL_A, \
                                             SEGMAP595_MAP_ALPHABETICAL_B, \
                                             SEGMAP595_MAP_ALPHABETICAL_C, \
                                             SEGMAP595_MAP_ALPHABETICAL_D, \
                                             SEGMAP595_MAP_ALPHABETICAL_E, \
                                             SEGMAP595_MAP_ALPHABETICAL_F, \
                                             SEGMAP595_MAP_ALPHABETICAL_G, \
                                             SEGMAP595_MAP_ALPHABETICAL_H, \
                                             SEGMAP595_MAP_ALPHABETICAL_I, \
                                             SEGMAP595_MAP_ALPHABETICAL_J, \
                                             SEGMAP595_MAP_ALPHABETICAL_K, \
                                             SEGMAP595_MAP_ALPHABETICAL_L, \
                                             SEGMAP595_MAP_ALPHABETICAL_N, \
                                             SEGMAP595_MAP_ALPHABETICAL_O, \
                                             SEGMAP595_MAP_ALPHABETICAL_P, \
                                             SEGMAP595_MAP_ALPHABETICAL_Q, \
                                             SEGMAP595_MAP_ALPHABETICAL_R, \
                                             SEGMAP595_MAP_ALPHABETICAL_S, \
                                             SEGMAP595_MAP_ALPHABETICAL_T, \
                                             SEGMAP595_MAP_ALPHABETICAL_U, \
                                             SEGMAP595_MAP_ALPHABETICAL_Y, \
                                             SEGMAP595_MAP_ALPHABETICAL_Z

/* Handy index aliases for referring to the mapped
 * characters within the resulting array.
 */
#define SEGMAP595_CHAR_0 0
#define SEGMAP595_CHAR_1 1
#define SEGMAP595_CHAR_2 2
#define SEGMAP595_CHAR_3 3
#define SEGMAP595_CHAR_4 4
#define SEGMAP595_CHAR_5 5
#define SEGMAP595_CHAR_6 6
#define SEGMAP595_CHAR_7 7
#define SEGMAP595_CHAR_8 8
#define SEGMAP595_CHAR_9 9
#define SEGMAP595_CHAR_A 10
#define SEGMAP595_CHAR_B 11
#define SEGMAP595_CHAR_C 12
#define SEGMAP595_CHAR_D 13
#define SEGMAP595_CHAR_E 14
#define SEGMAP595_CHAR_F 15
#define SEGMAP595_CHAR_G 16
#define SEGMAP595_CHAR_H 17
#define SEGMAP595_CHAR_I 18
#define SEGMAP595_CHAR_J 19
#define SEGMAP595_CHAR_K 20
#define SEGMAP595_CHAR_L 21
#define SEGMAP595_CHAR_N 22
#define SEGMAP595_CHAR_O 23
#define SEGMAP595_CHAR_P 24
#define SEGMAP595_CHAR_Q 25
#define SEGMAP595_CHAR_R 26
#define SEGMAP595_CHAR_S 27
#define SEGMAP595_CHAR_T 28
#define SEGMAP595_CHAR_U 29
#define SEGMAP595_CHAR_Y 30
#define SEGMAP595_CHAR_Z 31


/****************** DATA TYPES ******************/

class SegMap595Class {
    public:
        /*--- Methods ---*/

        // Default constructor.
        SegMap595Class();

        /* "Load" a map string into an object.
         * Returns: 0 if the passed map string is valid and the characters are successfully mapped,
         * negative integer otherwise (see preprocessor macros list for possible values).
         *
         * If the second parameter evaluates to false, common cathode display is assumed.
         * Otherwise common anode display is assumed.
         *
         * Multiple calls for this method are valid, each call will lead to a fresh character mapping.
         */
        int32_t  init(const char *map_str, bool display_common_pin);

        /* Get the mapping status (whether the passed map string was valid and the characters were successfully mapped).
         * Returns: 0 if the passed map string was valid and the characters were successfully mapped,
         * negative integer otherwise (see preprocessor macros list for possible values).
         */
        int32_t  get_status();

        /* Get a mapped character.
         * Returns: a mapped character (custom formed byte) if the passed map string was valid,
         * the characters were successfully mapped and the passed index is within the array bounds,
         * zero otherwise.
         */
        uint8_t  get_mapped_character(uint32_t index);

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
        static constexpr uint8_t _mapped_alphabetical[SEGMAP595_CHAR_NUM] = {SEGMAP595_MAP_ALPHABETICAL_ALL_CHARS};

        // Internal buffer.
        char     _map_str[SEGMAP595_SEG_NUM + 1] = {0};

        // Mapping status. See preprocessor macros list for possible values.
        int32_t  _status = SEGMAP595_STATUS_INIT;

        /* Resulting array.
         * If the passed map string was valid and the characters were successfully mapped,
         * this array will hold the mapped characters (custom formed bytes).
         */
        uint8_t  _mapped_characters[SEGMAP595_CHAR_NUM] = {0};

        // Array of values that indicate the respective bit position number for every display segment.
        uint32_t _bit_pos[SEGMAP595_SEG_NUM] = {0};


        /*--- Methods ---*/

        /* Check the passed map string validity and, if it's valid, copy its contents to the internal buffer.
         * Returns: 0 if the passed map string is valid, negative integer otherwise (see preprocessor macros
         * list for possible values).
         */
        int32_t check_map_str(const char *map_str);

        /* Indicate bit positions for every display segment.
         * Returns: 0 if all bit positions are indicated, negative integer otherwise
         * (see preprocessor macros list for possible values).
         *
         * The map string isn't passed because it's already copied
         * to the internal buffer by the moment of this method call. 
         */
        int32_t read_map_str();

        /* Do the main job of mapping the characters.
         * Returns: nothing.
         */
        void    map_characters(bool display_common_pin);
};


/*************** GLOBAL VARIABLES ***************/

/* An Arduino-style singleton object.
 * More instances of the same class can be created if necessary.
 */
extern SegMap595Class SegMap595;


#endif  // Include guards.
