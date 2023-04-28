#ifndef _CONSTANTS_DEFINES_H
#define _CONSTANTS_DEFINES_H
//#include "relays.h"
#include <Arduino.h>
/*
TASK
compleate sensors modules and add macros and precompilator directives
macros and precompilator directives

REMEMBER 
we goint to change board to esp32, with new pins , we need change to new pins


*/

#define lampType "simple"//there diferents types of ligth for difetent acuariums, types are marine,planted or simples


#define NUMPIXELS1 12
#define NUMPIXELS2 24 

//change it to string

//#define turbitydigital
//#define dhtsensor

#define DHTTYPE DHT11



#define relayLigth 2//D2 
#define relayThermostat 4//D4 
#define relayFilters 5//D5 
#define DHTPIN 13 //D13 //fixed
#define waterTemperatureSensorPin 21//D21
#define turbitySensorPin 34 //d34 //fixed
#define waterLevelSensorPin 35 //D16//see https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/
#define PINSTRIP1 19 //D19
#define PINSTRIP2 18 //D18
/*
#define relayLigth 2//D2 //fixed
#define relayThermostat 4//D4 //fixed 
#define relayFilters 15//D15 <-- change 
#define DHTPIN 13 //D13 //fixed
#define waterTemperatureSensorPin 14//D14   <-- change
#define turbitySensorPin 34 //d34 //fixed
#define waterLevelSensorPin 16 //D16//see https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/
#define PINSTRIP1 19 //D19
#define PINSTRIP2 18 //D18

*/

#endif

/*

*/