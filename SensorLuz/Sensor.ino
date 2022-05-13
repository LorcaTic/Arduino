int sensorReading;

void setup() {
 Serial.begin(9600);
 pinMode(6,OUTPUT); // 
}

void loop() {
  
 sensorReading=analogRead(0);
  
 if (sensorReading<700)
 {
 digitalWrite(6,HIGH);
 }
 else digitalWrite(6,LOW);
 Serial.println(sensorReading); 
 delay(1000);
}
