# Overview

**SegMap595** is a single-class embedded-oriented Arduino-friendly C++ library
for mapping the outputs of a **74HC595 IC** to the segments of a **7-segment display**.

## Concept

Usually outputting characters to a 7-segment display involves forming all corresponding bytes
(sometimes called "bit masks") in advance and hardcoding them. This library automates the task
and lets your microcontroller do the whole job in one run based on a single parameter: the map string. 

## Map string

The map string is a C-style (null-terminated) string that must reflect the actual (physical) order
of connections made between parallel outputs of your 74HC595 and segment control pins of your 7-segment display.

The map string must consist of exactly 8 ASCII characters: **@, A, B, C, D, E, F and G**. Every character
corresponds to a single segment (@ stands for a dot). The first (leftmost) character in the map string
corresponds to the 7th (most significant) bit of the IC's parallel output (Q7 output), the second
character corresponds to the 6th bit (Q6 output), etc.

Uppercase characters may be substituted for their lowercase counterparts. Any other characters are invalid.
Duplicating characters in the map string is invalid.

```cpp
#define MAP_STR "ED@CGAFB"  // Valid map string example.
#define MAP_STR "ed@cgafb"  // Also valid.
#define MAP_STR "Ed@CgAfB"  // Still valid.
#define MAP_STR "ED@CGAF"   // Invalid: map string is too short.
#define MAP_STR "ED@CGAFM"  // Invalid: illegal character 'M'.
#define MAP_STR "ED@CGAFE"  // Invalid: duplicated character 'E'.
```

## Mapped characters

If the map string is valid, mapped characters (custom formed bytes that correspond to symbols to be output
on a 7-segment display) will be placed to a member array in the ascending order: from 0 to 9, from A to Z,
dash and underscore on top. Undisplayable symbols ('M', 'V', 'W', 'X') are omitted.

## API usage

Include the library:
```cpp
#include <SegMap595.h>  // Arduino style.
#include "SegMap595.h"  // Generic embedded programming style.
```

"Load" the map string into an object using init() method:
```cpp
SegMap595.init(MAP_STR, SEGMAP595_COMMON_CATHODE);  // If using common cathode display.
SegMap595.init(MAP_STR, SEGMAP595_COMMON_ANODE);    // If using common anode display.
```

Check the mapping status (optional):
```cpp
static int32_t mapping_status = SegMap595.get_status();
// Loop error output if mapping was unsuccessful.
if (mapping_status < 0) {
    while(true) {
        Serial.print("Character mapping failed, error code: ");
        Serial.println(mapping_status);
        delay(INTERVAL);
    }
}
```

Get necessary mapped character:
```cpp
uint8_t mapped_character = SegMap595.get_mapped_character(counter);           // Get by incremented index.
uint8_t mapped_character = SegMap595.get_mapped_character(SEGMAP595_CHAR_A);  // Get by a macro index name.
```

If necessary, toggle the dot segment bit:

```cpp
if (counter % 2) {
    static uint32_t dot_bit_pos = SegMap595.get_dot_bit_pos();
    uint8_t mask = static_cast<uint8_t>(1u << dot_bit_pos);
    mapped_character ^= mask;
}
```

If for some reason you need to retrieve the map string you've passed earlier, get a pointer to it:
```cpp
const char *map_str_retrieved = SegMap595.get_map_str();
```

Refer to `SegMap595.h` for the full description of return values if necessary.

## Compatibility

The library is primarily intended and documented for use with Arduino framework, but it doesn't
include `Arduino.h` and can be readily used in non-Arduino embedded electronics projects. 
