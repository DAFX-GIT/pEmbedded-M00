#include <avr/io.h>
#include <util/delay.h>

#define BIN_MAX 15

const uint8_t ledBits[4] = {PB0, PB1, PB2, PB4}; // store all led in an array

void showNumber(uint8_t n) {
    for (uint8_t i = 0; i < 4; i++) {
        if ((n >> i) & 1) // shift binaire et mask pour afficher que le bit de droite qui au depart est le premier, puis deuxieme avec le shift etc etc...
            PORTB |=  (1 << ledBits[i]);   // LED on
        else
            PORTB &= ~(1 << ledBits[i]);    //LED off
    }
}

int main () {
    // Configuration
    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB4); //D1 D2 D3 D4 en sortie → LED

    

    DDRD &= ~(1 << PD2);    // PD2 (SW1) en entrée → Bouton
    PORTD |= (1 << PD2);    // Activer pull-up sur PD2

    DDRD &= ~(1 << PD4);    // PD4 (SW2) en entrée → Bouton
    PORTD |= (1 << PD4);    // Activer pull-up sur PD4

    uint8_t value = 0;
    
    while (1) {
        if (!(PIND & (1 << PD2))) {    // SW1 Bouton pressé (LOW)
            if (value < BIN_MAX) value++;
            _delay_ms(20);                  //debounce
            while (!(PIND & (1 << PD2)));   // Attente du release du bouton
            _delay_ms(20);                  // debounce
        } else if (!(PIND & (1 << PD4))) {    // SW1 Bouton pressé (LOW)
            if (value > 0) value--;
            _delay_ms(20);                 	//debounce
            while (!(PIND & (1 << PD4)));   // Attente du release
            _delay_ms(20);                  //debounce
        }
        showNumber(value);
    }
}