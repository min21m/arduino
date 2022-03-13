/*
  Blink without Delay
  None of this code inside the loop is waiting for anything.
  Logic -- interval Line 37: Code inside that only runs (once every time interval happens)
  Moore Machine -- We are reading outputs back first, before we change our outputs. One cycle: Read our output as input.
  
*/

// constants won't change. Used here to set a pin number:
const int ledpin1 = 7;// the number of the LED pin
const int ledpin2 = 6;
const int ledpin3 = 5;
 
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 250;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

//We want to test all three conditions every single time 
//fastest code is the code that doesn't run 
//This is a demo of state machine 
   // TOGGEL LED1
   if (digitalRead(ledpin2) == HIGH && digitalRead(ledpin3) == HIGH)
   {
      digitalWrite(ledpin1,!digitalRead(ledpin1));
   }
  
   // TOGGEL LED2
   if (digitalRead(ledpin1) == HIGH && digitalRead(ledpin3) == HIGH)
   {   digitalWrite(ledpin2,!digitalRead(ledpin2));
   }
   
   // TOGGEL LED3
   
   if (digitalRead(ledpin1) == HIGH && digitalRead(ledpin2) == HIGH)
   {   digitalWrite(ledpin3,!digitalRead(ledpin3));
   }
   

  }
}
