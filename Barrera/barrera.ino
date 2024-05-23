#include <Servo.h>

#define BUTTON_PIN A0  // Pin analógico del módulo KY-009 conectado al botón
#define SERVO_PIN 9   // Pin del servo

bool aux = false;

Servo myservo;         // Crear un objeto Servo
int pos = 0;         // Variable para almacenar la posición del servo
int buttonState = 0; // Variable para almacenar el estado del botón
bool servoMoving = false; // Variable para verificar si el servo está en movimiento

void setup() {
  Serial.begin(9600); // Inicializar el monitor serie
  myservo.attach(SERVO_PIN); // Inicializar el servo en el pin especificado

  myservo.write(0);
}

void loop() {
  buttonState = analogRead(BUTTON_PIN); // Leer el estado del botón
  
  // Mostrar información de depuración en el monitor serie
  Serial.print("Button state: ");
  Serial.println(buttonState);

  // Verificar si el botón ha sido pulsado
  if (buttonState > 100 && aux == true)  {
    // Mover el servo a 90 grados si está en 0 grados
    moveBarrera();
    }
    // Mover el servo a 0 grados si está en 90 grados
    else if (buttonState < 100) {
      Serial.println("Servo moving to 0 degrees");
      Serial.println(aux);
      aux = true;
    
}
}

void moveBarrera () {
    int pos = 0 ;
    for (pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                      
  }

   aux = false;
}
