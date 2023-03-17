#include "sensors.h"
#include "constants_defines.h"
#include <DallasTemperature.h>
#include <Wire.h>
#include <DHT.h>
DHT dht(DHTPIN,DHTTYPE);
dht.begin();

OneWire oneWire(waterTemperatureSensorPin);  
DallasTemperature sensors(&oneWire);
//if macro of sensor set to digital 
#ifdef turbitydigital
pinMode(waterTemperatureSensorPin, INPUT);
#endif

unsigned short int sensors::waterTemperatureGet(){
    return sensors.getTempCByIndex(0);
}

unsigned short int sensors::dhtHumidityGet(){
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

float sensors::waterTemperatureGet(){
    //Rember the operational aplifier for get data from termocucla
    return sensors.getTempCByIndex(0);
}

#ifdef turbitydigital
short int sensors::turbityGetDigital(){
  if(digitalRead(sensor_in)==HIGH){       //read sensor signal
    return 1;
  }
  else{
    return 0;    
  }
}
#else
short int sensors::turbityGetAnalog(){
  int sensorValue = analogRead(waterTemperatureSensorPin);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float porcent=(voltage*100)/5;
  return  porcent
}
#endif