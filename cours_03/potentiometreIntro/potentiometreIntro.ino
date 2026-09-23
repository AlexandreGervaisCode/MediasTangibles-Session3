const int pinCapteur = 4;
const int pinLED = 2;

int valeurCapteur;
int valeurLED;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valeurCapteur = analogRead(pinCapteur);
  Serial.println(valeurCapteur);

  // 0 = valeur minimale, 4095 = valeur maximale
  valeurCapteur = constrain(valeurCapteur, 0, 4095);
  valeurLED = map(valeurCapteur, 0, 4095, 0, 255); // Remap de 0 à 255
  analogWrite(pinLED, valeurLED);
  delay(20);
}
