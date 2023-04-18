#include <EEPROM.h>
int addr = 0; //address

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}

void loop()

{



  if    (Serial.available() > 0 ) {       //check if there is data


    int received = Serial.read();    //read data (one byte), store in received
    EEPROM.write(addr, received);     //write received to eeprom at address (default 0)

    addr = addr + 1;                         //increment address

  }
  if (addr >= 1023) {
    digitalWrite(13, HIGH);
  }





}








