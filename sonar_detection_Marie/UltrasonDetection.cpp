// 
// 
// 

#include "UltrasonDetection.h"

//mesure de distance pour ultrason 
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
// décision True ou False en fonction de la distance réelle et de la distance min voulue
bool dashDecision(float distance, float THRESHOLD) {
	if (distance <= THRESHOLD) {
		return false;
	}
	else {
    Serial.print("truc détecté");
		return true;
	}
}
// fonction de setup pour les pins trigger et echo des ultrasons
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


// fonction qui mesure la distance pour les 4 ultrasons et renvoit le plus petit
float measureDistance4()
{
	float distanceAR, distanceAV, distanceG, distanceD = 0;
	distanceAR = measureDistance(echoPinAR, trigPinAR);
	distanceAV = measureDistance(echoPinAV, trigPinAV);
	distanceG = measureDistance(echoPinG, trigPinG);
	distanceD = measureDistance(echoPinD, trigPinD);
  
	return max(max(distanceAR, distanceAV),max(distanceG,distanceD));
	
}


Serial.print("  distance Avant =   " + String(distanceAV) + "   distance Droite =   " + String(distanceD) + "   distance Arrière =   " + String(distanceAR) + "   distance Gauche =   " + String(distanceG));


distanceMin = DetDistMin(distanceAV, distanceD, distanceAR, distanceG);

return distanceMin;

}

// détermination de la distance minimale entre les 4. faudra quand même vérifier le programme
float DetDistMin(float distAV, float distD, float distAR, float distG) {
	float test = -1;
	if (verifDistance(distAV)) {
		test = distAV;
		if (verifDistance(distD) && distAV > distD) {
			test = distD;
			if (verifDistance(distAR) && distAR > distD) {
				test = distAR;
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}
			else {
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}

		}
		else {
			if (verifDistance(distAR) && distAR > distD) {
				test = distAR;
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}
			else {
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}
		}
	}
	else {

		
		if (verifDistance(distD) && distAV > distD) {
			test = distD;
			if (verifDistance(distAR) && distAR > distD) {
				test = distAR;
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}
			else {
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}

		}
		else {
			if (verifDistance(distAR) && distAR > distD) {
				test = distAR;
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}
			else {
				if (verifDistance(distG) && distG > distAR) {
					test = distAR;
				}
			}
		}
	}
	return test;
}

//verification de la distance ( les ultrasons peuvent renvoyer 0.00 si la cible est trop loin ou si les câbles sont mal branchés)
// cette fonction renvoit true si la distance n'est pas nulle
bool verifDistance(float distance) {
	if (distance != 0.0) {
		return true;
	}
	else {
		return false;
	}


}
// envoit un signal si on est trop proche
void SendSignal(bool decision) {
	if (decision) {
		digitalWrite(Signal, HIGH);
	}
	else {
		digitalWrite(Signal, LOW);
	}
}
