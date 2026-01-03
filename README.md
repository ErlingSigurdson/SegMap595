# Overview

**SegMap595** is a single-class embedded-oriented Arduino-compatible C++ library for mapping
the parallel outputs of a 74HC595 shift register IC to the segments of a 7-segment display.

## Concept

Typically, outputting a glyph (a character representation) on a 7-segment display involves composing a byte
whose combination of bit states (set or cleared) corresponds to a pattern in which the segments must be turned
ON and OFF to form a recognizable symbol. Finding the proper correspondence between the bit states and the segment
pattern is called **mapping**.

**74HC595**, sometimes simply called **595**, is a widely used 8-bit serial-in, parallel-out (SIPO) shift register
integrated circuit (IC) commonly employed to drive 7-segment displays.

**Mapped bytes** (sometimes called **bit masks**) can be precomputed and hard-coded into a program run by
a microcontroller (MC) or a similar device that drives a display. Although it may be perfectly acceptable,
it may become troublesome if the program needs to be adapted to a circuit with a different wiring order
between the device's outputs and the display's control pins. This library automates the task and lets
your device do the whole job in one go based on three parameters:
* a map string
* a display type (either common-cathode or common-anode)
* a glyph set

## Map string

The **map string** is a C-style (null-terminated) string that must reflect the actual (physical) order of connections
made between the parallel outputs of your 74HC595 and the segment control pins of your 7-segment display.

The map string must consist of exactly 8 ASCII characters: **@**, **A**, **B**, **C**, **D**, **E**, **F** and **G**.
Every character corresponds to a single segment (@ stands for a dot, also known as a decimal point or DP).
The first (leftmost) character in the map string corresponds to the 7th bit (most significant bit, MSB) of a byte
stored in the shift register, connected to the Q7 parallel output.
The last (rightmost) character in the map string corresponds to the 0th bit (least significant bit, LSB) of a byte
stored in the shift register, connected to the Q0 parallel output.

Uppercase characters may be replaced with their lowercase counterparts. Any other characters are invalid.
Duplicating characters is invalid as well.

```cpp
#define MAP_STR "ED@CGAFB"    // Valid map string example.
//#define MAP_STR "ed@cgafb"  // Also valid.
//#define MAP_STR "Ed@CgAfB"  // Still valid.
//#define MAP_STR "ED@CGAF"   // Invalid: map string is too short.
//#define MAP_STR "ED@CGAFM"  // Invalid: invalid character 'M'.
//#define MAP_STR "ED@CGAFE"  // Invalid: duplicated character 'E'.
```

## Mapped bytes

If the map string is valid, mapped bytes will be placed in a member array in the ascending order of characters
they represent: from 0 to 9, from A to Z, non-alphanumerics at the end.

By default, the dot bit will be in an OFF state (cleared for a common-cathode display, set for a common-anode display)
in all mapped bytes, therefore you will have to control the dot state in your code as necessary (see suggestions below).

Glyphs are not standardized globally. Some of them do resemble their actual prototype characters, some are
rather sketchy (like G, K, T, V, X and Z), others are outright arbitrary (like M and W).

This library offers two glyph sets:

### Set #1 (default)

This set includes all English letters, although some of them are represented by arbitrary glyphs:

![Glyphs](extras/images/glyph_set_1.jpg)

### Set #2

This set avoids arbitrary glyphs, but lacks the letters K, M, V, W and X:

![Glyphs](extras/images/glyph_set_2.jpg)

## API usage

Include the library:
```cpp
#include <SegMap595.h>    // Arduino style.
//#include "SegMap595.h"  // Generic embedded programming style.
```

"Load" the map string into an object, specify a display type (based on its common pin) and select a glyph set:
```cpp
SegMap595.init(MAP_STR,
               SegMap595CommonCathode,  // Other option is `SegMap595CommonAnode`.
               SegMap595GlyphSet1       // Other option is `SegMap595GlyphSet2`. Optional parameter.
              );
```
If the third parameter is omitted, glyph set #1 will be selected by default.

Get the last mapping status:
```cpp
int32_t mapping_status = SegMap595.get_status();
// Loop the error output if the mapping was unsuccessful.
if (mapping_status < 0) {  // If an error is detected.
    while(true) {
        Serial.print("Error: mapping failed, error code ");
        Serial.println(mapping_status);
        delay(INTERVAL);
    }
}
```
You can also check the value returned by `init()` instead of calling `get_status()`.

