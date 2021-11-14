 
#include "UltrasonDetection.h" 

  

void setup() {
  setupDetection();
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
  distance = measureDistance4();
  Serial.print("distance max = "+ distance);
  decision = dashDecision(distance,THRESHOLD);
  
}
