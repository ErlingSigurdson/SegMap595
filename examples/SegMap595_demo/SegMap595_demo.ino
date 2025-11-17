/*************** FILE DESCRIPTION ***************/

/**
 * Filename: SegMap595_demo.ino
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  An example sketch demonstrating basic usage of the SegMap595
 *           library.
 *
 *           Cycles through all glyphs in the selected glyph set
 *           and displays them, one by one, on a single-digit 7-segment
 *           display by bit-banging a 74HC595 shift register IC.
 *           Additionally, prints mapping information via UART.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:    Refer to the README for a general library overview.
 *           Refer to SegMap595.h for a detailed API description.
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

#include <SegMap595.h>


/*--- SegMap595 library API parameters ---*/

/* Map string.
 *
 * This string must reflect the actual (physical) order of connections made between
 * the parallel outputs of your 74HC595 and the segment control pins of your 7-segment display.
 *
 * The map string must consist of exactly 8 ASCII characters: '@', 'A', 'B', 'C', 'D', 'E', 'F' and 'G'.
 * Every character corresponds to a single segment ('@' stands for a dot, also known as a decimal point or 'DP').
 *
 * The first (leftmost) character in the map string corresponds to the 7th (most significant)
 * bit of the IC's parallel outputs ('Q7' output), the last (rightmost) character corresponds to
 * the 0th (least significant) bit ('Q0' output).
 *
 * Uppercase characters may be replaced with their lowercase counterparts. Any other characters
 * are invalid. Duplicating characters is invalid as well.
 */
#define MAP_STR "ED@CGAFB"

// Specify your display type based on its common pin. Use one variant, comment out or delete the other.
SegMap595Class::DisplayType display_common_pin = SegMap595CommonCathode;
//SegMap595Class::DisplayType display_common_pin = SegMap595CommonAnode;

// Select a glyph set. Use one variant, comment out or delete the other.
SegMap595Class::GlyphSetId glyph_set_id = SegMap595GlyphSet1;
//SegMap595Class::GlyphSetId glyph_set_id = SegMap595GlyphSet2;


/*--- Misc ---*/

// Set appropriately based on the baud rate you use.
#define BAUD_RATE 115200

// Specify appropriately based on your wiring.
#define DATA_PIN  16
#define LATCH_PIN 17
#define CLOCK_PIN 18

// Output interval ("once every X milliseconds").
#define INTERVAL 1000


/******************* FUNCTIONS ******************/

void setup()
{
    Serial.begin(BAUD_RATE);

    // Pin setup.
    pinMode(DATA_PIN,  OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);

    // Byte mapping.
    SegMap595.init(MAP_STR, display_common_pin, glyph_set_id);

    /* Mapping status check.
     * You can also check the value returned by init() instead of calling get_status().
     */
    int32_t mapping_status = SegMap595.get_status();

    // Loop the error output if the mapping was unsuccessful.
    if (mapping_status < 0) {  // If an error is detected.
        while(true) {
            Serial.print("Error: mapping failed, error code ");
            Serial.println(mapping_status);
            delay(INTERVAL);
        }
    }
}

void loop()
{
    /*--- Counter and output trigger ---*/

    uint32_t current_millis = millis();
    static uint32_t previous_millis = current_millis;

    static size_t counter = 0;
    static size_t glyph_num = SegMap595.get_glyph_num();
    if (counter >= glyph_num) {
        counter = 0;
    }

    // Output trigger.
    static bool output_due = true;


    /*--- Demo output ---*/

    if (output_due) {
        uint8_t byte_to_shift = SegMap595.get_mapped_byte(counter);

        // Print mapping information via UART.
        Serial.print("Based on map string ");
        Serial.print(SegMap595.get_map_str());

        char represented_char = SegMap595.get_represented_char(counter);
        if (represented_char == '*') {        /* The asterisk represents the degree symbol because
                                               * the actual degree symbol isn't listed in ASCII.
                                               */
            Serial.print(" degree symbol ");
        } else {
            Serial.print(" character '");
            Serial.print(represented_char);
            Serial.print("' ");
        }

        Serial.print("corresponds to mapped byte ");
        Serial.println(SegMap595.get_byte_bin_notation_as_str(byte_to_shift));

        // Dot-segment blink.
        if (counter % 2) {
            /* Normally you should check the returned value for being negative (error status indicator),
             * since shifting for a negative count leads to undefined behavior. But in this sketch
             * it's safe to assume a positive value because the status has already been checked.
             */
            static int32_t dot_bit_pos = SegMap595.get_dot_bit_pos();
            static uint8_t mask = static_cast<uint8_t>(1u << dot_bit_pos);
            byte_to_shift ^= mask;
        }

        // Output a glyph on the display.
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, byte_to_shift);
        /* Note that if your display's common pin is connected to the ground (for a common-cathode display)
         * or the positive rail (for a common-anode display) not directly, but via a switching device
         * (typically a transistor), at this point you also have to call a function that will turn on
         * the switch and thus power your display.
         */
        digitalWrite(LATCH_PIN, HIGH);

        output_due = false;
    }


    /*--- Counter and output trigger, continued ---*/

    if (current_millis - previous_millis >= INTERVAL) {
        ++counter;
        output_due = true;
        previous_millis = current_millis;
    }
}
