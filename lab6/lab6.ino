/*
controlar la velocidad del motor entre 0 a 200 de velocidad, con un potenciometro
si la velocidad es 0: encender un led de apagado 
si la velocidad es 200: encender otro led en alerta 
*/

int led1 = 4;
int led2 = 5;
int mot_der1 = 6;
int mot_der2 = 7;
int mot_izq1 = 8; 
int mot_izq2 = 9;
int pot = A0;

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
  pinMode(mot_der1,OUTPUT);
  pinMode(mot_der2,OUTPUT);
  pinMode(mot_izq1,OUTPUT);
  pinMode(mot_izq2,OUTPUT);
  pinMode(pot,INPUT);
}

void loop(){
  int velocidad = analogRead(pot);
  velocidad = map(velocidad,0,1023,0,200);
  Serial.print("Velocidad: ");
  Serial.println(velocidad);
  if(velocidad == 0){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
  }else if(velocidad == 200){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    analogWrite(mot_der1,velocidad);
    analogWrite(mot_der2,0);
  }
  analogWrite(mot_der1,velocidad);
  analogWrite(mot_der2,0);
  analogWrite(mot_izq1,0);
  analogWrite(mot_izq2,0);
  delay(1000);
}
