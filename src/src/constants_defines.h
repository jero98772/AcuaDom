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
#define NUMPIXELS2 12  

#define hour6 21600
#define hour10 36000
#define hour14 50400
#define hour18 64800
#define hour21 75600


#define waterTemperatureSensor
#define waterTemperatureSensor

//#define dhtsensor

#define DHTTYPE DHT11

#define relayLigth 2//D2
#define relayThermostat 4//D4
#define relayFilters 5//D5
#define DHTPIN 13 //D2
#define waterTemperatureSensorPin 14//D5
#define turbitySensorPin 15
#define waterLevelSensorPin 16 //see https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/
#define PINSTRIP1 17
#define PINSTRIP2 18



//relays
//1 relay for ligth
//1 relay for thermostat
//1 relay for filters


#endif

