#include <Servo.h>

//Servo servoElbow;
Servo servoWrist;
Servo servoLWh;
Servo servoRWh;

void restart(){
  servoRWh.writeMicroseconds(1500); 
  servoLWh.writeMicroseconds(1500);
}

void stopPen(int secs){
  servoWrist.writeMicroseconds(1500);
  delay(secs);
}

void penup(){
  servoWrist.writeMicroseconds(1300);
  delay(400);
}

void pendown(){
  servoWrist.writeMicroseconds(1700);
  delay(400);
}

 void turnRight(){
  servoRWh.writeMicroseconds(1700); //right
  servoLWh.writeMicroseconds(1600);
  delay(800);
  restart();
   
}

void turnLeft(){ 
  servoLWh.writeMicroseconds(1300); //left
  servoRWh.writeMicroseconds(1200); //right
  delay(800);
  restart();
  
}

void forward(int secs){
  servoRWh.writeMicroseconds(1300); 
  servoLWh.writeMicroseconds(1700); 
  delay(secs);
  restart();
}

void backward(int secs){
  servoRWh.writeMicroseconds(1700); 
  servoLWh.writeMicroseconds(1300); 
  delay(secs);
  restart();
}

void drawSquare(){
  for (int i = 0; i < 4; i ++){
    //penup();
    //stopPen(800);
    turnRight();
    pendown();
    stopPen(1500);
    forward(1500);
    //delay(500);
    restart();
    
    
  }
}
void circle(int secs){
  for (int i = 0; i < 10; i++){
    pendown();
    stopPen(8000);
    turnRight();
      
   }
}
void fan(int secs){
  for (int i = 0; i < 15; i++){
      pendown();
      stopPen(1050);
      forward(250);
      turnRight();
      restart();
      //penup();
   }
}

//int shapes[] = {0,1,2};
long randNumber;

void setup() {
 // servoElbow.attach(13);
  servoWrist.attach(12);
  servoLWh.attach(11);
  servoRWh.attach(10);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  servoLWh.writeMicroseconds(1500); //left
  servoRWh.writeMicroseconds(1500);
  delay(2000);
}

void loop() {
  /*pendown();
  stopPen(10000);
  penup();
  stopPen(5000);*/

  //penup();
  
/* randNumber = random(3);

  if (randNumber == 0){
    circle(500);
    penup();
    stopPen(500);
    delay(500);
    
  }
  else if (randNumber == 1){
    drawSquare();
    delay(500);
    
  }
  else if (randNumber == 2){
    fan(1000);
    penup();
    stopPen(500);
    delay(500);
  }
  Serial.println(randNumber); */
}

