/*
  This program simulates a simplified traffic light system with 3 LEDs for cars,
  2 LEDs for pedestrians, a pedestrian switch to change light sequence and a 
  buzzer that plays a tune while pedestrians are allowed to cross.
  
  Initially both car GREEN and PED_RED are ON. 
  Once the pedestrian button is pressed, the car LEDs cycle in 4 second intervals
  until the pedestrian cycle when the buzzer starts. After the pedestrian cycle 
  is over, the lights cycle back to their initial condition.
*/

const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;
const int PED_RED = 10;
const int PED_GREEN = 9;
const int SW = 2;

int buttonState = 0;

void lightSequence() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(4000);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  digitalWrite(PED_RED, LOW);
  digitalWrite(PED_GREEN, HIGH);
  delay(4000);
  digitalWrite(PED_GREEN, LOW);
  digitalWrite(PED_RED, HIGH);
  digitalWrite(RED, LOW);
  flash(YELLOW);
}

void flash(int LED) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED, HIGH);
  	delay(250);
  	digitalWrite(LED, LOW);
  	delay(250);
  }
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop(){
  buttonState = digitalRead(SW);

  if (buttonState == HIGH) {
    digitalWrite(PED_RED, HIGH);
    digitalWrite(GREEN, HIGH);
  } 
  else {
    lightSequence();
  }
}