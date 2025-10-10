/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595.ino
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  An example sketch demonstrating a basic usage of the SegMap595
 *           library. Outputs all valid characters one by one to a single-digit
 *           7-segment display using a bit-banging and a single 74HC595 IC.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

#include <SegMap595.h>


/*--- Library usage ---*/

/* Valid map string example. You should specify the relevant string
 * according to the actual order of connections in your circuit.
 */
#define SEGMAP595_MAP_STR "ED@CGAFB"


/*--- Misc ---*/

#define BAUD_RATE 115200

#define DATA_PIN  6
#define LATCH_PIN 7
#define CLOCK_PIN 8

#define INTERVAL 1000


/******************* FUNCTIONS ******************/

void setup()
{
    pinMode(DATA_PIN,  OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);

    Serial.begin(BAUD_RATE);

    // Character mapping (choose variant according to display type).
    SegMap595.init(SEGMAP595_MAP_STR, SEGMAP595_COMMON_CATHODE);
    //SegMap595.init(SEGMAP595_MAP_STR, SEGMAP595_COMMON_ANODE);
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
            delay(INTERVAL);
        }
    }


    /*--- Demo output to single-digit 7-segment display ---*/
    
    static uint32_t counter = 0;
    if (counter >= SEGMAP595_CHAR_NUM) {
        counter = 0;
    }

    uint64_t current_millis = millis();
    static uint64_t previous_millis = current_millis;

    static bool display_update_due = true;
    
    if (display_update_due) {
        uint8_t byte_to_shift = SegMap595.get_mapped_character(counter);
        // Dot segment blink.
        if (counter % 2) {
            uint8_t mask = static_cast<uint8_t>(1u << SegMap595.get_dot_bit_pos());
            byte_to_shift ^= mask; 
        }

        // Output a mapped character to the display.
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, byte_to_shift);
        digitalWrite(LATCH_PIN, HIGH);
        display_update_due = false;
    }

    if (current_millis - previous_millis >= INTERVAL) {
        ++counter;
        display_update_due = true;
        previous_millis = current_millis;
    }
}
