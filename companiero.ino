/*Cuando el sensor ultrasonico detecteuna distancia menor a 8cm
     *  Motor apagado
     *  Led A parpadeando cada 1seg
     *  Led B prendido  
 *Cuando el sensor ultrasonico detecta entre 8 a 35 cm
 *    la velocidad debe variar de acuerdo a la distancia
 *    Ej: si D= 8cm entnces  V = 60 
 *        si D = 35cm entonces V = 255
 *    Ambos led deben estar prendidos
 *Cuando el sensor ultrasonico detecte una distancia mayor a 35cm
     *  Motor apagado
     *  Led A prendido
     *  Led B parpadeando 0.5s
 *  
*/
#include <Ultrasonic.h>
Ultrasonic sensor(50,51);
int ledA = 52;
int ledB = 53;
int M1 = 6;
int M2 = 7;
int velocidad;
int distancia;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  distancia = sensor.read();
  if(distancia<8 || distancia >35){
    velocidad = 0;
    }else{
      velocidad = trunc(7.3*distancia);
      }
  Serial.print("Distancia en CM: ");
  Serial.println(distancia);
  Serial.print("Velocidad : ");
  Serial.println(velocidad);
  if(distancia <8){
      analogWrite(M1,velocidad);
      analogWrite(M2,0);
      for(int i = 1;i<=4;i++){
        digitalWrite(ledA,HIGH);
        digitalWrite(ledB,HIGH);
        delay(1000);
        digitalWrite(ledA,LOW);
        delay(1000);
      }
    }else{
        if((distancia >= 8) && (distancia <= 35) ){
            analogWrite(M1,velocidad);
            analogWrite(M2,0);
            digitalWrite(ledA,HIGH);
            digitalWrite(ledB,HIGH);
            delay(8000);
          }else{
               analogWrite(M1,velocidad);
               analogWrite(M2,0);
               for(int i = 1;i<=8;i++){
                   digitalWrite(ledA,HIGH);
                   digitalWrite(ledB,HIGH);
                   delay(500);
                   digitalWrite(ledB,LOW);
                   delay(500);
              }      
        }
  }

}