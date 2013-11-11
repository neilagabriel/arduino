/*
  Be sure to move the IRremote folder contained with this sketch to the
  Arduino sketchbook libraries folder. See the readme.txt file for more
  information.
  
  Program your universal remote for a Sony TV code. Try different codes until
  you get one that works.

*/

#include <IRremote.h>
#include <Servo.h> 
#include "pitches.h"

Servo servoLeft;              // Define left servo
Servo servoRight;             // Define right servo

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;
volatile int pbLeft = LOW;
volatile int pbRight = LOW;
boolean started = false;

void setup() {
  // Set pin modes for switches
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);     // Serves as ground connection
  
  pinMode(6, OUTPUT);       // IR power, ground pins
  pinMode(7, OUTPUT);
  digitalWrite(6, LOW);     // IR ground
  digitalWrite(7, HIGH);    // IR power
  
  pinMode(12, OUTPUT);      // Ground for speaker
  digitalWrite(12, LOW);
  
  servoLeft.attach(10);    // Set left servo to digital pin 10
  servoRight.attach(9);    // Set right servo to digital pin 9
  irrecv.enableIRIn();     // Start the receiver
  
  Serial.begin(9600);
    
  // Set up interrupts
  attachInterrupt(0, hitRight, FALLING);
  attachInterrupt(1, hitLeft, FALLING);
  
  started = true;
}

void loop() {
  
  if (pbLeft == HIGH) {           // If left bumper hit
    int tones[] = {NOTE_C4, NOTE_B3, NOTE_C4};
    int toneDurations[] = {4,4,4};
    reverse();
    makeTone(tones, toneDurations, sizeof(tones)/sizeof(int));
    delay(500); 
    spinRight();
    delay(1500);
    forward();
    pbLeft = LOW;
    Serial.println("pbLeft");
  }
  
  if (pbRight == HIGH) {          // If right bumper hit
    int tones[] = {NOTE_D6, NOTE_C3};
    int toneDurations[] = {4,4};
    reverse();
    makeTone(tones, toneDurations, sizeof(tones)/sizeof(int));
    delay(500); 
    spinLeft();
    delay(1500);
    forward();
    pbRight = LOW;
    Serial.println("pbRight");  
  }
  
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0x10:
        Serial.println("1");     // Turn left forward
        turnLeftFwd();
        break;
      case 0x810:
        Serial.println("2");     // Forward
        forward();
        break;
      case 0x410:
        Serial.println("3");     // Turn right forward
        turnRightFwd();
        break;
      case 0xC10:
        Serial.println("4");    // Spin left
        spinLeft();
        break;
      case 0x210:
        Serial.println("5");    // Stop
        stopRobot();
        break;
      case 0xA10:
        Serial.println("6");    // Spin right
        spinRight();
        break;
     case 0x610:
        Serial.println("7");    // Turn left reverse
        turnLeftRev();
        break;
      case 0xE10:
        Serial.println("8");    // Reverse
        reverse();
        break;
      case 0x110:
        Serial.println("9");    // Turn right reverse
        turnRightRev();
        break;
    }        
    //Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    delay(2);
  }
}

void makeTone(int tones[], int toneDurations[], int length) {
  // Iterate notes of tune
  for (int thisNote = 0; thisNote < length; thisNote++) {

    //Calculate the note duration
    int toneDuration = 1000/toneDurations[thisNote];
    tone(13, tones[thisNote],toneDuration);

    //Add slight pause between notes
    int pauseBetweenNotes = toneDuration * 1.30;
    delay(toneDuration * 1.30);
    noTone(13);                      // Stop tone
  }
  irrecv.enableIRIn();               // Restart receiver
  return;
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
void turnLeftFwd() {
  servoLeft.write(90);
  servoRight.write(0);
}
void turnRightFwd() {
  servoLeft.write(180);
  servoRight.write(90);
}
void turnLeftRev() {
  servoLeft.write(90);
  servoRight.write(180);
}
void turnRightRev() {
  servoLeft.write(0);
  servoRight.write(90);
}
void stopRobot() {
  servoLeft.write(90);
  servoRight.write(90);
}

// Interrupt handlers
void hitLeft() {
  if (started)
    pbLeft = HIGH;
}
void hitRight() {
  if (started) 
    pbRight = HIGH;
}
