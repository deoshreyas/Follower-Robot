#include <AFMotor.h> 
#include <NewPing.h>  

// Define sensor constants 
unsigned int front_dst = 0;
unsigned int left_dst = 0;
unsigned int right_dst = 0;
#define LEFT_INFRA A5
#define RIGHT_INFRA A4 
#define TRIGGER_PIN A0 
#define ECHO_PIN A1    
#define MAX_DISTANCE 200

NewPing front_sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Create motor objects
AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

void setup() {
  pinMode(LEFT_INFRA, INPUT); // left infrared sensor
  pinMode(RIGHT_INFRA, INPUT); // right infrared sensor
}

void loop() {   
  front_dst = front_sonar.ping_cm();
  left_dst = digitalRead(LEFT_INFRA);
  right_dst = digitalRead(RIGHT_INFRA);

  delay(50);

  if (front_dst>1 && front_dst<15) { // If object in front, go forward
    Motor1.setSpeed(200);  
    Motor1.run(BACKWARD);   
    Motor2.setSpeed(200);  
    Motor2.run(BACKWARD);  
    Motor3.setSpeed(200); 
    Motor3.run(BACKWARD);  
    Motor4.setSpeed(200); 
    Motor4.run(BACKWARD); 
  } else if (right_dst==0 && left_dst==1) { // If object on the right, turn right
    Motor1.setSpeed(200);  
    Motor1.run(BACKWARD);   
    Motor2.setSpeed(200);  
    Motor2.run(BACKWARD);  
    Motor3.setSpeed(200); 
    Motor3.run(FORWARD);  
    Motor4.setSpeed(200); 
    Motor4.run(FORWARD); 
  } else if (left_dst==0 && right_dst==1) { // If object on the left, turn left
    Motor1.setSpeed(200);  
    Motor1.run(FORWARD);   
    Motor2.setSpeed(200);  
    Motor2.run(FORWARD);  
    Motor3.setSpeed(200); 
    Motor3.run(BACKWARD);  
    Motor4.setSpeed(200); 
    Motor4.run(BACKWARD); 
  } else if (front_dst > 15) { // If none then stop
    Motor1.setSpeed(0);    
    Motor1.run(RELEASE);   
    Motor2.setSpeed(0);    
    Motor2.run(RELEASE);   
    Motor3.setSpeed(0);    
    Motor3.run(RELEASE);   
    Motor4.setSpeed(0);    
    Motor4.run(RELEASE);   
  }
}
