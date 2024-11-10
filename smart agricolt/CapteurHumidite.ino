#define solPin A0 // port de connexion du capteur
#define ledPin 13 // port de connexion du led

int minsol = 500; // minimal d'humidité du sol
int sol;

void setup(){
   Serial.begin(9600);

   pinMode(solPin, INPUT);
   pinMode(ledPin, OUTPUT);
}

void loop(){
   sol = analogRead(solPin);
   Serial.print("sol = ");
   Serial.println(sol); // afficher variable

   if (sol < minsol) { digitalWrite(ledPin, LOW); }
   if (sol > minsol) { digitalWrite(ledPin, HIGH); }

   delay(1000);
}
