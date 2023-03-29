
int led=10; // variable led

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  // analog Write(,) : 2 parametros pin,valor(nº entero 0 a 255) o es low 255 es high 127= 2.5 voltios
  
  /*analogWrite(led,255);
  delay(500);
  
  analogWrite(led,175);
  delay(500);
  
  analogWrite(led,85);
  delay(500);
  
  analogWrite(led,0);
  delay(500);
  
  for(int i=0;i<=255; i+=50){ // for dentro de otro for
    analogWrite(led,i);
    delay(500);
  }
*/  
// asciende y desciende
  for(int i=255;i>=0; i-=25){ // for dentro de otro for
    analogWrite(led,i);
    delay(100);
  }
  for(int i=0;i<=255; i+=25){ // for dentro de otro for
    analogWrite(led,i);
    delay(100);
  }
}
