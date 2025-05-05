/*
  A pushbutton switch using the internal Arduino pullup resistor to light an LED.
  
  When the pushbutton is not pressed or OFF, it's state is pulled HIGH and when 
  it is pressed or ON, it's state is LOW. 
  
  So if we want to turn the LED ON when the switch is pressed, we need add code 
  for when the button state is LOW.
*/

const int RED = 13;
const int SW = 2;

int buttonState = 0;

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop(){
  // read the state of the pushbutton value to check if pushbutton is pressed
  buttonState = digitalRead(SW);
  // if it isn't, the buttonState is HIGH, LED OFF
  if (buttonState == HIGH) {
    digitalWrite(RED, LOW);
  } 
  // if it is, the buttonState is LOW, LED ON
  else {
    digitalWrite(RED, HIGH);
  } 
}