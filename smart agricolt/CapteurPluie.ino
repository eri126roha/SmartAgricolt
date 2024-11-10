void setup() {
  pinMode(12, INPUT); //rain on pin12
  pinMode(13, OUTPUT); //led on pin13

}

void loop() {
  if(digitalRead(12) ==LOW){
    digitalWrite(13, HIGH);
    delay(500);
  }

}
