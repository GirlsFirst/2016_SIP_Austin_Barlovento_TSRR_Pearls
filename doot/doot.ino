#include <SoftwareSerial.h>     //Bluetooth library
#include <Servo.h>              //Servo library


int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

Servo servoTest;

//Servo servoElbow;
Servo servoWrist;
Servo servoLWh;
Servo servoRWh;

int LEDPIN = 4;

void pause() {      //Stops & resets wheels
  servoRWh.writeMicroseconds(1500);
  servoLWh.writeMicroseconds(1500);
  delay(1000);
}

void stopPen(int secs) {   //Pen stays in position for x amount of time
  servoWrist.writeMicroseconds(1500);
  delay(secs);
}


void penup() {      //Pen up
  servoWrist.writeMicroseconds(1300);
  delay(600);
}

void pendown() {    //Pen down
  servoWrist.writeMicroseconds(1700);
  delay(600);
}

void turnRight() {  //Turn right
  servoRWh.writeMicroseconds(2000); //right
  servoLWh.writeMicroseconds(1700);
  delay(800);
  pause();
  delay(1000);
}
void turnLeft() {   //Turn left
  servoLWh.writeMicroseconds(1300); //left
  //servoRWh.writeMicroseconds(1200); //right
  delay(800);
  pause();
}
void turnRight_2() {    //Left turn for triangle
  servoRWh.writeMicroseconds(2000); //right
  servoLWh.writeMicroseconds(1700);
  delay(3000);
  pause();

}
void forward(int secs) {    //forward x amount of time
  servoRWh.writeMicroseconds(1300);
  servoLWh.writeMicroseconds(1700);
  delay(secs);
}

void backward(int secs) {   //backward x amount of time
  servoRWh.writeMicroseconds(1700);
  servoLWh.writeMicroseconds(1300);
  delay(secs);
}

void drawSquare() {     //draw a square
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
void circle() {     //draw a circle
  for (int i = 0; i < 4; i++) {
    turnLeft();
  }

}
void harry() {      //draw glasses
  for (int i = 0; i < 5; i++) {
    circle();
    forward(1000);
  }
}
void balloon() {    //draw a balloon
  circle();
  delay(1000);
  pause();
  delay(1000);
  backward(800);
}

void loopdeloop(int secs) {   //draw a loop de loop
  for (int i = 0; i < 2; i++) {
    circle();
    forward(1000);
  }
}

void triangle() {     //draw a triangle
  for (int i = 0; i < 3; i++) {
    turnRight_2();
    pause();
    forward(500);
    pause();
  }
}


void fan(int secs) {    //draw a fan shape thing
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

long randNumber;    //Set up random

void setup() {

  Serial.begin(9600);  // Begin the serial monitor at 9600bps

  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  delay(100);               // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);    // Start bluetooth serial at 9600

  servoTest.attach(13);
  servoWrist.attach(11);
  servoLWh.attach(13);
  servoRWh.attach(12);
  pinMode(LEDPIN, OUTPUT);
}


void loop() {
  /*servoRWh.writeMicroseconds(1500);
  servoLWh.writeMicroseconds(1500);*/

  if (bluetooth.available())      // If the bluetooth sent any characters
    {
     //pendown();
     //stopPen(5600);
     circle();
    // penup();
     //stopPen(500);
     delay(500);

     //servoTest.writeMicroseconds(1700);

     // Send any characters the bluetooth prints to the serial monitor
     Serial.print((char)bluetooth.read());
    }
    if (Serial.available())       // If stuff was typed in the serial monitor
    {

     // Send any characters the Serial monitor prints to the bluetooth
     bluetooth.print((char)Serial.read());
    }
    // and loop forever and ever!

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
  //circle();
  //digitalWrite(LEDPIN, HIGH);
  //delay(500);
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

