/* Sources used:
 * http://www.cplusplus.com/doc/tutorial/structures/
 * https://www.instructables.com/id/How-to-Use-the-NRF24L01s-IRQ-Pin-to-Generate-an-In/
 * https://github.com/nRF24/RF24/blob/master/examples/GettingStarted_HandlingData/GettingStarted_HandlingData.ino
 */

// libraries
# include <SPI.h>
# include <nRF24L01.h>
# include <RF24.h>

// wiring -->
// VCC+ to 3.3V
// GND to GND
// CSN to digital-pwm (8)
// CE to digital-pwm (7)
// MOSI to 51
// SCK to 52
// MISO to 50
// IRQ to 48 ?? Check SPI.h

// def radio
RF24 radio(7, 8); // CE, CSN

// user config
bool radioNumber = 0;
bool role = 1; // sending or receiving data

// constants
const byte address[6] = "00001";

// define own data types
struct transmit{ // struct dataType (below are traits of dataType)
  bool ledStatus;
};

// functions
int currentStatus() {
  ledStatus = 1;
  return ledStatus;
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));
  
  radio.begin(); // configure rf radio
  radio.setPALevel(RF24_PA_LOW); // likelihood of close proximity where RF24_PA_MAX is default

  // open writing & reading pipes on each radio with opposite addresses
  if (radioNumber){ // if radioNumber is 0 then considered false
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1, addresses[0]);
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1, addresses[1]);
  }
  
  radio.startListening(); // for data via reading pipe
}

void loop() {
  if (role == 1){
    radio.stopListening();

    Serial.println(F("Now sending"));

    transmit.ledStatus = 1;
    if (!radio.write(&transmit, sizeof(transmit))){
      Serial.println(F("failed"));
    }

    radio.startListening();
  }
}
