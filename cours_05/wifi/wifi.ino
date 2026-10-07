/*#include <OSCBoards.h>
#include <OSCBufferedPrint.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <OSCMatch.h>
#include <OSCMessage.h>
#include <OSCTiming.h>
#include <SLIPEncodedSerial.h>
#include <SLIPEncodedTCP.h>*/

#include<WiFi.h>
#include<WiFiUdp.h> // Réseau UDP
#include<OSCMessage.h> // Protocole OSC

char hotspotName[] = "Clodsire";
char password[] = "poisonground"; // minimum de 8 char

WiFiUDP Udp;
const IPAddress IP_ordinateur(192, 168, 4, 2); // adresse de l'ordi
const int outPort = 8000; // port écouté

void setup() {
  WiFi.softAP(hotspotName, password); // Création du hotspot
  Udp.begin(outPort); // Start UDP
}

void loop() {
  int valCapteur = touchRead(15);

  OSCMessage msg("/capteur1");
  msg.add(valCapteur); // Message "/capteur1 <int>"

  Udp.beginPacket(IP_ordinateur, outPort);
  msg.send(Udp);
  Udp.endPacket();
  msg.empty(); // On vide l'espace en mémoire
  delay(50); // Cadence du message (période d'échantillionnage)
}
