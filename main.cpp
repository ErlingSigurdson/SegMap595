/****************** DESCRIPTION *****************/

/**
 * Filename: main.cpp
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  A test sequence for
             the class for mapping a 74HC595 IC's outputs and
             a 7-segment display's segments.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

#include <cstdio>
#include "SegMap595.h"


/*--- Misc ---*/

#define TEST_SEGMAP595_MAP_STR "ABCDEFG@"


/******************* FUNCTIONS ******************/

int main()
{
    SegMap.init(TEST_SEGMAP595_MAP_STR);
    printf("%d\n", SegMap.status);

    // Expected result is 254.
    printf("%d\n", SegMap.mapped_characters[SEGMAP595_CHAR_8]);

    return 0;
}