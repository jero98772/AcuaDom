#ifndef _CONSTANTS_DEFINES_H
#define _CONSTANTS_DEFINES_H
//#include "relays.h"
#include <Arduino.h>

#define NUMPIXELS1 12
#define NUMPIXELS2 24 


#define waterTemperatureSensor
#define waterTemperatureSensor

//#define dhtsensor
#define DHTTYPE DHT11

#define relayLight 2//D2 
#define relayThermostat 4//D4 
#define relayFilters 5//D5 
#define DHTPIN 13 //D13 //fixed
#define waterTemperatureSensorPin 32//D21
#define turbitySensorPin 34 //d34 //fixed
#define waterLevelSensorPin 35 //see https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/
#define PINSTRIP1 19 //D19
#define PINSTRIP2 18 //D18

#endif