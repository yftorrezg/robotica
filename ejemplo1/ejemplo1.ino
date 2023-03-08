void setup() {

  pinMode(13,INPUT); //pinMode(pin,modo:2 modos OUTPUT/INPUT)
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //digitalWrite(pin,HIGH); vota señal de 5 voltios
  //digitalWrite(13,LOW); // no vota señal, solo tiene 2 valores.. on/off
  digitalWrite(13,HIGH); 
}
