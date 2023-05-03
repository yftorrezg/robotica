#include <SoftwareSerial.h>
SoftwareSerial BT(10,11); // 10 es Rx y el 11 = Tx 
/*
Si el BT ha mandado algo 
codigo para comunicar del BT a PC y viceversa
*/
void setup() {
  /*
  Serial.begin(9600); // presionar continuamente y escribir 'AT' en el serial
  BT.begin(9600); // y te devuelve OK
*/
  Serial.begin(38400);
  BT.begin(38400);
}

void loop() {
  if(BT.available()) {
    Serial.write(BT.read());
    //Serial.write(BT.get);
  }
  if(Serial.available()){
    BT.write(Serial.read());
  }
}
