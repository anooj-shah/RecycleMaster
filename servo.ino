#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
int analogpin = 8;
char userInput;

int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;  

void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }  
    pinMode(inputPin, INPUT);
}

void loop() {
  if(Serial.available() > 0) {
    userInput = Serial.read();
    if(userInput == 'g') {
      for (pos = 90; pos <= 180; pos += 1) { // goes from 90 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
    if(userInput == 'h') {
     for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 90 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    }
    if(userInput == 'i') {
      for (pos = 90; pos >= 0; pos -= 1) { 
    // in steps of 1 degree
    myservo.write(pos);             
    delay(15);                       
  }
    }
    if(userInput == 'j') {
     for (pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
    }
    
    
    if(userInput == 'a') {
      val = digitalRead(inputPin);  // read input value
      if (val == HIGH) {            // check if the input is HIGH
         if (pirState == LOW) {
        // we have just turned on
        Serial.println("Motion detected!");
        // We only want to print on the output change, not state
        pirState = HIGH;
        }
      } else {
        if (pirState == HIGH){
          // we have just turned of
          Serial.println("Motion ended!");
          // We only want to print on the output change, not state
          pirState = LOW;
        }
      }
    }
  }
}
