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
const int BZR = 8;

#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

int buttonState = 0;

void lightSequence() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(4000);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  digitalWrite(PED_RED, LOW);
  digitalWrite(PED_GREEN, HIGH);
  buzzer();
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

void buzzer() {
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };
  int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BZR, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 2.0;
    delay(pauseBetweenNotes);
    noTone(BZR);
  }
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(BZR, OUTPUT);
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
