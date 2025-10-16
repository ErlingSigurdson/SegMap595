/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595_glyph_set_2.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  Specific macros/constants related to glyphs and mapping.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:    Some resulting glyphs resemble their actual prototype characters,
 *           some are rather sketchy.
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595_GLYPH_SET_2_H
#define SEGMAP595_GLYPH_SET_2_H


/*--- Specific macros/constants related to mapping and glyphs ---*/

#define SEGMAP595_GLYPH_SET_2_CHAR_NUM 35

/* Bytes formed as if the map string is "@ABCDEFG" (@ is for a dot).
 * In reality the map string is unlikely to be like that,
 * and alphabetically mapped bytes are just a set of default
 * combinations used in a mapping process.
 */
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_0 0b01111110
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_1 0b00110000
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_2 0b01101101
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_3 0b01111001
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_4 0b00110011
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_5 0b01011011
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_6 0b01011111
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_7 0b01110000
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_8 0b01111111
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_9 0b01111011
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_A 0b01110111  // Like actual 'A'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_B 0b00011111  // Like actual 'b'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_C 0b01001110  // Like actual 'C'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_D 0b00111101  // Like actual 'd'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_E 0b01001111  // Like actual 'E'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_F 0b01000111  // Like actual 'F'.

#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_G 0b01011110  /* More or less like actual 'G',
                                                                   * but without the short horizontal stroke.
                                                                   */

#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_H 0b00110111  // Like actual 'H'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_I 0b00110000  // Like actual 'I', equivalent to '1'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_J 0b00111100  // Like actual 'J'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_L 0b00001110  // Like actual 'L'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_N 0b00010101  // Like actual 'n'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_O 0b00011101  // Like actual 'o' (to distinguish from zero).
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_P 0b01100111  // Like actual 'P'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_Q 0b01110011  // Like actual 'q'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_R 0b00000101  // Like actual 'r'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_S 0b01011011  // Like actual 'S', equivalent to '5'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_T 0b00001111  // More or less like actual 't'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_U 0b00111110  // Like actual 'U'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_Y 0b00111011  // Like actual 'y', but size of a capital letter.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_Z 0b01101101  // More or less like actual 'Z', equivalent to '2'.
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_DASH       0b00000001
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_EQUAL      0b00001001
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_DEGREE     0b01100011
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_UNDERSCORE 0b00001000
#define SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_ALL SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_0, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_1, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_2, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_3, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_4, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_5, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_6, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_7, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_8, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_9, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_A, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_B, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_C, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_D, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_E, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_F, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_G, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_H, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_I, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_J, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_L, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_N, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_O, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_P, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_Q, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_R, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_S, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_T, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_U, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_Y, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_Z, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_DASH,   \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_EQUAL,  \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_DEGREE, \
                                                        SEGMAP595_GLYPH_SET_2_MAPPED_ALPHABETICALLY_UNDERSCORE

/* Handy index aliases for referring to the mapped bytes
 * within the resulting array.
 */
#define SEGMAP595_GLYPH_SET_2_INDEX_0          0
#define SEGMAP595_GLYPH_SET_2_INDEX_1          1
#define SEGMAP595_GLYPH_SET_2_INDEX_2          2
#define SEGMAP595_GLYPH_SET_2_INDEX_3          3
#define SEGMAP595_GLYPH_SET_2_INDEX_4          4
#define SEGMAP595_GLYPH_SET_2_INDEX_5          5
#define SEGMAP595_GLYPH_SET_2_INDEX_6          6
#define SEGMAP595_GLYPH_SET_2_INDEX_7          7
#define SEGMAP595_GLYPH_SET_2_INDEX_8          8
#define SEGMAP595_GLYPH_SET_2_INDEX_9          9
#define SEGMAP595_GLYPH_SET_2_INDEX_A          10
#define SEGMAP595_GLYPH_SET_2_INDEX_B          11
#define SEGMAP595_GLYPH_SET_2_INDEX_C          12
#define SEGMAP595_GLYPH_SET_2_INDEX_D          13
#define SEGMAP595_GLYPH_SET_2_INDEX_E          14
#define SEGMAP595_GLYPH_SET_2_INDEX_F          15
#define SEGMAP595_GLYPH_SET_2_INDEX_G          16
#define SEGMAP595_GLYPH_SET_2_INDEX_H          17
#define SEGMAP595_GLYPH_SET_2_INDEX_I          18
#define SEGMAP595_GLYPH_SET_2_INDEX_J          19
#define SEGMAP595_GLYPH_SET_2_INDEX_L          20
#define SEGMAP595_GLYPH_SET_2_INDEX_N          21
#define SEGMAP595_GLYPH_SET_2_INDEX_O          22
#define SEGMAP595_GLYPH_SET_2_INDEX_P          23
#define SEGMAP595_GLYPH_SET_2_INDEX_Q          24
#define SEGMAP595_GLYPH_SET_2_INDEX_R          25
#define SEGMAP595_GLYPH_SET_2_INDEX_S          26
#define SEGMAP595_GLYPH_SET_2_INDEX_T          27
#define SEGMAP595_GLYPH_SET_2_INDEX_U          28
#define SEGMAP595_GLYPH_SET_2_INDEX_Y          29
#define SEGMAP595_GLYPH_SET_2_INDEX_Z          30
#define SEGMAP595_GLYPH_SET_2_INDEX_DASH       31
#define SEGMAP595_GLYPH_SET_2_INDEX_EQUAL      32
#define SEGMAP595_GLYPH_SET_2_INDEX_DEGREE     33
#define SEGMAP595_GLYPH_SET_2_INDEX_UNDERSCORE 34

