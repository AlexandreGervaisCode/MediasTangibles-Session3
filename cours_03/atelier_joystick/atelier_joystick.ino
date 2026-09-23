// Pins
const int pinJoyX = 15;
const int pinJoyY = 4;
const int pinButton = 5;

const int pinRed = 13;
const int pinBlue = 14;

// Valeurs joystick
int joyX;
int joyY;
bool joyBtn;
bool ledState = true;
bool prev_buttonState = true;

// Valeurs couleurs
int lightRed;
int lightBlue;
int lightIntensity;
int currentColor;

void setup() {
  // Met en mode Output les lumières RGB
  pinMode(pinRed, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  // Pour le Joystick
  Serial.begin(115200);
}

void loop() {
  // Lit les valeurs afin des attribuer
  joyX = analogRead(pinJoyX);
  joyY = analogRead(pinJoyY);
  joyBtn = digitalRead(pinButton);

  // Remap le joystick Y afin d'avoir un registre qui affecte l'intensité
  lightIntensity = map(joyY, 0, 4095, 0, 100);

  // Remap le joystick X afin d'avoir un registre qui affecte la couleur
  currentColor = map(joyX, 0, 4095, 0, 255);

  // Check la valeur du bouton
  joyBtn = digitalRead(pinButton);

  // Sert a Toggle le On Off
  if (joyBtn == false && prev_buttonState == true) 
  {
    ledState = !ledState;
    delay(100);
  }
  prev_buttonState = joyBtn;

  // Détermine la couleur selon la valeur X du Joystick
  lightRed = 255-currentColor;
  lightBlue = currentColor;

  // Affiche les couleurs (remap le light et intensity pour avoir le contole total)
  analogWrite(pinRed, map(lightRed*lightIntensity, 0, 25500, 0, 255)*ledState);
  analogWrite(pinBlue, map(lightBlue*lightIntensity, 0, 25500, 0, 255)*ledState);

  // Évite de overloader le serial monitor
  delay(20);
}
