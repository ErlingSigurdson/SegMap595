/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595Characters.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  Macros/constants related to characters to be mapped.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef SEGMAP595CHARACTERS_H
#define SEGMAP595CHARACTERS_H


/*--- Macros/constants related to characters to be mapped ---*/

/* Bytes formed as if the map string is "@ABCDEFG" (@ is for a dot).
 * In reality the map string is highly unlikely to be like that,
 * and alphabetically mapped bytes are just a set of default
 * combinations used in the actual mapping process.
 */
#define SEGMAP595_MAP_ALPHABETICAL_0          0b01111110
#define SEGMAP595_MAP_ALPHABETICAL_1          0b00110000
#define SEGMAP595_MAP_ALPHABETICAL_2          0b01101101
#define SEGMAP595_MAP_ALPHABETICAL_3          0b01111001
#define SEGMAP595_MAP_ALPHABETICAL_4          0b00110011
#define SEGMAP595_MAP_ALPHABETICAL_5          0b01011011
#define SEGMAP595_MAP_ALPHABETICAL_6          0b01011111
#define SEGMAP595_MAP_ALPHABETICAL_7          0b01110000
#define SEGMAP595_MAP_ALPHABETICAL_8          0b01111111
#define SEGMAP595_MAP_ALPHABETICAL_9          0b01111011
#define SEGMAP595_MAP_ALPHABETICAL_A          0b01110111
#define SEGMAP595_MAP_ALPHABETICAL_B          0b00011111
#define SEGMAP595_MAP_ALPHABETICAL_C          0b01001110
#define SEGMAP595_MAP_ALPHABETICAL_D          0b00111101
#define SEGMAP595_MAP_ALPHABETICAL_E          0b01001111
#define SEGMAP595_MAP_ALPHABETICAL_F          0b01000111
#define SEGMAP595_MAP_ALPHABETICAL_G          0b01011110
#define SEGMAP595_MAP_ALPHABETICAL_H          0b00110111
#define SEGMAP595_MAP_ALPHABETICAL_I          0b00110000
#define SEGMAP595_MAP_ALPHABETICAL_J          0b00111100
#define SEGMAP595_MAP_ALPHABETICAL_K          0b01010111  // Barely resembles actual 'K', but still usable.
#define SEGMAP595_MAP_ALPHABETICAL_L          0b00001110
#define SEGMAP595_MAP_ALPHABETICAL_N          0b00010101
#define SEGMAP595_MAP_ALPHABETICAL_O          0b00011101  // Stylized as lowercase to distinguish from zero.
#define SEGMAP595_MAP_ALPHABETICAL_P          0b01100111
#define SEGMAP595_MAP_ALPHABETICAL_Q          0b01110011
#define SEGMAP595_MAP_ALPHABETICAL_R          0b00000101
#define SEGMAP595_MAP_ALPHABETICAL_S          0b01011011
#define SEGMAP595_MAP_ALPHABETICAL_T          0b00001111
#define SEGMAP595_MAP_ALPHABETICAL_U          0b00111110
#define SEGMAP595_MAP_ALPHABETICAL_Y          0b00111011
#define SEGMAP595_MAP_ALPHABETICAL_Z          0b01101101
#define SEGMAP595_MAP_ALPHABETICAL_DASH       0b00000001
#define SEGMAP595_MAP_ALPHABETICAL_UNDERSCORE 0b00001000
#define SEGMAP595_MAP_ALPHABETICAL_ALL_CHARS  SEGMAP595_MAP_ALPHABETICAL_0,    \
                                              SEGMAP595_MAP_ALPHABETICAL_1,    \
                                              SEGMAP595_MAP_ALPHABETICAL_2,    \
                                              SEGMAP595_MAP_ALPHABETICAL_3,    \
                                              SEGMAP595_MAP_ALPHABETICAL_4,    \
                                              SEGMAP595_MAP_ALPHABETICAL_5,    \
                                              SEGMAP595_MAP_ALPHABETICAL_6,    \
                                              SEGMAP595_MAP_ALPHABETICAL_7,    \
                                              SEGMAP595_MAP_ALPHABETICAL_8,    \
                                              SEGMAP595_MAP_ALPHABETICAL_9,    \
                                              SEGMAP595_MAP_ALPHABETICAL_A,    \
                                              SEGMAP595_MAP_ALPHABETICAL_B,    \
                                              SEGMAP595_MAP_ALPHABETICAL_C,    \
                                              SEGMAP595_MAP_ALPHABETICAL_D,    \
                                              SEGMAP595_MAP_ALPHABETICAL_E,    \
                                              SEGMAP595_MAP_ALPHABETICAL_F,    \
                                              SEGMAP595_MAP_ALPHABETICAL_G,    \
                                              SEGMAP595_MAP_ALPHABETICAL_H,    \
                                              SEGMAP595_MAP_ALPHABETICAL_I,    \
                                              SEGMAP595_MAP_ALPHABETICAL_J,    \
                                              SEGMAP595_MAP_ALPHABETICAL_K,    \
                                              SEGMAP595_MAP_ALPHABETICAL_L,    \
                                              SEGMAP595_MAP_ALPHABETICAL_N,    \
                                              SEGMAP595_MAP_ALPHABETICAL_O,    \
                                              SEGMAP595_MAP_ALPHABETICAL_P,    \
                                              SEGMAP595_MAP_ALPHABETICAL_Q,    \
                                              SEGMAP595_MAP_ALPHABETICAL_R,    \
                                              SEGMAP595_MAP_ALPHABETICAL_S,    \
                                              SEGMAP595_MAP_ALPHABETICAL_T,    \
                                              SEGMAP595_MAP_ALPHABETICAL_U,    \
                                              SEGMAP595_MAP_ALPHABETICAL_Y,    \
                                              SEGMAP595_MAP_ALPHABETICAL_Z,    \
                                              SEGMAP595_MAP_ALPHABETICAL_DASH, \
                                              SEGMAP595_MAP_ALPHABETICAL_UNDERSCORE

