# En arduino hay 3 tipos de motores

### 1. Motores DC: 

Giran y giran, estos q compramos son motores q giran y giran

### 2. Servomotores

Giran y giran, pero con un ángulo de giro limitado, por grados. 

### 3. Paso a paso

Giran y giran, pero en pasos, por lo q se puede controlar la velocidad de giro. 
Si es de 4 pasos y da 2 pasos gira la mitad.
Si hay de 360 pasos cada paso va ser un grado.


Los motores tienen su torque, revoluciones por minuto, + rapido cuestan mas
Torque: mientras mas torque mas caro, y menos revoluciones por minuto y viceversa. 

Ejemplo: 
Motor de 12v 0.5A 60RPM 4Kg.cm 
Motor de 12v 0.5A 60RPM 1Kg.cm
 
Componentes:
Pila rojo es positivo y negro negativo se conecta al cuadrado pequeño driver positivo al 12 y negativo a gnd

codigo

variables 

int mot_der1 = 10;
int mot_der2 = 9;

int mot_izq2 = 6;
int mot_izq2 = 5;


