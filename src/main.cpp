#include <Arduino.h>
#include "BluetoothSerial.h"
#include "ELMduino.h"

BluetoothSerial SerialBT;
ELM327 myELM327;

String masterName = "ESP32-BT-Master";
String MACadd = "66:1E:21:00:28:46"; // This only for printing
uint8_t address[6]  = {0x66, 0x1E, 0x21, 0x00, 0x28, 0x46}; // ELM327 MAC address
const char *pin = "1234"; // ELM327 BT password

float FuelLevel;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(masterName, true);
  SerialBT.setPin(pin);
  
  Serial.print("Connecting with ELM327 through MAC "); Serial.println(MACadd);
  while (!SerialBT.connect(address))
  {
    Serial.println("...");
  }
  Serial.println("Connected Successfully!");
  myELM327.begin(SerialBT, true, 2000);
}

void loop() {
  FuelLevel = myELM327.fuelLevel();
  if (myELM327.nb_rx_state == ELM_SUCCESS)
  {
    Serial.print("Current fuel level: ");Serial.println(FuelLevel);
  }
  else if (myELM327.nb_rx_state != ELM_GETTING_MSG)
  {
    myELM327.printError();
  }
  delay(400);
}