/* Handy index aliases for referring to the mapped characters
 * within the resulting array.
 */
#define SEGMAP595_INDEX_0          0
#define SEGMAP595_INDEX_1          1
#define SEGMAP595_INDEX_2          2
#define SEGMAP595_INDEX_3          3
#define SEGMAP595_INDEX_4          4
#define SEGMAP595_INDEX_5          5
#define SEGMAP595_INDEX_6          6
#define SEGMAP595_INDEX_7          7
#define SEGMAP595_INDEX_8          8
#define SEGMAP595_INDEX_9          9
#define SEGMAP595_INDEX_A          10
#define SEGMAP595_INDEX_B          11
#define SEGMAP595_INDEX_C          12
#define SEGMAP595_INDEX_D          13
#define SEGMAP595_INDEX_E          14
#define SEGMAP595_INDEX_F          15
#define SEGMAP595_INDEX_G          16
#define SEGMAP595_INDEX_H          17
#define SEGMAP595_INDEX_I          18
#define SEGMAP595_INDEX_J          19
#define SEGMAP595_INDEX_K          20
#define SEGMAP595_INDEX_L          21
#define SEGMAP595_INDEX_N          22
#define SEGMAP595_INDEX_O          23
#define SEGMAP595_INDEX_P          24
#define SEGMAP595_INDEX_Q          25
#define SEGMAP595_INDEX_R          26
#define SEGMAP595_INDEX_S          27
#define SEGMAP595_INDEX_T          28
#define SEGMAP595_INDEX_U          29
#define SEGMAP595_INDEX_Y          30
#define SEGMAP595_INDEX_Z          31
#define SEGMAP595_INDEX_DASH       32
#define SEGMAP595_INDEX_UNDERSCORE 33

/* Digits can't be uppercase or lowercase, but they're
 * still listed twice to keep both lists the same length.
 */
