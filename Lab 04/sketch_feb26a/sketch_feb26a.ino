const int switchPin = 2; // named constant for the switch pin
const int switchPin2 = 6;
unsigned long previousTime = 0; // store the last time an LED was updated
int switchState = 0; // the current switch state
int prevSwitchState = 0; // the previous switch state
int led = 3; // a variable to refer to the LEDs
int interval = 5000; // interval at which to light the next LED (5 s)
void setup() {
  // set the LED pins as outputs and turn LEDs off
  for (int i = 3; i < 6; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  // set the switch pin as input
  pinMode(switchPin, INPUT);
  pinMode(switchPin2, INPUT);
}
// TASK 1
void loop() {
  // store the time since the Arduino started running in a variable
  unsigned long currentTime = millis();
  // compare the current time to the previous time an LED turned on
  // if it is greater than your interval, turn next LED on
  if (currentTime - previousTime > interval && led < 6) {
    // save the current time as the last time you changed an LED
    previousTime = currentTime;
    // Turn the LED on
    digitalWrite(led, HIGH);
    // increment the led variable
    // in 5 s the next LED will light up
    led++;
  }
  // read the switch value
  switchState = digitalRead(switchPin2);
  // if the switch has changed
  if (switchState == LOW) {
    // turn all the LEDs low
    for (int i = 3; i < 6; i++) {
      digitalWrite(i, LOW);
    }
    // reset the LED variable to the first one
    led = 3;
    //reset the timer
    previousTime = currentTime;
  }
  // set the previous switch state to the current state
  prevSwitchState = switchState;
}
// TASK 2
//void loop() {
//  if (led < 6) {
//    // wait for interval
//    delay(interval);
//    // Turn the LED on
//    digitalWrite(led, HIGH);
//    // increment the led variable
//    // in 5 s the next LED will light up
//    led++;
//  }
//  // read the switch value
//  switchState = digitalRead(switchPin);
//  // if the switch has changed
//  if (switchState != prevSwitchState) {
//    // turn all the LEDs low
//    for (int i = 3; i < 6; i++) {
//      digitalWrite(i, LOW);
//    }
//    // reset the LED variable to the first one
//    led = 3;
//  }
//  // set the previous switch state to the current state
//  prevSwitchState = switchState;
//}

