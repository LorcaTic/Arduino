/* Controlar el ángulo de rotación con un potenciómetro. */

#include <Servo.h>  // librería para poder controlar el servo

Servo servoMotor;   // Crea un objeto servo llamado servoMotor

const int pinPotenc = 0;
const int pinServo = 2;
const int pulsoMin = 650;   // pulso para girar el servo a 0º
const int pulsoMax = 2550;  // pulso para girar el servo a 180º
int valor;
int angulo;


void setup() {
  Serial.begin(9600);
  servoMotor.attach(pinServo, pulsoMin, pulsoMax);
}


void loop() {
  valor = analogRead(pinPotenc);
  angulo = map(valor, 0, 1023, 0, 180);
  servoMotor.write(angulo);
  Serial.print("Angulo:  ");
  Serial.println(angulo);
  delay(20);
}
