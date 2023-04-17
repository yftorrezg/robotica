#include <Ultrasonic.h>
Ultrasonic sensor(2,3);
int distancia;
int led = 4;
int in1 = 5;
int in2 = 6; 
//Ejercicio: si el sensor mide menos de 22cm entncs el motor se mueva hacia adelante con una velocidad de 150.
//Si mide una distancia mayor o igual pero menor a 30, entncs que parpadee un led cada segundo.
//Si la distancia es mayor o igual que 30 que el motor se mueva hacia atras con una velocidad de 150.
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    distancia = sensor.read();
    if(distancia < 22){
        analogWrite(in1,150);
        analogWrite(in2,0);
    }else if(distancia <30 && distancia >=22){
        digitalWrite(led,HIGH);
        delay(1000);  
        digitalWrite(led,LOW);
        analogWrite(in1,0);
        analogWrite(in2,0);
    }else{
        analogWrite(in2,150);
        analogWrite(in1,0);
    }
  Serial.print("Distance in CM: ");
  Serial.println(distancia);
  delay(500);
}