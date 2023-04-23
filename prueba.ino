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
Ultrasonic sensor(50,51); // Los pines 50 y 51 son los pines de entrada y salida del sensor ultrasónico: triguer = 50, echo = 51
int ledA = 52; // El pin 52 es el pin de salida del led A
int ledB = 53; // El pin 53 es el pin de salida del led B
int M1 = 6; // El pin 6 es el pin de salida del motor 1
int M2 = 7; // El pin 7 es el pin de salida del motor 2
int velocidad; // la velocidad del motor
int distancia; // la distancia medida por el sensor ultrasónico
int pot = A0; // El pin A0 es el pin de entrada del potenciómetro
int valor; // el valor leído del potenciómetro

void setup() {
  pinMode(ledA,OUTPUT); 
  pinMode(ledB,OUTPUT); 
  pinMode(M1,OUTPUT); 
  pinMode(M2,OUTPUT); 
  pinMode(pot,INPUT); 
  Serial.begin(9600); // Iniciar la comunicación serial a 9600 baudios
}

void loop() {
  distancia = sensor.read(); // Leer la distancia medida por el sensor ultrasónico
  valor = analogRead(pot); // Leer el valor del potenciómetro
  velocidad = map(valor,0,1023,190,200); // Mapear el valor del potenciómetro a un rango de velocidad de 0 a 200

  Serial.print("Distancia en CM: "); 
  Serial.println(distancia); 
  Serial.print("Velocidad : "); 
  Serial.println(velocidad); 
  Serial.print("Valor del potenciómetro: ");
  Serial.println(valor);

  if(valor > 512){ // Si el valor del potenciómetro es mayor a 512
    if(distancia < 15){ // Si la distancia medida por el sensor es menor a 15 cm
      analogWrite(M1,velocidad); // Activar el motor 1 con la velocidad calculada
      analogWrite(M2,0); 
      digitalWrite(ledA,HIGH); // Encender el led A
      digitalWrite(ledB,LOW); // Apagar el led B
      delay(8000); 
    }else{
      analogWrite(M1,0); // Detener el motor 1
      analogWrite(M2,0); 
      digitalWrite(ledA,LOW); // Apagar el led A
      digitalWrite(ledB,LOW); // Apagar el led B
      delay(8000); 
    }
  }else{
    if(distancia > 15){ // Si la distancia medida por el sensor es mayor a 15 cm
      analogWrite(M1,0); 
      analogWrite(M2,velocidad); // Activar el motor 2 con la velocidad calculada
      digitalWrite(ledA,LOW); 
      digitalWrite(ledB,HIGH);
      delay(8000); 
    }else{
      analogWrite(M1,0); 
      analogWrite(M2,0); 
      digitalWrite(ledA,LOW); 
      digitalWrite(ledB,LOW); 
      delay(8000); 
    }
  }
}