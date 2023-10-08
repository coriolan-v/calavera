// Adafruit nOOds digital control using GPIO pins.
// Uses 3 nOOds, anode (+) to GPIO pin, cathode (-) to ground.
// A current-limiting resistor (e.g. 220 Ohm) can go at either end.

// This uses the 3 adjacent SPI pins on QtPy RP2040, but any pins will do.
uint8_t pins[] = { 10, 9, 8, 7, 6 };  // List of pins, one per nOOd
#define NUM_PINS 5

void setup() {
  //for (uint8_t i = 0; i < NUM_PINS; i++) pinMode(pins[i], OUTPUT);
}

int maxPWM = 255;
int delayPause = 5;
void loop() {
  for (int i = 0; i < maxPWM; i++) {
    for (uint8_t p = 0; p < NUM_PINS; p++) analogWrite(pins[p], i);
    delay(delayPause);
  }

  for (int i = maxPWM; i > 0; i--) {
    for (uint8_t p = 0; p < NUM_PINS; p++) analogWrite(pins[p], i);
    delay(delayPause);
  }
  
}
// for (uint8_t i=0; i<NUM_PINS; i++) { // For each pin...
//   digitalWrite(pins[i], HIGH);       // nOOd on
//   delay(500);                        // Pause 1/2 sec
//   digitalWrite(pins[i], LOW);        // nOOd off
// }
