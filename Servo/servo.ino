#include <Servo.h> // Incluimos la biblioteca Servo

Servo servo_1;  // Definimos los servos que vamos a utilizar

int potenciometro_1 = 0;  // Pin usado para conectar el potenciómeto
int valor_potenciometro_1;    // Esta variable define la posición del servo

void setup() {
servo_1.attach(9);  // Difinimos el pines de señal para el servo
}

void loop() {
  
valor_potenciometro_1 = analogRead(potenciometro_1);
// leemose valor del potenciometro (valor entre 0 y 1023)

valor_potenciometro_1 = map(valor_potenciometro_1, 0, 1023, 0, 180);
// valor proporcional a la escala del servomotor (valor entre 0 y 180)

servo_1.write(valor_potenciometro_1);

delay(10);
// Esperamos para reiniciar el bucle
}
