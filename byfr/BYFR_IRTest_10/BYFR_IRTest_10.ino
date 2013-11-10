#include <IRremote.h>       // Include IRremote library
                            // Put in sketchbook /libraries folder

#define  showCode  false    // Test mode
                            // false=match against number buttons
                            // true=show raw code

const int RECV_PIN = 5;     // Receiver input pin on D5
IRrecv irrecv(RECV_PIN);    // Define IR recever object
decode_results results;

void setup() {
  pinMode(6, OUTPUT);       // IR power, ground pins
  pinMode(7, OUTPUT);
  digitalWrite(6, LOW);     // IR ground
  digitalWrite(7, HIGH);    // IR power
  irrecv.enableIRIn();      // Start the receiver
  Serial.begin(9600);
}

void loop() {

  if (irrecv.decode(&results)) {  // If valid value was receiver
    if(showCode) {                // If showCode=trtue 
      Serial.print("0x");
      Serial.println(results.value, HEX);  // Show raw hex value of code
    } else {                      // else showCode=false
      switch (results.value) {    // Match button against Sony codes
        case 0x10:
          Serial.println("1");
          break;
        case 0x810:
          Serial.println("2");
          break;
        case 0x410:
          Serial.println("3");
          break;
        case 0xC10:
          Serial.println("4");
          break;
        case 0x210:
          Serial.println("5");
          break;
        case 0xA10:
          Serial.println("6");
          break;
       case 0x610:
          Serial.println("7"); 
          break;
        case 0xE10:
          Serial.println("8");
          break;
        case 0x110:
          Serial.println("9");
          break;
      }        
    }
    irrecv.resume();                // Receive the next value
    delay(10);                      // 10ms delay
  }

}
