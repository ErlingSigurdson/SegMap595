/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.ino
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  Example sketch demonstrating a basic use of the SegMap595 library.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

#include <SegMap595.h>


/*--- Misc ---*/

// Specify display type.
#define   USING_COMMON_CATHODE_DISPLAY
//#define USING_COMMON_ANODE_DISPLAY

#define SERIAL_BAUD_RATE 115200

#define DATA_PIN  6
#define LATCH_PIN 7
#define CLOCK_PIN 8

#define SEGMAP595_MAP_STR   "ED@CGAFB"  // Valid map string example.
//#define SEGMAP595_MAP_STR "ed@cgafb"  // Also valid.
//#define SEGMAP595_MAP_STR "Ed@cGaFb"  // Still valid.
//#define SEGMAP595_MAP_STR "E@CGAFB"   // Invalid: map string is too short.
//#define SEGMAP595_MAP_STR "E@CGAFBM"  // Invalid: illegal character 'M'.
//#define SEGMAP595_MAP_STR "E@CGAFBE"  // Invalid: duplicated character 'E'.


/******************* FUNCTIONS ******************/

void setup()
{
    pinMode(DATA_PIN,  OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);

    Serial.begin(SERIAL_BAUD_RATE);

    // Character mapping.
    #if   defined USING_COMMON_CATHODE_DISPLAY
        SegMap595.init(SEGMAP595_MAP_STR, SEGMAP595_COMMON_CATHODE);
    #elif defined USING_COMMON_ANODE_DISPLAY
        SegMap595.init(SEGMAP595_MAP_STR, SEGMAP595_COMMON_ANODE);
    #endif
}

void loop()
{
    /*--- Mapping status check ---*/
    
    static int32_t mapping_status = SegMap595.get_status();

    // Loop error output if mapping was unsuccessful.
    if (mapping_status < 0) {
        while(true) {
            Serial.print("Character mapping failed, error code: ");
            Serial.println(mapping_status);
            delay(1000);
        }
    }


    /*--- Test output to single-digit 7-segment display ---*/
    
    uint32_t counter = 0;
    if (counter > 9) {
        counter = 0;
    }

    uint64_t current_millis = millis();
    static uint64_t previous_millis = current_millis;

    static bool display_update_due = true;
    
    if (display_update_due) {  // If characters were successfully mapped.
        digitalWrite(LATCH_PIN, LOW);
        // Output a mapped character to the display.
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, SegMap595.mapped_characters[counter]);
        digitalWrite(LATCH_PIN, HIGH);
        display_update_due = false;
    }

    if (current_millis - previous_millis >= 1000) {  // Every second.
        ++counter;
        display_update_due = true;
        previous_millis = current_millis;
    }
}
