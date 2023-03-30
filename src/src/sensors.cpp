#include "sensors.h"
#include "constants_defines.h"
#include <DallasTemperature.h>
#include <Wire.h>
#include <DHT.h>

DHT dht(DHTPIN,DHTTYPE);
OneWire oneWire(waterTemperatureSensorPin);  
DallasTemperature waterTempSensor(&oneWire);
//if macro of sensor set to digital 
#ifdef turbitydigital
pinMode(waterTemperatureSensorPin, INPUT);
#endif
sensors::sensors(){
  dht.begin();

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
    return waterTempSensor.getTempCByIndex(0);
}
unsigned short int sensors::waterLevelSensorGet(){
  return analogRead(waterLevelSensorPin); //convert to porcent bettewn 100 to 0 
}

#ifdef turbitydigital
unsigned short int sensors::turbityGet(){
  if(digitalRead(sensor_in)==HIGH){       //read sensor signal
    return 1;
  }
  else{
    return 0;    
  }
}
#else
unsigned short int sensors::turbityGet(){
  int sensorValue = analogRead(waterTemperatureSensorPin);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float porcent=(voltage*100)/5;
  return  porcent;
}
#endif