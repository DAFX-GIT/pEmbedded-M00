#include <avr/io.h>
#include <util/delay.h>

int main () {
    // Configuration
    DDRB |= (1 << PB0);     // PB0 (D1) en sortie → LED
    DDRD &= ~(1 << PD2);    // PD2 (D2) en entrée → Bouton
    PORTD |= (1 << PD2);    // Activer pull-up sur PD2

    while (1) {
		_delay_ms(20); //debounce
        if (!(PIND & (1 << PD2))) {    // Bouton pressé (LOW)
            PORTB ^= (1 << PB0);}        // LED TOGGLE
		while (!(PIND & (1 << PD2)));   // Attente du release
		_delay_ms(20);

    }
}