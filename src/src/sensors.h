#ifndef _SENSORS_H
#define _SENSORS_H
#include <DHT.h>
class sensors{
private:/*
    float waterTemperature;
    float temperature;
    unsigned short int humidity;  
    unsigned short int turbity;*/
public:
    sensors();
    ~sensors();
    float floatdhtTemperatureGetCelcius();
    float floatdhtTemperatureGetFahrenheit();
    float waterTemperatureGet();
    unsigned short int dhtHumidityGet();
    unsigned short int turbityGet();
    unsigned short int waterLevelSensorGet();
    //clock
};




#endif