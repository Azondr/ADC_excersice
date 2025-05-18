/*
  Pulsierende LED mit Timer0 PWM.
  Die LED pulsiert durch kontinuierliches Erhöhen und Verringern des Duty Cycles.
  Aziz Önder
  18.05.2025
*/

#include <Arduino.h>

int main()
{
  // Set pin 6 as output (output pin of OC0A)
  DDRD |= (1 << PD6);

  // Select Fast PWM Mode
  TCCR0A |= (1 << WGM00) | (1 << WGM01);

  // Clear OC0A on compare match
  TCCR0A |= (1 << COM0A1);

  // Start timer with no prescaler
  TCCR0B |= (1 << CS00);

  int brightness = 0;
  int direction = 1;

  for (;;)
  {
    // Set duty cycle
    OCR0A = brightness;

    // Update brightness for pulsating effect
    brightness += direction;
    if (brightness == 0 || brightness == 255) {
      direction = -direction;
    }

    // delay to control pulse speed
    _delay_ms(5);
  }
}
