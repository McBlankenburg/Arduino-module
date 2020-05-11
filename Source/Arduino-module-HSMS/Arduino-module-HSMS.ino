
#include "DHT.h"
#define DHT11_PIN 3
DHT dht;


#define PIR 2
#define BUZZ A0

void setup() {
 Serial.begin(9600); //Setting speed transmition
 
  pinMode(PIR,  INPUT); //PIR input
  pinMode( A0, OUTPUT); //PIN A0 output
  
  dht.setup(DHT11_PIN);
}
 
void loop() {
   pirDetector();
   dhtDetector();

   
  delay(1000);
  Serial.println("_____________________");
}


void pirDetector(){
  
    if (digitalRead(PIR) == HIGH) { //when detector sees movement
    Serial.println("movement detected");  
  }
  
  else {                            //when detector cannot see movement
    Serial.println("no movement");
  }
}

void dhtDetector(){
  //getHumidity
  int humidity = dht.getHumidity();
  int temperature = dht.getTemperature();

  if (dht.getStatusString() == "OK") {
    Serial.print(humidity);
    Serial.print("%RH | ");
    Serial.print(temperature);
    Serial.println("*C");
  }
  delay(dht.getMinimumSamplingPeriod());

}

void buzzer(){  // only to alarm something

  digitalWrite(BUZZ, HIGH);
  delay(1);
   digitalWrite(BUZZ, LOW);

  
}
