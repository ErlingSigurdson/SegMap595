# SegMap595

SegMap595 is a single-class embdedded-oriented Arduino-friendly C++ library for mapping the outputs
of a 74HC595 IC to the segments of a 7-segment display.

## Concept

Usually outputting characters to a 7-segment display is done by forming all corresponding bytes
(sometimes called "bit masks") in advance and hardcoding them. This library simplifies the job
and lets your microcontroller do the whole job in one run based on a single parameter: the map string. 

## Map string

The map string is a C-style (null-terminated) string that must reflect the actual order of connections
made between parallel outputs of your 74HC595 and segment control pins of your 7-segment display.

The map string must consist of exactly 8 ASCII characters: @, A, B, C, D, E, F and G. Every character
corresponds to a single segment (@ stands for a dot). The first (leftmost) character in the map string
corresponds to the 7th (most significant) bit of the IC's parallel output (Q7 output), the second
character corresponds to the 6th bit (Q6 output), etc.

Uppercase characters may be substituted for their lowercase counterparts. Any other characters are invalid.
Duplicating characters in the map string is invalid.

```cpp
#define SEGMAP595_MAP_STR "ED@CGAFB"  // Valid map string example.
#define SEGMAP595_MAP_STR "ed@cgafb"  // Also valid.
#define SEGMAP595_MAP_STR "Ed@CgAfB"  // Still valid.
#define SEGMAP595_MAP_STR "ED@CGAF"   // Invalid: map string is too short.
#define SEGMAP595_MAP_STR "ED@CGAFM"  // Invalid: illegal character 'M'.
#define SEGMAP595_MAP_STR "ED@CGAFE"  // Invalid: duplicated character 'E'.
```

## API usage



If the map string is valid, mapped characters (bytes which
correspond to intelligible symbols to be output on a 7-segment
display) will be placed to the member array named mapped_characters
in the ascending order (from 0 to Z).

The dot bit will be cleared in all mapped character bytes,
therefore you will have to set this bit in your implementation
if necessary (get_dot_bit_pos method can be helpful).



## Compatibility

The library is primarily intended and documented for use with Arduino framework, but it doesn't
include `Arduino.h` and can be readily used in non-Arduino embedded electronics projects. 
