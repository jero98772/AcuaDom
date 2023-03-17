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
    short int dhtHumidityGet();
    float waterTemperatureGet();
    short int turbityGetAnalog();
    short int turbityGetDigital();
    //water level
    //clock
};




#endif