int brilo;
int potenciometro = 0;
int valor; //valor del potenciometro
int led = 3;
/*
analogRead : acepta un valor, el pin solo 1 parametro , de 0 a 1024
digitalRead : recibe 1 pin, recibe 1 valor no de 0 a 255, sino HIGT - LOW 
funcion map ()
map: recibe 5 parametros
*/
void setup() {
  // Pin analogico siempre son Inputs,
  pinMode(potenciometro, INPUT); // introducimos los lados
  pinMode(led, OUTPUT); // salida de luz de led
  Serial.begin(9600);
}

void loop() {
  // variable valor
  // valor = analogRead(potenciometro)/4; // brillo = valor*255/1023
  // brillo = valor*0.25;
  valor = analogRead(potenciometro);
  brilo = map(valor,0,1023,0,255);
  Serial.println(valor);
  // Serial.println(brillo); 
  delay(200);
  analogWrite(led,valor);
}
