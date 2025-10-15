/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595GlyphSet1.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  Macros/constants related to characters to be mapped.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:    Some resulting glyphs resemble their actual prototype characters,
 *           some are rather sketchy, others are outright arbitrary.
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595_GLYPH_SET_1_H
#define SEGMAP595_GLYPH_SET_1_H


/*--- Macros/constants related to characters to be mapped ---*/

#define SEGMAP595_GLYPH_SET_1_CHAR_NUM 40

/* Bytes formed as if the map string is "@ABCDEFG" (@ is for a dot).
 * In reality the map string is highly unlikely to be like that,
 * and alphabetically mapped bytes are just a set of default
 * combinations used in the actual mapping process.
 */
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_0          0b01111110
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_1          0b00110000
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_2          0b01101101
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_3          0b01111001
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_4          0b00110011
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_5          0b01011011
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_6          0b01011111
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_7          0b01110000
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_8          0b01111111
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_9          0b01111011
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_A          0b01110111  // Like actual 'A'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_B          0b00011111  // Like actual 'b'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_C          0b01001110  // Like actual 'C'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_D          0b00111101  // Like actual 'd'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_E          0b01001111  // Like actual 'E'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_F          0b01000111  // Like actual 'F'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_G          0b01011110  /* Like actual 'G', but without
                                                                       * the short horizontal stroke.
                                                                       */
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_H          0b00010111  // Like actual 'h'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_I          0b00010000  // Short vertical stroke, not equivalent to '1'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_J          0b00111100  // More or less like actual 'J'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_K          0b01010111  // Barely resembles actual 'K'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_L          0b00001110  // Like actual 'L'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_M          0b01010101  // Like actual 'n' with a dash over it.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_N          0b00010101  // Like actual 'n'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_O          0b00011101  // Like actual 'o' (to distinguish from zero).
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_P          0b01100111  // Like actual 'P'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_Q          0b01110011  // More or less like actual 'q'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_R          0b00000101  // Like actual 'r'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_S          0b01011011  /* More or less like actual 'S',
                                                                       * equivalent to '5'.
                                                                       */
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_T          0b00001111  // More or less like actual 't'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_U          0b00111110  // Like actual 'U'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_V          0b00011100  /* Like actual 'u', because keeping it like this
                                                                       * gives up space for 'U' byte that looks like
                                                                       * actual 'U'.
                                                                       */
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_W          0b00101011  // Like elevated actual 'u' with a dash under it.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_X          0b00110111  /* Like actual 'H', because keeping it like this
                                                                       * gives up space for 'H' byte that looks like
                                                                       * actual 'h'.
                                                                       */
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_Y          0b00111011  // More or less like Cyrillic 'У'.
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_Z          0b01101101  /* More or less like actual 'Z',
                                                                       * equivalent to '2'.
                                                                       */
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_DASH       0b00000001
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_EQUAL      0b00001001
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_DEGREE     0b01100011
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_UNDERSCORE 0b00001000
#define SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_ALL SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_0,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_1,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_2,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_3,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_4,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_5,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_6,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_7,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_8,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_9,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_A,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_B,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_C,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_D,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_E,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_F,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_G,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_H,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_I,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_J,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_K,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_L,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_M,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_N,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_O,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_P,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_Q,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_R,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_S,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_T,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_U,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_V,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_W,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_X,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_Y,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_Z,      \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_DASH,   \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_EQUAL,  \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_DEGREE, \
                                                   SEGMAP595_GLYPH_SET_1_MAP_ALPHABETICAL_UNDERSCORE

/* Handy index aliases for referring to the mapped characters
 * within the resulting array.
 */
#define SEGMAP595_GLYPH_SET_1_INDEX_0          0
#define SEGMAP595_GLYPH_SET_1_INDEX_1          1
#define SEGMAP595_GLYPH_SET_1_INDEX_2          2
#define SEGMAP595_GLYPH_SET_1_INDEX_3          3
#define SEGMAP595_GLYPH_SET_1_INDEX_4          4
#define SEGMAP595_GLYPH_SET_1_INDEX_5          5
#define SEGMAP595_GLYPH_SET_1_INDEX_6          6
#define SEGMAP595_GLYPH_SET_1_INDEX_7          7
#define SEGMAP595_GLYPH_SET_1_INDEX_8          8
#define SEGMAP595_GLYPH_SET_1_INDEX_9          9
#define SEGMAP595_GLYPH_SET_1_INDEX_A          10
#define SEGMAP595_GLYPH_SET_1_INDEX_B          11
#define SEGMAP595_GLYPH_SET_1_INDEX_C          12
#define SEGMAP595_GLYPH_SET_1_INDEX_D          13
#define SEGMAP595_GLYPH_SET_1_INDEX_E          14
#define SEGMAP595_GLYPH_SET_1_INDEX_F          15
#define SEGMAP595_GLYPH_SET_1_INDEX_G          16
#define SEGMAP595_GLYPH_SET_1_INDEX_H          17
#define SEGMAP595_GLYPH_SET_1_INDEX_I          18
#define SEGMAP595_GLYPH_SET_1_INDEX_J          19
#define SEGMAP595_GLYPH_SET_1_INDEX_K          20
#define SEGMAP595_GLYPH_SET_1_INDEX_L          21
#define SEGMAP595_GLYPH_SET_1_INDEX_M          22
#define SEGMAP595_GLYPH_SET_1_INDEX_N          23
#define SEGMAP595_GLYPH_SET_1_INDEX_O          24
#define SEGMAP595_GLYPH_SET_1_INDEX_P          25
#define SEGMAP595_GLYPH_SET_1_INDEX_Q          26
#define SEGMAP595_GLYPH_SET_1_INDEX_R          27
#define SEGMAP595_GLYPH_SET_1_INDEX_S          28
#define SEGMAP595_GLYPH_SET_1_INDEX_T          29
#define SEGMAP595_GLYPH_SET_1_INDEX_U          30
#define SEGMAP595_GLYPH_SET_1_INDEX_V          31
#define SEGMAP595_GLYPH_SET_1_INDEX_W          32
#define SEGMAP595_GLYPH_SET_1_INDEX_X          33
#define SEGMAP595_GLYPH_SET_1_INDEX_Y          34
#define SEGMAP595_GLYPH_SET_1_INDEX_Z          35
#define SEGMAP595_GLYPH_SET_1_INDEX_DASH       36
#define SEGMAP595_GLYPH_SET_1_INDEX_EQUAL      37
#define SEGMAP595_GLYPH_SET_1_INDEX_DEGREE     38
#define SEGMAP595_GLYPH_SET_1_INDEX_UNDERSCORE 39