#define SEGMAP595_CHAR_UPPERCASE_0          '0'
#define SEGMAP595_CHAR_UPPERCASE_1          '1'
#define SEGMAP595_CHAR_UPPERCASE_2          '2'
#define SEGMAP595_CHAR_UPPERCASE_3          '3'
#define SEGMAP595_CHAR_UPPERCASE_4          '4'
#define SEGMAP595_CHAR_UPPERCASE_5          '5'
#define SEGMAP595_CHAR_UPPERCASE_6          '6'
#define SEGMAP595_CHAR_UPPERCASE_7          '7'
#define SEGMAP595_CHAR_UPPERCASE_8          '8'
#define SEGMAP595_CHAR_UPPERCASE_9          '9'
#define SEGMAP595_CHAR_UPPERCASE_A          'A'
#define SEGMAP595_CHAR_UPPERCASE_B          'B'
#define SEGMAP595_CHAR_UPPERCASE_C          'C'
#define SEGMAP595_CHAR_UPPERCASE_D          'D'
#define SEGMAP595_CHAR_UPPERCASE_E          'E'
#define SEGMAP595_CHAR_UPPERCASE_F          'F'
#define SEGMAP595_CHAR_UPPERCASE_G          'G'
#define SEGMAP595_CHAR_UPPERCASE_H          'H'
#define SEGMAP595_CHAR_UPPERCASE_I          'I'
#define SEGMAP595_CHAR_UPPERCASE_J          'J'
#define SEGMAP595_CHAR_UPPERCASE_K          'K'
#define SEGMAP595_CHAR_UPPERCASE_L          'L'
#define SEGMAP595_CHAR_UPPERCASE_N          'N'
#define SEGMAP595_CHAR_UPPERCASE_O          'O'
#define SEGMAP595_CHAR_UPPERCASE_P          'P'
#define SEGMAP595_CHAR_UPPERCASE_Q          'Q'
#define SEGMAP595_CHAR_UPPERCASE_R          'R'
#define SEGMAP595_CHAR_UPPERCASE_S          'S'
#define SEGMAP595_CHAR_UPPERCASE_T          'T'
#define SEGMAP595_CHAR_UPPERCASE_U          'U'
#define SEGMAP595_CHAR_UPPERCASE_Y          'Y'
#define SEGMAP595_CHAR_UPPERCASE_Z          'Z'
#define SEGMAP595_CHAR_UPPERCASE_DASH       '-'
#define SEGMAP595_CHAR_UPPERCASE_UNDERSCORE '_'
#define SEGMAP595_CHAR_UPPERCASE_ALL SEGMAP595_CHAR_UPPERCASE_0,             \
                                     SEGMAP595_CHAR_UPPERCASE_1,             \
                                     SEGMAP595_CHAR_UPPERCASE_2,             \
                                     SEGMAP595_CHAR_UPPERCASE_3,             \
                                     SEGMAP595_CHAR_UPPERCASE_4,             \
                                     SEGMAP595_CHAR_UPPERCASE_5,             \
                                     SEGMAP595_CHAR_UPPERCASE_6,             \
                                     SEGMAP595_CHAR_UPPERCASE_7,             \
                                     SEGMAP595_CHAR_UPPERCASE_8,             \
                                     SEGMAP595_CHAR_UPPERCASE_9,             \
                                     SEGMAP595_CHAR_UPPERCASE_A,             \
                                     SEGMAP595_CHAR_UPPERCASE_B,             \
                                     SEGMAP595_CHAR_UPPERCASE_C,             \
                                     SEGMAP595_CHAR_UPPERCASE_D,             \
                                     SEGMAP595_CHAR_UPPERCASE_E,             \
                                     SEGMAP595_CHAR_UPPERCASE_F,             \
                                     SEGMAP595_CHAR_UPPERCASE_G,             \
                                     SEGMAP595_CHAR_UPPERCASE_H,             \
                                     SEGMAP595_CHAR_UPPERCASE_I,             \
                                     SEGMAP595_CHAR_UPPERCASE_J,             \
                                     SEGMAP595_CHAR_UPPERCASE_K,             \
                                     SEGMAP595_CHAR_UPPERCASE_L,             \
                                     SEGMAP595_CHAR_UPPERCASE_N,             \
                                     SEGMAP595_CHAR_UPPERCASE_O,             \
                                     SEGMAP595_CHAR_UPPERCASE_P,             \
                                     SEGMAP595_CHAR_UPPERCASE_Q,             \
                                     SEGMAP595_CHAR_UPPERCASE_R,             \
                                     SEGMAP595_CHAR_UPPERCASE_S,             \
                                     SEGMAP595_CHAR_UPPERCASE_T,             \
                                     SEGMAP595_CHAR_UPPERCASE_U,             \
                                     SEGMAP595_CHAR_UPPERCASE_Y,             \
                                     SEGMAP595_CHAR_UPPERCASE_Z,             \
                                     SEGMAP595_CHAR_UPPERCASE_DASH,      '-' \
                                     SEGMAP595_CHAR_UPPERCASE_UNDERSCORE '_'

