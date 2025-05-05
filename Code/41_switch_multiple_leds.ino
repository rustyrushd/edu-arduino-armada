// pushbutton switch using internal pullup resistor to light multiple LEDs at
// the same time 

const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;
const int PED_RED = 10;
const int PED_GREEN = 9;
const int SW = 2;

int buttonState = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(SW);
  
  if (buttonState == HIGH) {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(PED_RED, LOW);
    digitalWrite(PED_GREEN, LOW);
  } 
  else {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(PED_RED, HIGH);
    digitalWrite(PED_GREEN, HIGH);
  } 
}