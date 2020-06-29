#include <SPI.h>
#include </Users/reyna/Desktop/RF24/nRF24L01.h>
#include </Users/reyna/Desktop/RF24/RF24.h>

// wiring -->
// VCC+ to 3.3V
// GND to GND
// CSN to digital-pwm (8)
// CE to digital-pwm (7)
// MOSI to 51
// SCK to 52
// MISO to 50
// IRQ to 48 ??

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);
}
