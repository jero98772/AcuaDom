#include "sensors.h"
#include "constants_defines.h"
#include <DallasTemperature.h>
#include <Wire.h>
#include <DHT.h>
DHT dht(DHTPIN,DHTTYPE);
dht.begin();
OneWire oneWire(waterTemperatureSensor);  
DallasTemperature sensors(&oneWire);


short int sensors::waterTemperatureGet(){
    return sensors.getTempCByIndex(0);

}
short int sensors::dhtHumidityGet(){
    short int data; 
    if(!isnan(dht.readHumidity())) data= dht.readHumidity();
    else data=-1; 
    return data;
}
float sensors::floatdhtTemperatureGetCelcius(){
    float data; 
    if(!isnan(dht.readTemperature())) data= dht.readTemperature();
    else data=-1.0; 
    return data;
}
float sensors::floatdhtTemperatureGetFahrenheit(){
    float data; 
    if(!isnan(dht.readTemperature())) data= dht.readTemperature(true);
    else data=-1.0; 
    return data;
}
short int sensors::turbitySetup(){}