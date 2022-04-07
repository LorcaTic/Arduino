#include <Servo.h>  // librería para poder controlar el servo

Servo servoMotor;   // Crea un objeto servo llamado servoMotor

void setup(){ 
  // Asociamos el servo a la patilla 2 del Arduino
  servoMotor.attach(2);
}
 
void loop(){
  // Desplazamos a la posición 0º
  servoMotor.write(0);
  delay(1000);  // Esperamos 1 segundo
  
  // Desplazamos a la posición 90º
  servoMotor.write(90);
  delay(1000);  // Esperamos 1 segundo
  
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  delay(1000);  // Esperamos 1 segundo
}
