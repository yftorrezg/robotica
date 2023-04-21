
int led=10; // variable led

void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  //  analog Write(,) : 2 parametros: ( pin , valor(0-255) ) 
  //  0: low 
  //  255: high 
  //  127= 2.5 voltios
  
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
/*
digitalWrite: Controla pines en dos estados (0 o 1).
analogWrite: Controla pines en valores analógicos (0 a 255).
digitalWrite es para dispositivos binarios.
analogWrite es para dispositivos que requieren niveles intermedios.
No todos los pines son compatibles con analogWrite y la precisión varía.
*/