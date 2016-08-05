#include <Servo.h>

//Servo servoElbow;
Servo servoWrist;
Servo servoLWh;
Servo servoRWh;

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
  servoRWh.writeMicroseconds(1200); //right
  delay(800);
  pause();
}

void turnRight_2() {
  servoRWh.writeMicroseconds(2000); //right
  servoLWh.writeMicroseconds(1700);
  delay(900);
  pause();
  delay(1000);
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
    penup();
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
  for (int i = 0; i < 6; i++) {
    turnRight();
  }
}
void harry(int secs) {
  for (int i = 0; i < 5; i++) {
    circle();
    forward(1000);
  }
}

void loopdeloop(int secs) {
  for (int i = 0; i < 2; i++) {
    circle();
    forward(1000);
  }
}

void triangle(){
  for (int i = 0; i < 3; i++) {
    turnRight_2();
    pause();
    forward(500);
    pause();
  }
}


void fan(int secs) {
  for (int i = 0; i < 15 ; i++) {
    pendown();
    stopPen(1050);
    forward(250);
    turnRight();
    penup();
    stopPen(500);
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

}

void loop() {
  //servoRWh.writeMicroseconds(1500);
  drawSquare();

  /*servoLWh.writeMicroseconds(1500);
  delay(1000);
  servoLWh.writeMicroseconds(1300);
  delay(100);
  servoLWh.writeMicroseconds(1700);
  delay(1000);*/

 //pause();
 //delay(1000);
 //forward(1000);
  //drawSquare();
  
  /*pendown();      //draws a circle. set marker to left position
  stopPen(10680);
  circle();
  penup();
  forward(100);
  pause();
  delay(1000);*/
 
 
  
  

  



  //loopdeloop(2000);
  
  //harry(1000);
  /*  pendown();
    stopPen(500);
    //triangle();
    penup();
    stopPen(1000);*/
  //drawSquare();

    /*pendown();
    stopPen(1000);
    delay(2000);
    penup();
    stopPen(1000);*/
    


   /* //circle();
    randNumber = random(3);
    Serial.print(randNumber);

    if (randNumber == 0) {
      circle(500);
      penup();
      stopPen(500);
      delay(500);
    }
    else if (randNumber == 1) {
      drawSquare();
      delay(500);
    }
    else if (randNumber == 2) {
      fan(1000);
      penup();
      stopPen(500);
      delay(500);
    }
  // turnRight();*/

}

