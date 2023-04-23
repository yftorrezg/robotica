/*
2 leds, motor, potenciometro, y sensor ultrasonico
la funcionalidad depende del valor del potenciometro si es mas de la mitad o menos.

Cuando el potenciometro esta en mas de la mitad de su valor:
  *  El motor debe girar en un sentido (adelante) a 200 de velocidad hasta q el sensor ultrasonico detecte menos de 15 cm
  *  El led A debe estar prendido
  *  El led B debe estar apagado

Cuando el potenciometro en menos de la mitad de su valor:
  *  El motor debe girar en el otro sentido (Atras) a 190 de velocidad hasta q el sensor ultrasonico detecte una distancia mayor a 15 cm
  *  El led A debe estar apagado
  *  El led B debe estar prendido
*/

#include <Ultrasonic.h>
Ultrasonic sensor(50,51);
int ledA = 52;
int ledB = 53;
int M1 = 6;
int M2 = 7;
int velocidad;
int distancia;
int pot = A0;
int valor;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  distancia = sensor.read();
  valor = analogRead(pot);
  velocidad = map(valor,0,1023,190,200);
  
  Serial.print("Distancia en CM: "); 
  Serial.println(distancia); 
  Serial.print("Velocidad : "); 
  Serial.println(velocidad); 
  Serial.print("Valor del potenciómetro: ");
  Serial.println(valor);
  
  if(valor > 512){
    if(distancia < 15){
      analogWrite(M1,velocidad);
      analogWrite(M2,0);
      digitalWrite(ledA,HIGH);
      digitalWrite(ledB,LOW);
      delay(500);
    }else{
      analogWrite(M1,0);
      analogWrite(M2,0);
      digitalWrite(ledA,LOW);
      digitalWrite(ledB,LOW);
      delay(500);
    }
  }else{
    if(distancia > 15){
      analogWrite(M1,0);
      analogWrite(M2,velocidad);
      digitalWrite(ledA,LOW);
      digitalWrite(ledB,HIGH);
      delay(500);
    }else{
      analogWrite(M1,0);
      analogWrite(M2,0);
      digitalWrite(ledA,LOW);
      digitalWrite(ledB,LOW);
      delay(500);
    }
  }
}
