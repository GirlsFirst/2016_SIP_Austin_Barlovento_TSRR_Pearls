#include <Servo.h>

//Servo servoElbow;
Servo servoWrist;
Servo servoLWh;
Servo servoRWh;

void penup(int secs){
  servoWrist.writeMicroseconds(1300);
  delay(secs);
}

void pendown(int secs){
  servoWrist.writeMicroseconds(1700);
  delay(secs);
}

 void turnRight(int secs){
  servoRWh.writeMicroseconds(2000); //right
  servoLWh.writeMicroseconds(1700);
  delay(secs);
   
}

void turnLeft(int secs){ 
  servoLWh.writeMicroseconds(1300); //left
  servoRWh.writeMicroseconds(1200); //right
  delay(secs);
}

void forward(int secs){
  servoRWh.writeMicroseconds(1300); 
  servoLWh.writeMicroseconds(1700); 
  delay(secs);
}

void backward(int secs){
  servoRWh.writeMicroseconds(1700); 
  servoLWh.writeMicroseconds(1300); 
  delay(secs);
}

void drawSquare(){
  for (int i = 0; i < 4; i ++){
    forward(1500);
    turnRight(1000);
  }
}
void circle(){
  for (int i = 0; i < 36; i++){
     // forward(250);
      turnRight(500);
   }
}
void fan(){
  for (int i = 0; i < 36; i++){
      forward(250);
      turnRight(500);
   }
}
void setup() {
 // servoElbow.attach(13);
  servoWrist.attach(12);
  servoLWh.attach(11);
  servoRWh.attach(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  //pendown(100);
  //drawSquare();
  circle();

  
}

