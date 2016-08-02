#include <Servo.h>

Servo servoElbow;
Servo servoWrist;


void penup(){
  servo.writeMicroseconds();
}

void pendown(){
  servo.writeMicroseconds();
}

void elbowRight(){
  servoElbow.writeMicroseconds(1300); //right
}

void elbowLeft(){ 
  servoElbow.writeMicroseconds(1700); //left

}

void drawSquare(){
}


void setup() {
  // put your setup code here, to run once:
  servoElbow.attach(13);
  servoWrist.attach(12);

}

void loop() {
  // put your main code here, to run repeatedly:
  elbowRight();
}
