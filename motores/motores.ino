// variables 

int mot_der1 = 10;
int mot_der2 = 9;

int mot_izq1= 6;
int mot_izq2 = 5;

void setup(){
  
  pinMode(mot_der1,OUTPUT);
  pinMode(mot_der2,OUTPUT);
  pinMode(mot_izq1,OUTPUT);
  pinMode(mot_izq2,OUTPUT);

   
}

void loop(){

  // adelante
  digitalWrite(mot_der1,HIGH);
  digitalWrite(mot_der2,LOW);
  digitalWrite(mot_izq1,HIGH);
  digitalWrite(mot_izq2,LOW);
  
  delay(1000);
  
  // atras
  digitalWrite(mot_der1,LOW);
  digitalWrite(mot_der2,HIGH);
  digitalWrite(mot_izq1,LOW);
  digitalWrite(mot_izq2,HIGH);
  
  delay(1000);
  
  // derecha
  digitalWrite(mot_der1,LOW);
  digitalWrite(mot_der2,HIGH);
  digitalWrite(mot_izq1,HIGH);
  digitalWrite(mot_izq2,LOW);
  
  delay(1000);
  
  // izquierda
  digitalWrite(mot_der1,HIGH);
  digitalWrite(mot_der2,LOW);
  digitalWrite(mot_izq1,LOW);
  digitalWrite(mot_izq2,HIGH);
  
  delay(1000);
  
  // parar
  digitalWrite(mot_der1,LOW);
  digitalWrite(mot_der2,LOW);
  digitalWrite(mot_izq1,LOW);
  digitalWrite(mot_izq2,LOW);
  
  delay(1000); 

/* 
  analogWrite(mot_der1,150); // se mueve a velocidad 150
  // analogWrite(mot_der2,150); // no se mueve
  analogWrite(mot_der2,0);

  analogWrite(mot_izq1,0);
  analogWrite(mot_izq2,0);

// durante 2 segundos
  delay(2000);

   analogWrite(mot_der1,0); // se mueve a velocidad 150
  // analogWrite(mot_der2,150); // no se mueve
  analogWrite(mot_der2,0);

  analogWrite(mot_izq1,100);
  analogWrite(mot_izq2,0);

// durante 2 segundos
  delay(2000);
  
 */

}
