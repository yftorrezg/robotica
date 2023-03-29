#include <Ultrasonic.h>
Ultrasonic sen(7, 6);
int ledA = 2;
int ledB = 3;
int ledC = 4;

int potenciometro = A0;
int valor = 0;
int valorPotenciometro = 0;
int distancia = 0;


void setup() {
  
  Serial.begin(9600);

  
  // put your setup code here, to run once:
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(potenciometro, INPUT);
}

void loop() {

  distancia = sen.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distancia);

  
  // put your main code here, to run repeatedly:
  valorPotenciometro = analogRead(potenciometro);
  
  if(valorPotenciometro < 512){
    
    

    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    delay(500);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    delay(500);

      
  }else{
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
    
    if(distancia <=10){
        Serial.print("entra");
        digitalWrite(ledB, HIGH);
        digitalWrite(ledC, HIGH);
        delay(500);
      }else{
        digitalWrite(ledB, LOW);
        digitalWrite(ledC, LOW);
        delay(500);
      }
  }

}