Get a mapped byte:
```cpp
// Get by a represented character (case-insensitive).
uint8_t mapped_byte = SegMap595.get_mapped_byte('0');
uint8_t mapped_byte = SegMap595.get_mapped_byte('9');
uint8_t mapped_byte = SegMap595.get_mapped_byte('A');
uint8_t mapped_byte = SegMap595.get_mapped_byte('Z');
uint8_t mapped_byte = SegMap595.get_mapped_byte('-');
uint8_t mapped_byte = SegMap595.get_mapped_byte('_');
uint8_t mapped_byte = SegMap595.get_mapped_byte('*');  /* The asterisk represents the degree symbol because
                                                        * the actual degree symbol isn't listed in ASCII.
                                                        */

// Get by a decimal digit's numerical value (from 0 to 9).
uint8_t mapped_byte = SegMap595.get_mapped_byte(0);    // Returns a byte for '0'.
uint8_t mapped_byte = SegMap595.get_mapped_byte(9);    // Returns a byte for '9'.

// Get by a hexadecimal digit's numerical value (from 0 to 15, or from 0x0 to 0xF).
uint8_t mapped_byte = SegMap595.get_mapped_byte(0);    // Returns a byte for '0'.
uint8_t mapped_byte = SegMap595.get_mapped_byte(15);   // Returns a byte for 'F'.
uint8_t mapped_byte = SegMap595.get_mapped_byte(0x0);  // Returns a byte for '0'.
uint8_t mapped_byte = SegMap595.get_mapped_byte(0xA);  // Returns a byte for 'A'.
uint8_t mapped_byte = SegMap595.get_mapped_byte(0xF);  // Returns a byte for 'F'.

// Get by an incremental index. Use `counter < SegMap595.get_glyph_num()` as an appropriate boundary.
uint8_t mapped_byte = SegMap595.get_mapped_byte(counter);

// Get by an index macro name specific to a glyph set (match your selected set).
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_1_INDEX_0);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_1_INDEX_9);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_1_INDEX_A);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_1_INDEX_Z);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_1_INDEX_DASH);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_1_INDEX_UNDERSCORE);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_2_INDEX_0);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_2_INDEX_9);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_2_INDEX_A);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_2_INDEX_Z);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_2_INDEX_DASH);
uint8_t mapped_byte = SegMap595.get_mapped_byte(SEGMAP595_GLYPH_SET_2_INDEX_UNDERSCORE);
```

Control the dot segment state:
```cpp
mapped_byte = SegMap595.turn_on_dot(mapped_byte);
mapped_byte = SegMap595.turn_off_dot(mapped_byte);
mapped_byte = SegMap595.toggle_dot(mapped_byte);

// Toggle the dot segment periodically to make it blink.
if (counter % 2) {
    mapped_byte = SegMap595.toggle_dot(mapped_byte);
}
```

Get the number of glyphs available in the selected glyph set (typically used as a loop boundary):
```cpp
size_t glyph_num = SegMap595.get_glyph_num();
```

Get a character (its ASCII code) that corresponds to a given index in the resulting array of mapped bytes:
```cpp
char represented_char = SegMap595.get_represented_char(counter);
```

Get a pointer to a string that represents a standard (since GCC 4.3 and C++14) binary number notation
for a given byte (`0bXXXXXXXX`):
```cpp
const char *byte_bin_notation = SegMap595.get_byte_bin_notation_as_str(byte_to_shift);
```
This method works as a utility: it can be used regardless of whether mapping was performed and
whether it was successful.

Get a pointer to an object's internal buffer that holds the map string you've passed earlier:
```cpp
const char *map_str_retrieved = SegMap595.get_map_str();
```

Refer to `SegMap595.h` for more API details.

## Compatibility

The library is highly portable: its code should compile and run on any platform with a C++ compiler that supports
C++14 or later. It will also compile with C++11 if your compiler supports binary literals (`0b…`) as an extension
(e.g., GCC 4.3+).

Actual interfacing with a 74HC595 (such as demonstrated in the example sketch) requires
an MC or a similar embedded device capable of bit-banging or SPI data transfer.

The library is primarily intended and documented for use with the Arduino framework, but it doesn't
include `Arduino.h` and can be readily used in non-Arduino embedded electronics projects.

## License

This library is licensed under the **MIT License** (see `LICENSE` [here](LICENSE)).

## Links

### This library
* [Primary repository on GitHub](https://github.com/ErlingSigurdson/SegMap595)
* [Backup repository on GitFlic](https://gitflic.ru/project/efimov-d-v/segmap595)
* [Backup repository on Codeberg](https://codeberg.org/ErlingSigurdson/SegMap595)

## Contact details

**Maintainer** — Dmitriy Efimov aka Erling Sigurdson
* <efimov-d-v@yandex.ru>
* <erlingsigurdson1@gmail.com>
* Telegram: @erlingsigurdson

Your feedback and pull requests are welcome.
