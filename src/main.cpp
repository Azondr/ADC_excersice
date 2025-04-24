//Aziz Önder
//ADC Excercise


#include <Arduino.h>
const int poti = A0;  // Potentiometer  A0


void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int analogWert = analogRead(poti);
  float Spannung = (analogWert / 1023.0) * 5;
  Serial.print("Potentiometer analog value = ");
  Serial.print(Spannung); 
  Serial.println(" V");

  delay(500);  // 0.5 Sekunden warten
}
