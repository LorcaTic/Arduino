#include <Servo.h>  // librería para poder controlar el servo

Servo servoMotor;   // Crea un objeto servo llamado servoMotor

void setup(){ 
  Serial.begin(9600);
  // Asociamos el servo a la patilla 2 del Arduino
  servoMotor.attach(2);
  servoMotor.write(0); // Inicializamos al ángulo 0 el servomotor
}
 
void loop(){
  // giro de 0 a 180º
  for (int i = 0; i &lt;= 180; i++){
    servoMotor.write(i);
    Serial.print("Angulo:  ");
    Serial.println(i);
    delay(30);
  }
 // giro de 180 a 0º
  for (int i = 179; i &gt; 0; i--){
    servoMotor.write(i);
    Serial.print("Angulo:  ");
    Serial.println(i);
    delay(30);
  }
}
