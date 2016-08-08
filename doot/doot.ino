#include <Servo.h>

//Servo servoElbow;
Servo servoWrist;
Servo servoLWh;
Servo servoRWh;
int LEDPIN = 4;

void pause() {
  servoRWh.writeMicroseconds(1500);
  servoLWh.writeMicroseconds(1500);
  delay(1000);
}

void stopPen(int secs) {
  servoWrist.writeMicroseconds(1500);
  delay(secs);
}


void penup() {
  servoWrist.writeMicroseconds(1300);
  delay(600);
}

void pendown() {
  servoWrist.writeMicroseconds(1700);
  delay(600);
}

void turnRight() {
  servoRWh.writeMicroseconds(2000); //right
  servoLWh.writeMicroseconds(1700);
  delay(800);
  pause();
  delay(1000);
}
void turnLeft() {
  servoLWh.writeMicroseconds(1300); //left
  //servoRWh.writeMicroseconds(1200); //right
  delay(800);
  pause();
}
void turnRight_2() {
  servoRWh.writeMicroseconds(2000); //right
  servoLWh.writeMicroseconds(1700);
  delay(3000);
  pause();
  
}
void forward(int secs) {
  servoRWh.writeMicroseconds(1300);
  servoLWh.writeMicroseconds(1700);
  delay(secs);
}

void backward(int secs) {
  servoRWh.writeMicroseconds(1700);
  servoLWh.writeMicroseconds(1300);
  delay(secs);
}

void drawSquare() {
  for (int i = 0; i < 4; i ++) {
    //penup();
    stopPen(1780);
    turnRight();
    pause();
    pendown();
    stopPen(1500);
    forward(1500);
    pause();
  }
}
void circle() {
  for (int i = 0; i < 4; i++) {
    turnLeft();
  }
  
}
void harry() {
  for (int i = 0; i < 5; i++) {
    circle();
    forward(1000);
  }
}
void balloon() {
  circle();
  delay(1000);
  pause();
  delay(1000);
  backward(800);
}

void loopdeloop(int secs) {
  for (int i = 0; i < 2; i++) {
    circle();
    forward(1000);
  }
}

void triangle() {
  for (int i = 0; i < 3; i++) {
    turnRight_2();
    pause();
    forward(500);
    pause();
  }
}


void fan(int secs) {
  for (int i = 0; i < 15 ; i++) {
    //pendown();
    //stopPen(1050);
    forward(250);
    turnRight();
    //penup();
    //stopPen(500);
    delay(500);
    pause();
  }
}

long randNumber;

void setup() {
  // servoElbow.attach(13);
  servoWrist.attach(11);
  servoLWh.attach(13);
  servoRWh.attach(12);
  pinMode(LEDPIN, OUTPUT);
}


void loop() {

    /*pendown();
    stopPen(5600);
    circle();
    penup();
    stopPen(500);
    delay(500);

    pendown();
    stopPen(6600);
    balloon();
    penup();
    stopPen(500);
    delay(500);

    pendown();
    stopPen(6600);
    fan(1000);
    penup();
    stopPen(500);
    delay(500);
 
    pendown();
    stopPen(6600);
    harry();
    penup();
    stopPen(500);
    delay(500);*/
  
  
  /*balloon();
    penup();
    stopPen(1000);*/

  /*servoLWh.writeMicroseconds(1500);
    delay(1000);
    servoLWh.writeMicroseconds(1300);
    delay(100);
    servoLWh.writeMicroseconds(1700);
    delay(1000);*/

  /*pendown();      //draws a circle. set marker to left position
    stopPen(10680); */
    circle();
    digitalWrite(LEDPIN, HIGH);
    delay(500);
   /* penup();
    forward(100);
    pause();
    delay(1000);*/
    
 /* randNumber = random(4);
  Serial.print(randNumber);

  if (randNumber == 0) {
    pendown();
    stopPen(5600);
    circle();
    penup();
    stopPen(500);
    delay(500);
  }
  else if (randNumber == 1) {
    pendown();
    stopPen(6600);
    balloon();
    penup();
    stopPen(500);
    delay(500);
  }
  else if (randNumber == 2) {
    fan(1000);
    penup();
    stopPen(500);
    delay(500);
  }
  else if (randNumber == 3) {
    pendown();
    stopPen(6600);
    harry();
    stopPen(500);
    delay(500);
  }*/

}

