#define   flamePin 2
#define   ledPin 12

int   flame;

void  setup () {
    Serial . begin (9600);
 
   pinMode (flamePin, INPUT );
    pinMode (ledPin, OUTPUT );
     pinMode (8, OUTPUT );
}

void  loop () {
   flame = digitalRead (flamePin);

   Serial . print ( "Flame Sensor - " );
    Serial . println (flame);

   if (flame == HIGH ){
       digitalWrite (ledPin, 0 );
       noTone (8);}
    else {
      Serial . println ( "Attention DETECTION" );
      digitalWrite (ledPin, 1 );
      tone (8,1000,1000);
    }
}
