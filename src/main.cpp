//Aziz Önder
//ADC Excercise


#include <Arduino.h>

#define ADC_CHANNEL 0;
volatile int Poti_Value;
volatile bool value_ready = false;

void setup() 
{
  Serial.begin(9600);

  // enable ADC and set prescaler to 128 -> 125kHz @ 16MHz (best conversion rast is between 50 - 200kHz)
  ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
 
  // set ADC channel of multiplexer
  ADMUX = (ADMUX & 0b11110000) | ADC_CHANNEL;
  
  // set internal 5V reference
  ADMUX |= (1 << REFS0);

  sei();

}

void loop() 
{
  //int poti_value = analogRead(A0);
  ADCSRA |= (1 << ADSC);                      // start ADC conversion
  while((ADCSRA & (1 << ADSC)) != 0);         // ADSC is cleared when conversion is completed

  if(value_ready == true)                     
  {
    value_ready = false;                      // value_ready is set false, so that it can loop
  float Voltage = (Poti_Value * 5.0) / 1023;
  Serial.print("Potentiometer analog value = ");
  Serial.print(Voltage); 
  Serial.println(" V");

  }
}

ISR(ADC_vect)           //Triggers automatically if Interrupt Flag is set
{
  static int counter = 0;

  counter++;

  if (counter >= 30)    // Trigger every 500ms
  {
    Poti_Value = ADC;            
    value_ready = true;   // value_ready is set true, so that he programm can loop
  }
}