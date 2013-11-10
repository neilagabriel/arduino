#include <Servo.h> 
Servo servoLeft;              // Define left servo
Servo servoRight;             // Define right servo

void setup() {
  servoLeft.attach(10);    // Set left servo to digital pin 10
  servoRight.attach(9);    // Set right servo to digital pin 9
}

void loop() {
  forward();
  delay(2000);
  reverse();
  delay(2000);
  spinRight();
  delay(2000);
  spinLeft();
  delay(2000);
}

// Motion routines for forward, reverse, turns, and stop
void forward() {
  servoLeft.write(180);
  servoRight.write(0);
}
void reverse() {
  servoLeft.write(0);
  servoRight.write(180);
}
void spinLeft() {
  servoLeft.write(0);
  servoRight.write(0);
}
void spinRight() {
  servoLeft.write(180);
  servoRight.write(180);
}
void stopRobot() {
  servoLeft.write(90);
  servoRight.write(90);
}

