// 1M.h

#ifndef _1M_h
#define _1M_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// programme qui doit r�aliser un mouvement de 1 mtre pour le robot

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38
#define X_MIN_PIN 3
#define X_MAX_PIN 2

#define Y_STEP_PIN 60
#define Y_DIR_PIN 61
#define Y_ENABLE_PIN 56
#define Y_MIN_PIN 14
#define Y_MAX_PIN 15

extern bool notInterrupted_moteur;

void setup_Moteur();
void setInterruption(bool noInterrupt);
void Test_1M();
void Test_360_degres();
void TestNull();

#endif
