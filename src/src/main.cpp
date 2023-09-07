#pragma once
#include "lights.h"
#include "relays.h"
#include "sensors.h"
#include "networking.h"
#include "tools.h"
#include "UbidotsEsp32Mqtt.h"

//#include <WiFiManager.h>  
#include "constants_defines.h"

long  mytime=0L;
bool conected=false;
unsigned long timer;


//values for ubidots

const int PUBLISH_FREQUENCY = 5000; 
const char * UBIDOTS_TOKEN="";
// location
//String loclat="19.21833";
//String loclng="72.978088";
//String Location;

const char *DEVICE_LABEL = "acuadoom_1";   
const char *HUMIDITY_LABEL = "humidity"; 
const char *TEMPERATURE_LABEL = "temperature"; 
const char *WATERLEVEL_LABEL = "waterlevel"; 
const char *TURBITY_LABEL = "turbity";

const char *FILTER_LABEL = "filter"; 
const char *LIGTHS_LABEL = "lights"; 
const char *THERMOSTAT_LABEL = "thermostat";



//WiFiManager wifiManager;
lights light;
sensors sensor;
relays relay;
networking net;

Ubidots ubidots(UBIDOTS_TOKEN);

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}


void options(String input){
  if(input=="on"){
      relay.turnOnAll();
  }else if(input=="off"){
    relay.turnOffAll();
  }
  else if(input=="onlights"){ //|| ubidots.subscribeLastValue(DEVICE_LABEL, LIGTHS_LABEL)==1){
    relay.turnOnlights();
    //light.turnOn();
  }else if(input=="offlights"){//|| ubidots.subscribeLastValue(DEVICE_LABEL, LIGTHS_LABEL)==0){
    relay.turnOfflights();
    //light.turnOff();
  }
  else if(input=="onfilters"){// || ubidots.subscribeLastValue(DEVICE_LABEL, FILTER_LABEL)==1){
    relay.turnOnFilters();
  }else if(input=="offfilters"){// || ubidots.subscribeLastValue(DEVICE_LABEL, FILTER_LABEL)==0){
    relay.turnOffFilters();
  }else if(input=="onthermostat"){// || ubidots.subscribeLastValue(DEVICE_LABEL, THERMOSTAT_LABEL)==1){
    relay.turnOnThermostat();
  }else if(input=="offthermostat"){// || ubidots.subscribeLastValue(DEVICE_LABEL, THERMOSTAT_LABEL)==0){
    relay.turnOffThermostat();
  }

}
void sendUbidots(){
  if (!ubidots.connected()){
    ubidots.reconnect();
  }
  int time=millis() - timer;
  if (abs(time) > PUBLISH_FREQUENCY){ // triggers the routine every 5 seconds

    ubidots.add(HUMIDITY_LABEL, sensor.dhtHumidityGet()); 
    ubidots.add(TEMPERATURE_LABEL, sensor.dhtTemperatureGetCelcius()); 
    ubidots.add(WATERLEVEL_LABEL, sensor.waterLevelSensorGet()); 
    ubidots.add(TURBITY_LABEL, sensor.turbityGet()); 
    
    ubidots.publish(DEVICE_LABEL);
    timer = millis();

  }
  ubidots.loop();
}

void showData(){
  Serial.println("Humidty of the room");
  Serial.println(sensor.dhtHumidityGet());
  Serial.println("Temperature on Celcius of the room");
  Serial.println(sensor.dhtTemperatureGetCelcius());
  Serial.println("Water temperature");
  Serial.println(sensor.waterTemperatureGet());
  Serial.println("Water Level");
  Serial.println(sensor.waterLevelSensorGet());
  Serial.println("Turbity of Water");
  Serial.println(sensor.turbityGet());
}
void setup() {
  Serial.begin(9600);
  conected=net.wifimanager();
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  net.webServerSetup();
  relay.turnOnAll();
  timer = millis();
  //light.complateCicle(net.getTime());
}

void loop() {
  String mytime = net.getTime();
  Serial.println("Time:");
  Serial.println(mytime);
  showData();
  //light.complateCicle(mytime);
  net.webServerRun();
  delay(1000);
  // put your main code here, to run repeatedly:
}