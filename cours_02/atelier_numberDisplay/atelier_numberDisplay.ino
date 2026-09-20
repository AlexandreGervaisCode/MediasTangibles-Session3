// Variables pour les pins
const int pinA = 21;
const int pinB = 19;
const int pinC = 22;
const int pinD = 32;
const int pinE = 25;
const int pinF = 26;
const int pinG = 33;
const int pinDP = 23;

// Variables pour l'affichage des nombres (la valeur 0 sera ignorée durant l'affichage)
const int numbers[10][7] = {
  {pinA, pinB, pinC, pinD, pinE, pinF, 0},    // 0
  {pinB, pinC, 0, 0, 0, 0, 0},                // 1
  {pinA, pinB, pinD, pinE, pinG, 0, 0},       // 2
  {pinA, pinB, pinC, pinD, pinG, 0, 0},       // 3
  {pinB, pinC, pinF, pinG, 0, 0, 0},          // 4
  {pinA, pinC, pinD, pinF, pinG, 0, 0},       // 5
  {pinA, pinC, pinD, pinE, pinF, pinG, 0},    // 6
  {pinA, pinB, pinC, 0, 0, 0, 0},             // 7
  {pinA, pinB, pinC, pinD, pinE, pinF, pinG}, // 8
  {pinA, pinB, pinC, pinD, pinF, pinG, 0}     // 9
};

// Animation continuelle Post Countdown (0 est ignoré)
const int bounceBalls[6][2] = {
  {pinA, 0},
  {pinB, pinF},
  {pinC, pinE},
  {pinD, 0},
  {pinC, pinE},
  {pinB, pinF}
};

bool isCountdownOver = false;

void setup() {
  // Fait comprendre à la microchip que les pins sont en mode Output
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void loop() {
  if(isCountdownOver) { // Si le countdown initial est terminé, fait une animation
    postCountdown();
  } else { // Sinon, fait le countdown
    countdown();
  }
  
}

void countdown() {
  // Boucle qui countdown
  for (int i=0; i<10; i++)
  {
    // Boucle qui power off chaque edges
    for (int j=0; j<7; j++)
    {
      digitalWrite(numbers[8][j], LOW); // La forme du "8" est recyclée car elle contient tout les edges
    }

    // Boucle pour allumer le nombre demandé
    for (int j=0; j<7; j++) 
    {
      if(numbers[9-i][j] != 0) {
        digitalWrite(numbers[9-i][j], HIGH);
      }
    }
    delay(1000); // Attend 1 seconde
  }
  isCountdownOver = true; // Empêche le countdown de recommencer
}

void postCountdown() {
  for (int i=0;i<6;i++) // Boucle pour circuler de frame d'animation à frame d'animation
  {
    // Boucle qui power off chaque edges
    for (int j=0; j<7; j++)
    {
      digitalWrite(numbers[8][j], LOW); // La forme du "8" est recyclée car elle contient tout les edges
    }

    for (int j=0; j<2; j++) // Boucle pour ouvrir toutes les pins nécessaire pour cette frame d'animation
    {
      if(numbers[i][j] != 0) {
        digitalWrite(bounceBalls[i][j], HIGH);
      }
    }
    delay(500); // Attend la moitié d'une seconde
  }
}