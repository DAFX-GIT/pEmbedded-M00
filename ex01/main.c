#include <avr/io.h>
#include <util/delay.h>

int main () {
	DDRB  |= (1 << PB0); // set PB0 as output
    PORTB |= (1 << PB0); // light D1 LED

	while (1);
}

/*
PB0			A constant defined in the AVR headers, equal to 0. It's the bit position of pin 0 on port B. On the schema we get that D1 is on PB0 which means PORT B BIT 0 -> PB0 mask 
PORTB		A hardware register that controls the output state of the pins on port B. Each of its 8 bits maps to one pin (PB0–PB7).
1 << PB0	Shifts the value 1 left by PB0 (0) positions, producing a bit mask with only bit 0 set.		1 << PB0  =  0b00000001
|=			The bitwise OR assignment operator. a |= b is shorthand for a = a | b.
*/