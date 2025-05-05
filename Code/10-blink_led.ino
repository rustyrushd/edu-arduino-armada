/*
  This program continuously blinks an LED connected to pin 13, which is also 
  attached to the builtin LED of the Arduino. Both the external LED connected 
  to pin 13 and the built in LED should blink in sync. 
*/

const int RED = 13; // this is a better way to label pins

void setup() {
  pinMode(RED, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
  delay(1000);
}