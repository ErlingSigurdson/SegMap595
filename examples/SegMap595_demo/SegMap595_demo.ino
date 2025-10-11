/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595_demo.ino
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  An example sketch demonstrating a basic usage of the SegMap595
 *           library.
 *
 *           Outputs all displayable characters one by one to a single-digit
 *           7-segment display using a bit-banging and a single 74HC595 IC.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

#include <SegMap595.h>


/*--- Library usage ---*/

/* Valid map string example. You should specify the relevant string
 * according to the actual (physical) order of connections in your circuit.
 */
#define MAP_STR "ED@CGAFB"


/*--- Misc ---*/

#define BAUD_RATE 115200

#define DATA_PIN  16
#define LATCH_PIN 17
#define CLOCK_PIN 18

// Specify your display type. Use one directive, comment out or delete the other.
#define DISPLAY_TYPE_COMMON_CATHODE
//#define DISPLAY_TYPE_COMMON_ANODE

#define INTERVAL 1000


/******************* FUNCTIONS ******************/

void setup()
{
    Serial.begin(BAUD_RATE);

    pinMode(DATA_PIN,  OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);

    // Character mapping.
    #ifdef DISPLAY_TYPE_COMMON_CATHODE
        SegMap595.init(MAP_STR, SEGMAP595_COMMON_CATHODE);
    #elif defined DISPLAY_TYPE_COMMON_ANODE
        SegMap595.init(MAP_STR, SEGMAP595_COMMON_ANODE);
    #else
        #error "Display type not specified."
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
            delay(INTERVAL);
        }
    }


    /*--- Demo output to single-digit 7-segment display ---*/

    uint64_t current_millis = millis();
    static uint64_t previous_millis = current_millis;
    
    static uint32_t counter = 0;
    if (counter >= SEGMAP595_CHAR_NUM) {
        counter = 0;
    }

    static bool display_update_due = true;
    
    if (display_update_due) {
        uint8_t byte_to_shift = SegMap595.get_mapped_character(counter);
        // Dot segment blink.
        if (counter % 2) {
            static uint32_t dot_bit_pos = SegMap595.get_dot_bit_pos();
            uint8_t mask = static_cast<uint8_t>(1u << dot_bit_pos);
            byte_to_shift ^= mask; 
        }

        // Output mapped character.
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
