#define m1 8  //Right Motor MA1
#define m2 9  //Right Motor MA2
#define m3 10  //Left Motor MB1
#define m4 11 //Left Motor MB2
#define e1 12  //Right Motor Enable Pin EA
#define e2 13 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 2
#define ir2 3
#define ir3 4
#define ir4 5
#define ir5 6
#define ir6 A0
//*************************************************//

void setup() {
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
}

void loop() {
  //Reading Sensor Values
  
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor
  int clp = digitalRead(ir6);  //clp



Serial.print(s1);

Serial.print(s2);

Serial.print(s3);

Serial.print(s4);

Serial.println(s5);




  
  //if only middle sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1) && (clp == 0))
  {
    //going forward with full speed 
    Serial.println("MIDDLE");
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }
  
  //if only left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)&& (clp == 0))
  {
    //going right with full speed 
    Serial.println("iZ");
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1)&& (clp == 0))
  {
    Serial.println("iZ++");
    //going right with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)&& (clp == 0))
  {
    Serial.println("dE+");
    //going left with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)&& (clp == 0))
  {
    Serial.println("dE++");
    //going left with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1)&& (clp == 0))
  {
    //going left with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)&& (clp == 0))
  {
    //going right with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)&& (clp == 0))
  {
    //going right with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)&& (clp == 0))
  {
    //going left with full speed 
    analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

   if((clp == 1))
  {
    //stop
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
}

