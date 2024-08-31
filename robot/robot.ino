// #include <AFMotor.h> 
#include <NewPing.h>  
#include <Servo.h>  

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
// AF_DCMotor Motor1(1,MOTOR12_1KHZ);
// AF_DCMotor Motor2(2,MOTOR12_1KHZ);
// AF_DCMotor Motor3(3,MOTOR34_1KHZ);
// AF_DCMotor Motor4(4,MOTOR34_1KHZ);

// Servo Motor 
Servo myservo;
int pos = 0;

// SERVO MOTOR DOES NOT WORK (TODO: FIGURE IT OUT OR REMOVE)

void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  pinMode(LEFT_INFRA, INPUT); // left infrared sensor
  pinMode(RIGHT_INFRA, INPUT); // right infrared sensor
  {
  for(pos = 90; pos <= 180; pos += 1){    
    myservo.write(pos);                   
    delay(15);                            
    } 
  for(pos = 180; pos >= 0; pos-= 1) {     
    myservo.write(pos);                   
    delay(15);                            
    }
  for(pos = 0; pos<=90; pos += 1) {       
    myservo.write(pos);                   
    delay(15);                            
    }
  }
}

void loop() {   
  // front_dst = front_sonar.ping_cm();
  // Serial.print("Front dst: ");
  // Serial.println(front_dst);
  // left_dst = digitalRead(LEFT_INFRA);
  // right_dst = digitalRead(RIGHT_INFRA);
  // Serial.print("Left: ");
  // Serial.println(left_dst);
  // Serial.print("Right: ");
  // Serial.println(right_dst);

  // delay(100);
  // // TODO: Increase speed (testing for now)
  // Motor1.setSpeed(130);  
  // Motor1.run(FORWARD);   
  // Motor2.setSpeed(130);  
  // Motor2.run(FORWARD);  
  // Motor3.setSpeed(130); 
  // Motor3.run(FORWARD);  
  // Motor4.setSpeed(130); 
  // Motor4.run(FORWARD); 


}

// When object detected (infrared reading) : 0
