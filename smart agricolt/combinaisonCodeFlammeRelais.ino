// Broches pour le détecteur de flamme et le relais
#define flamePin 12       // Broche du détecteur de flamme
#define relayPin 2        // Broche pour le relais

int flame;

void setup() {
    Serial.begin(9600);
    
    // Initialisation des broches en mode INPUT ou OUTPUT
    pinMode(flamePin, INPUT);    // Capteur de flamme en entrée
    pinMode(relayPin, OUTPUT);   // Relais en sortie
}

void loop() {
    flame = digitalRead(flamePin);  // Lecture du capteur de flamme

    Serial.print("Flame Sensor - ");
    Serial.println(flame);

    if (flame == LOW) {  // Aucune flamme détectée
        digitalWrite(relayPin, LOW);    // Désactiver le relais (pompe éteinte)
    } 
    else {               // Flamme détectée
        Serial.println("Attention DETECTION");
        digitalWrite(relayPin, HIGH);   // Activer le relais (pompe en marche)
    }

    delay(500);  //
