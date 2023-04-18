
#include <EEPROM.h>


int address = 0;
byte value;

void setup() {
  Serial.begin(9600);
}

void loop() {

  value = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();

  address = address + 1;
//  if (address == EEPROM.length()) 
//{
//    Serial.end();//done
//  }


  delay(1);
}
