
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

  buzzer(200, 1, 500);
  Serial.println("Arduino Start");
}
 
void loop() {
  delay(500);
  Serial.println();
   pirDetector();
   dhtDetector();
   
  delay(1000);
}


void pirDetector(){

  Serial.print("Motion detector: ");
  
    if (digitalRead(PIR) == HIGH) { //when detector sees movement
    Serial.println("True");  
  }
  
  else {                            //when detector cannot see movement
    Serial.println("False");
  }
}

void dhtDetector(){
  //getHumidity
  int humidity = dht.getHumidity();
  int temperature = dht.getTemperature();

  if (dht.getStatusString() == "OK") {
    //humidity message
    Serial.print("Humidity[%RH]: ");
    Serial.println(humidity);
    
    //temperature message
    Serial.print("Temperature[*C]: ");
    Serial.print(temperature);
  }
  delay(dht.getMinimumSamplingPeriod());

}

void buzzer(int howLongScream, int howManyTimes, int howLongSilence) // ALARM with settings
{  
  for(int i = 1; i <= howManyTimes; i++){
    digitalWrite(BUZZ, HIGH);
    delay(howLongScream);
    digitalWrite(BUZZ, LOW);
    delay(howLongSilence);
  }

}