// Contents of an array used to get mapped characters by their corresponding ASCII values.
#define SEGMAP595_GLYPH_SET_1_CHAR_0          '0'
#define SEGMAP595_GLYPH_SET_1_CHAR_1          '1'
#define SEGMAP595_GLYPH_SET_1_CHAR_2          '2'
#define SEGMAP595_GLYPH_SET_1_CHAR_3          '3'
#define SEGMAP595_GLYPH_SET_1_CHAR_4          '4'
#define SEGMAP595_GLYPH_SET_1_CHAR_5          '5'
#define SEGMAP595_GLYPH_SET_1_CHAR_6          '6'
#define SEGMAP595_GLYPH_SET_1_CHAR_7          '7'
#define SEGMAP595_GLYPH_SET_1_CHAR_8          '8'
#define SEGMAP595_GLYPH_SET_1_CHAR_9          '9'
#define SEGMAP595_GLYPH_SET_1_CHAR_A          'A'
#define SEGMAP595_GLYPH_SET_1_CHAR_B          'B'
#define SEGMAP595_GLYPH_SET_1_CHAR_C          'C'
#define SEGMAP595_GLYPH_SET_1_CHAR_D          'D'
#define SEGMAP595_GLYPH_SET_1_CHAR_E          'E'
#define SEGMAP595_GLYPH_SET_1_CHAR_F          'F'
#define SEGMAP595_GLYPH_SET_1_CHAR_G          'G'
#define SEGMAP595_GLYPH_SET_1_CHAR_H          'H'
#define SEGMAP595_GLYPH_SET_1_CHAR_I          'I'
#define SEGMAP595_GLYPH_SET_1_CHAR_J          'J'
#define SEGMAP595_GLYPH_SET_1_CHAR_K          'K'
#define SEGMAP595_GLYPH_SET_1_CHAR_L          'L'
#define SEGMAP595_GLYPH_SET_1_CHAR_M          'M'.
#define SEGMAP595_GLYPH_SET_1_CHAR_N          'N'
#define SEGMAP595_GLYPH_SET_1_CHAR_O          'O'
#define SEGMAP595_GLYPH_SET_1_CHAR_P          'P'
#define SEGMAP595_GLYPH_SET_1_CHAR_Q          'Q'
#define SEGMAP595_GLYPH_SET_1_CHAR_R          'R'
#define SEGMAP595_GLYPH_SET_1_CHAR_S          'S'
#define SEGMAP595_GLYPH_SET_1_CHAR_T          'T'
#define SEGMAP595_GLYPH_SET_1_CHAR_U          'U'
#define SEGMAP595_GLYPH_SET_1_CHAR_V          'V'
#define SEGMAP595_GLYPH_SET_1_CHAR_W          'W'
#define SEGMAP595_GLYPH_SET_1_CHAR_X          'X'
#define SEGMAP595_GLYPH_SET_1_CHAR_Y          'Y'
#define SEGMAP595_GLYPH_SET_1_CHAR_Z          'Z'
#define SEGMAP595_GLYPH_SET_1_CHAR_DASH       '-'
#define SEGMAP595_GLYPH_SET_1_CHAR_EQUAL      '='
#define SEGMAP595_GLYPH_SET_1_CHAR_DEGREE     '*'
#define SEGMAP595_GLYPH_SET_1_CHAR_UNDERSCORE '_'
#define SEGMAP595_GLYPH_SET_1_CHAR_ALL SEGMAP595_GLYPH_SET_1_CHAR_0,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_1,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_2,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_3,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_4,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_5,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_6,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_7,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_8,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_9,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_A,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_B,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_C,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_D,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_E,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_F,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_G,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_H,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_I,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_J,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_K,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_L,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_M,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_N,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_O,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_P,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_Q,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_R,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_S,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_T,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_U,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_V,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_W,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_X,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_Y,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_Z,      \
                                       SEGMAP595_GLYPH_SET_1_CHAR_DASH,   \
                                       SEGMAP595_GLYPH_SET_1_CHAR_EQUAL,  \
                                       SEGMAP595_GLYPH_SET_1_CHAR_DEGREE, \
                                       SEGMAP595_GLYPH_SET_1_CHAR_UNDERSCORE


#endif  // Include guards.
