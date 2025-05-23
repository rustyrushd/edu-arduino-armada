// Adding flash function for yellow lights after red

const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;
const int PED_RED = 10;
const int PED_GREEN = 9;

void lightSequence() {
  digitalWrite(PED_RED, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(4000);
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

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
}

void loop(){
  lightSequence();
}
