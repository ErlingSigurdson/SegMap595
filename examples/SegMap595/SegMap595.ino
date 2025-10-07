/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.ino
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  Example sketch demonstrating basic use of SegMap595 library.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

#include <SegMap595.h>


/*--- Misc ---*/

#define SERIAL_BAUD_RATE    115200

#define DATA_PIN  6
#define LATCH_PIN 7
#define CLOCK_PIN 8

#define SEGMAP595_MAP_STR   "ED@CGAFB"  // Valid example of a map string.
//#define SEGMAP595_MAP_STR "ed@cgafb"  // Also valid.
//#define SEGMAP595_MAP_STR "Ed@cGaFb"  // Still valid.
//#define SEGMAP595_MAP_STR "E@CGAFB"   // Invalid: map string is too short.
//#define SEGMAP595_MAP_STR "E@CGAFBM"  // Invalid: illegal character 'M'.
//#define SEGMAP595_MAP_STR "E@CGAFBE"  // Invalid: duplicated character 'E'.


/******************* FUNCTIONS ******************/

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    // Character mapping.
    int32_t init_retval = SegMap595.init(SEGMAP595_MAP_STR, SEGMAP595_COMMON_CATHODE);
    if (init_retval < 0) {
        Serial.print("Character mapping failed, error code: ");
        Serial.println(init_retval);
    }
}

void loop()
{
    static int32_t mapping_status = SegMap595.get_status();
    uint32_t counter = 0;
    static bool display_update_due = true;

    uint64_t current_millis = millis();
    static uint64_t previous_millis = current_millis;

    if ((mapping_status >= 0) && display_update_due) {  // If characters were successfully mapped.
        digitalWrite(LATCH_PIN, LOW);
        // Output a mapped character to a display.
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, SegMap595.mapped_characters[counter]);
        digitalWrite(LATCH_PIN, HIGH);
        display_update_due = false;
    }

    if (current_millis - previous_millis >= 1000) {  // Every second.
        ++counter;
        previous_millis = current_millis;
        display_update_due = true;
    }

    if (counter > 9) {
        counter = 0;
    }
}
