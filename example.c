// ws2812_toy - main implementation
//
// Author: Daan Sprenkels <hello@dsprenkels.com>
// Description: A toy implementation for using WS2812 RBG leds

#include "ws2812b_attiny13.h"
#include <inttypes.h>
#include <stdbool.h>

// Define a list of colors to pulsate
const struct color {
    const uint8_t red;
    const uint8_t green;
    const uint8_t blue;
} COLORS;

const int led_num=64;
const uint8_t pin=_BV(PB0);

int main() 
{
	uint8_t c=0;
    while (true) 
	{
		for( uint8_t i = 0; i < led_num ; i++ )
		{
		uint8_t red=0,green=0,blue=0;	
		if( c==0 ) { red=50; }
		else if( c==1 ) { green=50; }
		else if( c==2 ) { blue=50; }
		c++; if(c==3){ c=0;}
		ws2812b_set_color_no_reset( pin, red, green, blue);
		}
		ws2812b_reset( pin );
		_delay_ms(500);
    }
}
