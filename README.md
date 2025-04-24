# ADC_excersice
 
## Register und Bits des ADC (laut Datenblatt ATmega328p)

## ADMUX – ADC Multiplexer Selection Register

Bit 7:6 – REFS1:0: Reference Selection Bits
Bits 3:0 – MUX3:0: Analog Channel Selection Bits

## ADCSRA – ADC Control and Status Register A
 ADEN – ADC aktivieren 
 ADSC – Start der Konvertierung
 ADIF – ADC Interrupt-Flag (zeigt an, wenn Konvertierung abgeschlossen)
 ADIE – ADC Interrupt aktivieren
 ADPS2:0 – Prescaler für den ADC-Takt

## Prescaler-Berechnung

 16 MHz / 128 = 125 kHz
 Prescaler-Einstellung: ADPS2 = 1, ADPS1 = 1, ADPS0 = 1 → Prescaler = 128

## Multiplexer-Einstellung

 MUX3:0 = 0000  (ADC0)

## Start der Konvertierung

 ADSC - Muss man sezten damit eine ADC Konvertierung beginnt

## Interrupt-Auswertung

 ADIE - Muss man setzen damit der Interrupt aktiviert wird
 ADCL oder ADLAR - Wenn die konvertierung fertig ist, findet man hier das ergebnis
