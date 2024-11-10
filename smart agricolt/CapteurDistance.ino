const int trigPin = 9;        // Trig pin of the HC-SR04
const int echoPin = 8;        // Echo pin of the HC-SR04
const int ledPin = 13;        // LED connected to pin 12
const int tankHeight = 50;    // Total height of the water tank in cm
const int lowWaterThreshold = 10;  // Threshold for low water level in cm

void setup() {
  Serial.begin(9600);          // Start serial communication
  pinMode(trigPin, OUTPUT);    // Set Trig pin as output
  pinMode(echoPin, INPUT);     // Set Echo pin as input
  pinMode(ledPin, OUTPUT);     // Set the LED pin as output
}

void loop() {
  // Send a pulse from the Trig pin
  digitalWrite(trigPin, LOW);  // Ensure the trigger pin is low
  delayMicroseconds(2);        // Pause for 2 microseconds
  digitalWrite(trigPin, HIGH); // Send a high pulse for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the Echo pin's high pulse
  long duration = pulseIn(echoPin, HIGH);

  // Convert the duration to distance in cm
  int distance = duration * 0.034 / 2;

  // Calculate the water level in the tank
  int waterLevel = tankHeight - distance;

  // Print the distance and water level to the Serial Monitor
  Serial.print("Distance to water surface: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Water level: ");
  Serial.print(waterLevel);
  Serial.println(" cm");

  // Debug: Print a message indicating whether the LED should be on or off
  if (waterLevel < lowWaterThreshold) {
    digitalWrite(ledPin, LOW);  // Turn on the LED if water level is low
    Serial.println("LED ON: Water level is low!");
  } else {
    digitalWrite(ledPin, HIGH);   // Turn off the LED if water level is sufficient
    Serial.println("LED OFF: Water level is sufficient.");
  }

  delay(1000);  // Delay between readings (increase this if you need more time to observe)
}
