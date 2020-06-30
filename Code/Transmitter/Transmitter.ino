#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// wiring -->
// VCC+ to 3.3V
// GND to GND
// CSN to digital-pwm (8)
// CE to digital-pwm (7)
// MOSI to 51
// SCK to 52
// MISO to 50
// IRQ to 48 ?? Check SPI.h

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

int ledStatus = 0; //0 is off, 1 is on

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  currentStatus();
}

void loop() {
}

int currentStatus() {
  ledStatus = 1;
  return ledStatus;
}
