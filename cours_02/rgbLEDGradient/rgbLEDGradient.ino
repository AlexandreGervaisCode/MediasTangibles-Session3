// Associer chaque couleur avec une pin
int pinRed = 2;
int pinGreen = 4;
int pinBlue = 5;

void setup() {
  pinMode(pinRed, OUTPUT); // Prend une Pin et détermine son mode (Input/Output)
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

void loop() {
  // Boucle Violet
  for (int i=0; i<256; i++)
  {
    analogWrite(pinBlue, 255-i);
    analogWrite(pinRed, i);
    delay(20);
  }

  // Boucle Jaune
  for (int i=0; i<256; i++)
  {
    analogWrite(pinRed, 255-i);
    analogWrite(pinGreen, i);
    delay(20);
  }

  // Boucle Cyan
  for (int i=0; i<256; i++)
  {
    analogWrite(pinGreen, 255-i);
    analogWrite(pinBlue, i);
    delay(20);
  }
}
