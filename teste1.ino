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
const unsigned long temp = 1000;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  garra.attach(pinServ1);
  base.attach(pinServ2);
  motorLeft.attach(pinServ3);
  motorRight.attach(pinServ4);
  
}

void loop(){

  // Posição Inicial
  move(garra, 20);
  move(base, 92);
  move(motorLeft, 90);
  move(motorRight, 100);

  // Movimento 
//  move(motorLeft, 110);
//  move(motorRight, 80);


  // tempo de espera para recomeçar
  delay(100);

}

void move (Servo servo, int angulo) {
  servo.write(angulo);
  delay(temp);
}