// Contents of an array used to get mapped bytes by the characters they represent.
#define SEGMAP595_GLYPH_SET_2_CHAR_0          '0'
#define SEGMAP595_GLYPH_SET_2_CHAR_1          '1'
#define SEGMAP595_GLYPH_SET_2_CHAR_2          '2'
#define SEGMAP595_GLYPH_SET_2_CHAR_3          '3'
#define SEGMAP595_GLYPH_SET_2_CHAR_4          '4'
#define SEGMAP595_GLYPH_SET_2_CHAR_5          '5'
#define SEGMAP595_GLYPH_SET_2_CHAR_6          '6'
#define SEGMAP595_GLYPH_SET_2_CHAR_7          '7'
#define SEGMAP595_GLYPH_SET_2_CHAR_8          '8'
#define SEGMAP595_GLYPH_SET_2_CHAR_9          '9'
#define SEGMAP595_GLYPH_SET_2_CHAR_A          'A'
#define SEGMAP595_GLYPH_SET_2_CHAR_B          'B'
#define SEGMAP595_GLYPH_SET_2_CHAR_C          'C'
#define SEGMAP595_GLYPH_SET_2_CHAR_D          'D'
#define SEGMAP595_GLYPH_SET_2_CHAR_E          'E'
#define SEGMAP595_GLYPH_SET_2_CHAR_F          'F'
#define SEGMAP595_GLYPH_SET_2_CHAR_G          'G'
#define SEGMAP595_GLYPH_SET_2_CHAR_H          'H'
#define SEGMAP595_GLYPH_SET_2_CHAR_I          'I'
#define SEGMAP595_GLYPH_SET_2_CHAR_J          'J'
#define SEGMAP595_GLYPH_SET_2_CHAR_L          'L'
#define SEGMAP595_GLYPH_SET_2_CHAR_N          'N'
#define SEGMAP595_GLYPH_SET_2_CHAR_O          'O'
#define SEGMAP595_GLYPH_SET_2_CHAR_P          'P'
#define SEGMAP595_GLYPH_SET_2_CHAR_Q          'Q'
#define SEGMAP595_GLYPH_SET_2_CHAR_R          'R'
#define SEGMAP595_GLYPH_SET_2_CHAR_S          'S'
#define SEGMAP595_GLYPH_SET_2_CHAR_T          'T'
#define SEGMAP595_GLYPH_SET_2_CHAR_U          'U'
#define SEGMAP595_GLYPH_SET_2_CHAR_Y          'Y'
#define SEGMAP595_GLYPH_SET_2_CHAR_Z          'Z'
#define SEGMAP595_GLYPH_SET_2_CHAR_DASH       '-'
#define SEGMAP595_GLYPH_SET_2_CHAR_EQUAL      '='
#define SEGMAP595_GLYPH_SET_2_CHAR_DEGREE     '*'  // Special case: there's no ASCII character for degree symbol.
#define SEGMAP595_GLYPH_SET_2_CHAR_UNDERSCORE '_'
#define SEGMAP595_GLYPH_SET_2_CHAR_ALL SEGMAP595_GLYPH_SET_2_CHAR_0,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_1,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_2,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_3,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_4,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_5,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_6,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_7,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_8,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_9,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_A,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_B,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_C,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_D,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_E,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_F,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_G,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_H,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_I,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_J,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_L,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_N,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_O,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_P,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_Q,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_R,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_S,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_T,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_U,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_Y,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_Z,      \
                                       SEGMAP595_GLYPH_SET_2_CHAR_DASH,   \
                                       SEGMAP595_GLYPH_SET_2_CHAR_EQUAL,  \
                                       SEGMAP595_GLYPH_SET_2_CHAR_DEGREE, \
                                       SEGMAP595_GLYPH_SET_2_CHAR_UNDERSCORE


#endif  // Include guards.
