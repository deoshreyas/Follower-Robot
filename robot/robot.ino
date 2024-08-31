#include <AFMotor.h>        

//create motor objects
AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

void setup() {
  Serial.begin(9600);
}

void loop() {                             
  delay(100);
  // TODO: Increase speed (testing for now)
  Motor1.setSpeed(130);  
  Motor1.run(FORWARD);   
  Motor2.setSpeed(130);  
  Motor2.run(FORWARD);  
  Motor3.setSpeed(130); 
  Motor3.run(FORWARD);  
  Motor4.setSpeed(130); 
  Motor4.run(FORWARD);   
}