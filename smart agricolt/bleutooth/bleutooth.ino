// Définition de la broche du relais
const int relayPin = 13;

void setup() {
  // Initialisation de la broche du relais en mode sortie
  pinMode(relayPin, OUTPUT);

  // Initialisation de la communication série pour le Bluetooth
  Serial.begin(9600); // Assurez-vous que le module Bluetooth est configuré à cette vitesse
}

void loop() {
  // Vérification s'il y a des données reçues via Bluetooth
  if (Serial.available() > 0) {
    char command = Serial.read(); // Lire la commande reçue

    // Vérifier la commande et contrôler le relais
    if (command == '1') { // Si '1' est reçu
      digitalWrite(relayPin, HIGH); // Activer le relais
      Serial.println("Relais : ON"); // Confirmation envoyée via Bluetooth
    }
    else if (command == '0') { // Si '0' est reçu
      digitalWrite(relayPin, LOW); // Désactiver le relais
      Serial.println("Relais : OFF"); // Confirmation envoyée via Bluetooth
    }
    else {
      Serial.println("Commande non reconnue"); // Message si commande inconnue
    }
  }

  delay(100); // Délai pour éviter des lectures répétées rapides
}
