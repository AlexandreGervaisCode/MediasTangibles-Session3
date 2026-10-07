#include <ESP32Servo.h>

const int pinServo = 5;
const int pinPotentio = 4;
int positionServo = 0;
int valeurCapteur = 0;
Servo monServo;

void setup() {
  monServo.attach(pinServo);
  Serial.begin(115200);
}

void loop() {
  valeurCapteur = analogRead(pinPotentio);
  positionServo = map(valeurCapteur, 0, 255, 0, 180);
  monServo.write(positionServo);
  Serial.println(valeurCapteur);
  /*
  for(i=0; i<=180; i++) // Glisse lentement de 0 à 180 degrées
  {
    monServo.write(i);
    delay(20);
  }

  for(i=0; i<=180; i++) // Glisse lentement de 180 à 0 degrées
  {
    monServo.write(180-i);
    delay(20);
  }*/
}