#define SEGMAP595_CHAR_LOWERCASE_0          '0'
#define SEGMAP595_CHAR_LOWERCASE_1          '1'
#define SEGMAP595_CHAR_LOWERCASE_2          '2'
#define SEGMAP595_CHAR_LOWERCASE_3          '3'
#define SEGMAP595_CHAR_LOWERCASE_4          '4'
#define SEGMAP595_CHAR_LOWERCASE_5          '5'
#define SEGMAP595_CHAR_LOWERCASE_6          '6'
#define SEGMAP595_CHAR_LOWERCASE_7          '7'
#define SEGMAP595_CHAR_LOWERCASE_8          '8'
#define SEGMAP595_CHAR_LOWERCASE_9          '9'
#define SEGMAP595_CHAR_LOWERCASE_A          'A'
#define SEGMAP595_CHAR_LOWERCASE_B          'B'
#define SEGMAP595_CHAR_LOWERCASE_C          'C'
#define SEGMAP595_CHAR_LOWERCASE_D          'D'
#define SEGMAP595_CHAR_LOWERCASE_E          'E'
#define SEGMAP595_CHAR_LOWERCASE_F          'F'
#define SEGMAP595_CHAR_LOWERCASE_G          'G'
#define SEGMAP595_CHAR_LOWERCASE_H          'H'
#define SEGMAP595_CHAR_LOWERCASE_I          'I'
#define SEGMAP595_CHAR_LOWERCASE_J          'J'
#define SEGMAP595_CHAR_LOWERCASE_K          'K'
#define SEGMAP595_CHAR_LOWERCASE_L          'L'
#define SEGMAP595_CHAR_LOWERCASE_N          'N'
#define SEGMAP595_CHAR_LOWERCASE_O          'O'
#define SEGMAP595_CHAR_LOWERCASE_P          'P'
#define SEGMAP595_CHAR_LOWERCASE_Q          'Q'
#define SEGMAP595_CHAR_LOWERCASE_R          'R'
#define SEGMAP595_CHAR_LOWERCASE_S          'S'
#define SEGMAP595_CHAR_LOWERCASE_T          'T'
#define SEGMAP595_CHAR_LOWERCASE_U          'U'
#define SEGMAP595_CHAR_LOWERCASE_Y          'Y'
#define SEGMAP595_CHAR_LOWERCASE_Z          'Z'
#define SEGMAP595_CHAR_LOWERCASE_DASH       '-'
#define SEGMAP595_CHAR_LOWERCASE_UNDERSCORE '_'
#define SEGMAP595_CHAR_LOWERCASE_ALL SEGMAP595_CHAR_LOWERCASE_0,             \
                                     SEGMAP595_CHAR_LOWERCASE_1,             \
                                     SEGMAP595_CHAR_LOWERCASE_2,             \
                                     SEGMAP595_CHAR_LOWERCASE_3,             \
                                     SEGMAP595_CHAR_LOWERCASE_4,             \
                                     SEGMAP595_CHAR_LOWERCASE_5,             \
                                     SEGMAP595_CHAR_LOWERCASE_6,             \
                                     SEGMAP595_CHAR_LOWERCASE_7,             \
                                     SEGMAP595_CHAR_LOWERCASE_8,             \
                                     SEGMAP595_CHAR_LOWERCASE_9,             \
                                     SEGMAP595_CHAR_LOWERCASE_A,             \
                                     SEGMAP595_CHAR_LOWERCASE_B,             \
                                     SEGMAP595_CHAR_LOWERCASE_C,             \
                                     SEGMAP595_CHAR_LOWERCASE_D,             \
                                     SEGMAP595_CHAR_LOWERCASE_E,             \
                                     SEGMAP595_CHAR_LOWERCASE_F,             \
                                     SEGMAP595_CHAR_LOWERCASE_G,             \
                                     SEGMAP595_CHAR_LOWERCASE_H,             \
                                     SEGMAP595_CHAR_LOWERCASE_I,             \
                                     SEGMAP595_CHAR_LOWERCASE_J,             \
                                     SEGMAP595_CHAR_LOWERCASE_K,             \
                                     SEGMAP595_CHAR_LOWERCASE_L,             \
                                     SEGMAP595_CHAR_LOWERCASE_N,             \
                                     SEGMAP595_CHAR_LOWERCASE_O,             \
                                     SEGMAP595_CHAR_LOWERCASE_P,             \
                                     SEGMAP595_CHAR_LOWERCASE_Q,             \
                                     SEGMAP595_CHAR_LOWERCASE_R,             \
                                     SEGMAP595_CHAR_LOWERCASE_S,             \
                                     SEGMAP595_CHAR_LOWERCASE_T,             \
                                     SEGMAP595_CHAR_LOWERCASE_U,             \
                                     SEGMAP595_CHAR_LOWERCASE_Y,             \
                                     SEGMAP595_CHAR_LOWERCASE_Z,             \
                                     SEGMAP595_CHAR_LOWERCASE_DASH,      '-' \
                                     SEGMAP595_CHAR_LOWERCASE_UNDERSCORE '_'


#endif  // Include guards.
