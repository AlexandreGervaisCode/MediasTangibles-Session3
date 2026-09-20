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
  // Ferme toutes les couleurs pendant 500ms
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, LOW);
  delay(500);

  // Ouvre la pin rouge pendant 500ms (RED)
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, LOW);
  delay(500);

  // Ouvre la pin rouge et verte pendant 500ms (YELLOW)
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, LOW);
  delay(500);

  // Ouvre la pin verte pendant 500ms (GREEN)
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, LOW);
  delay(500);

  // Ouvre la pin verte et bleu pendant 500ms (CYAN)
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, HIGH);
  delay(500);

  // Ouvre la pin bleu pendant 500ms (BLUE)
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, HIGH);
  delay(500);

  // Ouvre la pin rouge et bleu pendant 500ms (PURPLE)
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, HIGH);
  delay(500);
}
