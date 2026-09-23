const int pinLED = 2;
const int pinButton = 4;
bool buttonState = 0;
bool ledState = 0;
bool prev_buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT);
  digitalWrite(pinLED, ledState);
}

void loop() {
  buttonState = digitalRead(pinButton);

  if (buttonState == HIGH && prev_buttonState == LOW) 
  {
    ledState = !ledState;
    digitalWrite(pinLED, ledState);
    delay(100);
  }
  prev_buttonState = buttonState;
}
