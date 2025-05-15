// buzzer plays if switch is pressed

const int SW = 2;
const int BZR = 8;

int buttonState = 0;

#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

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
  pinMode(SW, INPUT_PULLUP);
  pinMode(BZR, OUTPUT);
}

void loop() {
  buttonState = digitalRead(SW);
  if (buttonState == HIGH) {
    // do nothing
  } 
  else {
    buzzer();
  } 
}
