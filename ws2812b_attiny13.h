// Headers for WS2812B protocol implementation for the attiny13
//
// Author: Daan Sprenkels <hello@dsprenkels.com>
// License: MIT

#ifndef WS2812B_ATTINY13_H_
#define WS2812B_ATTINY13_H_

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

void ws2812b_set_color_no_reset(const uint8_t pin_value, const uint8_t red, const uint8_t green, const uint8_t blue);
void ws2812b_set_color(const uint8_t pin_value, const uint8_t red, const uint8_t green, const uint8_t blue);
void ws2812b_reset(const uint8_t pin_value);
#endif // WS2812B_ATTINY13_H_