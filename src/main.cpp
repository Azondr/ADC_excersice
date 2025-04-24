#include <Arduino.h>

const int potPin = A0;  // Potentiometer an A0
const float referenceVoltage = 5.0;  // Standardmäßig 5V für Uno

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(potPin);
  float voltage = (analogValue / 1023.0) * referenceVoltage;
  Serial.print("Potentiometer analog value = ");
  Serial.print(voltage, 2);  // 2 Nachkommastellen
  Serial.println(" V");

  delay(500);  // 0.5 Sekunden warten
}
