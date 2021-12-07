

  
  int cm1 = 0, cm2 = 0; // Distance de l'objet
  int buzzer = 6; // Pin du buzzer
  int led = 4;
  
  void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600); 
  }
  
  void loop() {

    cm1 = (Distance(8, 2) /2) *340 /10000;
    cm2 = (Distance(9, 3) /2) *340 / 10000;
    
    //PAS Obligatoire 
    Serial.println("Gauche:");
    Serial.println(cm1);
    Serial.println("Droite:");
    Serial.println(cm2);
    Serial.println("-----------------");
    
    //SI objet est à - de 100cm
    if(cm1 <= 100 || cm2 <= 100)
    {
      //********************
      //Si objet est à GAUCHE
      //********************
      if(cm1 > cm2)
      {
        gauche();
      }
      
      //********************
      //Si objet est à DROITE
      //********************
      if(cm1 < cm2)
      {
        droite();
      }
      
     //********************
     //Si objet est au CENTRE
     //********************
      if(cm1 == cm2)
      {
        Symphonie();
      }
      
      noTone(6); // Arrete le buzzer
      digitalWrite(led, HIGH);//Allume la led
      delay(600);//Durée de l'alarme 
      digitalWrite(led, LOW);//Eteitn la led
      delay(100);//Delay FIN CONDITION
    }
    delay(500);//Delay LOOP 
  }
  
  //Fonction qui calcul la distance
  long Distance(int EnvoyeurPin, int RecepteurPin)
  {
    pinMode(EnvoyeurPin, OUTPUT);  // Clear the trigger
    digitalWrite(EnvoyeurPin, LOW);
    delayMicroseconds(RecepteurPin);
    // Sets the trigger pin to HIGH state for 10 microseconds
    digitalWrite(EnvoyeurPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(EnvoyeurPin, LOW);
    pinMode(RecepteurPin, INPUT);
    // Reads the echo pin, and returns the sound wave travel time in microseconds
    return pulseIn(RecepteurPin, HIGH);
  }

 void gauche() {
   for (int i = 1000; i > 0  ; i--){
      tone (6, i);
      delay(1);
   }
   Serial.println("Objet à Gauche");
  }
  
  void droite() { 
     for (int i = 0; i < 1000 ; i++){
       tone (6, i);
       delay(1);
    }
    Serial.println("Objet à Droite");
  }

  //Symphonie réalisée par Lucie:
  void Symphonie() {
  tone(8, 523); //do
  delay(100);
  noTone(8);
  delay(60); 
  tone(8, 523); //do
  delay(200);
  noTone(8);
  delay(300);

  tone(8, 587); //ré 
  delay(100);
  noTone(8);
  delay(60); 
  tone(8, 587); //ré
  delay(200);
  noTone(8);
  delay(300);

  tone(8, 698 ); //fa
  delay(100);
  noTone(8);
  delay(60); 
  tone(8, 698 ); //fa
  delay(200);
  noTone(8);
  delay(300);

  tone(8, 659); //mi
  delay(100);
  noTone(8);
  delay(60); 
  tone(8, 659); //mi
  delay(150);
  noTone(8);
  delay(300);

  tone(8, 523); //do
  delay(400);
  noTone(8);
  delay(70); 
  tone(8, 523); //do
  delay(100);
  noTone(8);
  delay(50);
  tone(8, 587); //ré
  delay(100);
  noTone(8);
  delay(50);
  tone(8, 523); //do
  delay(100);
  noTone(8);
  delay(50);
  tone(8, 494); //si
  delay(100);
  noTone(8);
  delay(50); 

  tone(8, 440); //la
  delay(100);
  noTone(8);
  delay(50); 
  tone(8, 440); //la
  delay(400);
  noTone(8);
  delay(50); 
  //geyou
  tone(8, 392 ); //sol
  delay(100);
  noTone(8);
  delay(50); 
  tone(8, 392); //sol
  delay(400);
  noTone(8);
  delay(50); 
  Serial.println("Objet au centre");
}
