// 
// 
// 

#include "Tests.h"
#include <Arduino.h>

bool notInterrupted_moteur = true;

void setup_Moteur()
{
	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(X_ENABLE_PIN, OUTPUT);
	pinMode(Y_STEP_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);

	digitalWrite(X_ENABLE_PIN, LOW);
	digitalWrite(Y_ENABLE_PIN, LOW);
	
}
void setInterruption(bool noInterrupt){
  notInterrupted_moteur = noInterrupt;
}
void Test_1M()
{
	
	digitalWrite(X_DIR_PIN, HIGH);
	digitalWrite(Y_DIR_PIN, LOW);
	
	for (int i = 0; i <= 320000; i++)
	{ 
	  if(notInterrupted_moteur ){//digitalRead(21)==LOW
  		digitalWrite(X_STEP_PIN, HIGH);
  		digitalWrite(Y_STEP_PIN, HIGH);
  		delay(1);
  		digitalWrite(X_STEP_PIN, LOW);
  		digitalWrite(Y_STEP_PIN, LOW);
  	}else{

  	}
	}

	//delay(5000);
	//trajet dans l'autre sens dans l'autre sens

	//digitalWrite(X_DIR_PIN, LOW);
	//digitalWrite(Y_DIR_PIN, HIGH);
	//for (int i = 0; i <= 3200; i++)
	//{
	//	digitalWrite(X_STEP_PIN, HIGH);
	//	digitalWrite(Y_STEP_PIN, HIGH);
	//	delay(1);
	//	digitalWrite(X_STEP_PIN, LOW);
	//	digitalWrite(Y_STEP_PIN, LOW);
	//}
	//delay(99999999999);
}
void Test_360_degres()
{
	// tour dans un sens
	digitalWrite(X_DIR_PIN, HIGH);
	digitalWrite(Y_DIR_PIN, HIGH);

	for (int i = 0; i <= 3200; i++)
	{
		digitalWrite(X_STEP_PIN, HIGH);
		digitalWrite(Y_STEP_PIN, HIGH);
		delay(1);
		digitalWrite(X_STEP_PIN, LOW);
		digitalWrite(Y_STEP_PIN, LOW);
	}

	delay(5000);
	//trajet dans l'autre sens dans l'autre sens

	digitalWrite(X_DIR_PIN, LOW);
	digitalWrite(Y_DIR_PIN, HIGH);
	for (int i = 0; i <= 3200; i++)
	{
		digitalWrite(X_STEP_PIN, HIGH);
		digitalWrite(Y_STEP_PIN, HIGH);
		delay(1);
		digitalWrite(X_STEP_PIN, LOW);
		digitalWrite(Y_STEP_PIN, LOW);
	}
	delay(99999999999);
}
void TestNull(){
  
}
