MCU=attiny13
F_CPU=9600000
CC=avr-gcc
LD=avr-ld
OBJCOPY=avr-objcopy
SIZE=avr-size
AVRDUDE=avrdude
CFLAGS=-std=c11 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main

SRCS = example.c ws2812b_attiny13.c

all:
	${CC} ${CFLAGS} -o ${TARGET}.o ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex
	
flash:
	$(AVRDUDE) -c usbtiny -p t13 -U flash:w:${TARGET}.hex:i

clean:
	rm -f *.c~ *.o *.elf *.hex
