// 
// 
// 

#include "UltrasonDetection.h"


float measureDistance(int echoPin, int trigPin) {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	// Calculating the distance
	distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
	return distance;
}
bool dashDecision(float distance, float THRESHOLD) {
	if (distance <= THRESHOLD) {
		return false;
	}
	else {
    Serial.print("truc détecté");
		return true;
	}
}
void setupDetection(){
  pinMode(trigPinG, OUTPUT);
  pinMode(echoPinG, INPUT);
  pinMode(trigPinD, OUTPUT);
  pinMode(echoPinD, INPUT);
  pinMode(trigPinAR, OUTPUT);
  pinMode(echoPinAR, INPUT);
  pinMode(trigPinAV, OUTPUT);
  pinMode(echoPinAV, INPUT);
}

float measureDistance4()
{
	float distanceAR, distanceAV, distanceG, distanceD = 0;
	distanceAR = measureDistance(echoPinAR, trigPinAR);
	distanceAV = measureDistance(echoPinAV, trigPinAV);
	distanceG = measureDistance(echoPinG, trigPinG);
	distanceD = measureDistance(echoPinD, trigPinD);
  
	return max(max(distanceAR, distanceAV),max(distanceG,distanceD));
	
}
