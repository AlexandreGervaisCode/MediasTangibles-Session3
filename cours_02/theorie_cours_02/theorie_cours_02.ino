void setup() {
  // put your setup code here, to run once:
  pinMode(21, OUTPUT); // Prend une Pin et détermine son mode (Input/Output)
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(21, HIGH); // Active le voltage pour Pin 21
  delay(1000); // Pause le programme pendant 1000ms
  
  digitalWrite(21, LOW); // Désactive le voltage pour Pin 21
  delay(1000); // Pause le programme pendant 1000ms
}
