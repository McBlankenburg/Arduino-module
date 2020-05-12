

#define PIR 2
 
void setup() {
 Serial.begin(9600); //Ustawienie prędkości transmisji
  pinMode(PIR, INPUT); //PIR jako wejście
  
}
 
void loop() {
   pirDetector();
   
  delay(1000);
}


void pirDetector(){
  
    if (digitalRead(PIR) == HIGH) { //when detector sees movement
    Serial.println("Wykryto Ruch");  
  }
  
  else {                            //when detector cannot see movement
    Serial.println("Brak Ruchu");
  }
}
