// UltrasonDetection.h

#ifndef _ULTRASONDETECTION_h
#define _ULTRASONDETECTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//const int echoPin = 2; // attach pin D2 Arduino to pin Echo of HC-SR04
//const int trigPin = 3; //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPinG 3
#define echoPinD 5
#define echoPinAV 7
#define echoPinAR 9
#define trigPinG 2
#define trigPinD 4
#define trigPinAV 6
#define trigPinAR 8
#define Signal 10

// defines variables 
const int THRESHOLD = 30; //variable for the decision to stop or not


float measureDistance(int, int);
bool dashDecision(float, float);
float measureDistance4();
void setupDetection();
void SendSignal(bool);
bool verifDistance(float);
float DetDistMin(float, float, float, float);
#endif
#endif
