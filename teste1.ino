// inclui bibilioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinServ1 2
#define pinServ2 3
#define pinServ3 4
#define pinServ4 5

// nomeia os servos
Servo garra,base,motorLeft,motorRight;

// cria as variavies dos angulos de cada motor
int motor1,motor2,motor3,motor4;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 5000;
const unsigned long temp = 50;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  garra.attach(pinServ1);
  base.attach(pinServ2);
  motorLeft.attach(pinServ3);
  motorRight.attach(pinServ4);

  // Posição Inicial
  garra.write(20);
  base.write(92);
  motorLeft.write(120);
  motorRight.write(90);
}

void loop(){    
  // Posição Inicial
  int angulo = 92;
  while(true) {
    Serial.print(angulo);
    Serial.print("\n");
    base.write(angulo);
    angulo --;
    if(angulo == 25) {
      break;
    }
    delay(temp);
  }

  // Posição Final 
  angulo = 25;
  while(true) {
    Serial.print(angulo);
    Serial.print("\n");
    base.write(angulo);
    angulo ++;
    if(angulo == 92) {
      break;
    }
    delay(temp);
  }
}