/*
  Change ON delays to 4 seconds to reprensent a simplified traffic light.
  The OFF delays are kept at 1 second and commented out to test the difference. 
*/

const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);
  delay(4000);
  digitalWrite(RED, LOW);
  //delay(1000);
  digitalWrite(YELLOW, HIGH);
  delay(4000);
  digitalWrite(YELLOW, LOW);
  //delay(1000);
  digitalWrite(GREEN, HIGH);
  delay(4000);
  digitalWrite(GREEN, LOW);
  //delay(1000);
  digitalWrite(YELLOW, HIGH);
  delay(4000);
  digitalWrite(YELLOW, LOW);
  //delay(1000);
}
