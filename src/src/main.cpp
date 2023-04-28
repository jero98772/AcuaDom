#pragma once
#include "lights.h"
#include "relays.h"
#include "sensors.h"
#include "networking.h"
#include "tools.h"
//#include <WiFiManager.h>  
#include "constants_defines.h"

long  mytime=0L;
bool conected=false;
//WiFiManager wifiManager;
lights light;
sensors sensor;
relays relay;
networking net;
void options(String input){
  if(input=="on"){
      relay.turnOnAll();
  }else if(input=="off"){
    relay.turnOffAll();
  }
  else if(input=="onligths"){
    relay.turnOnligths();
    light.turnOn();
  }else if(input=="offligths"){
    relay.turnOffligths();
    light.turnOff();
  }
  else if(input=="onfilters"){
    relay.turnOnFilters();
  }else if(input=="offfilters"){
    relay.turnOffFilters();
  }else if(input=="onthermostat"){
    relay.turnOnThermostat();
  }else if(input=="offthermostat"){
    relay.turnOffThermostat();
  }

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
  Serial.print(sensor.turbityGet());
}
void setup() {
  Serial.begin(9600);
  conected=net.wifimanager();
  net.webServerSetup();
  relay.turnOnAll();
  light.turnOn();
  light.complateCicle(net.getTime());
}

void loop() {
  String mytime = net.getTime();
  Serial.println("Time:");
  Serial.println(mytime);
  showData();
  light.complateCicle(mytime);
  net.webServerRun();
  delay(1000);
  // put your main code here, to run repeatedly:
}