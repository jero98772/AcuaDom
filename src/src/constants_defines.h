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
long time=0;
#define lampType "simple"//there diferents types of ligth for difetent acuariums, types are marine,planted or simples
#define PINSTRIP1 1
#define PINSTRIP2 3
#define NUMPIXELS1 12
#define NUMPIXELS2 12  

#define waterTemperatureSensor
#define waterTemperatureSensor


#define dht

#define DHTTYPE DHT11

#define relayLigth 4//D2
#define relayThermostat 0//D3
#define relayFilters 2//D4
#define waterTemperatureSensorPin 14 //D5
#define DHTPIN 12//D6
#define turbitySensorPin 13
#define waterLevelSensorPin 16 //see https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/


//relays
//1 relay for ligth
//1 relay for thermostat
//1 relay for filters


#endif

