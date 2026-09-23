const int pinLED = 2;
const int pinButton = 4;
bool buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  buttonState = !digitalRead(pinButton);

  digitalWrite(pinLED, buttonState);
}
