#pragma once
#include "lights.h"
#include "relays.h"
#include "sensors.h"
#include "networking.h"
#include "constants_defines.h"
#ifndef NOFIXWIFI
#include "WiFi.h"
#endif
bool conected=false;
lights light;
sensors sensor;
relays relay;
networking net;
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
  #ifdef NOFIXWIFI
  conected=net.wifimanager();
  if(conected){
    net.webServerSetup();
  }
  #else
  WiFi.begin("ssid", "12345678");
  Serial.println("\nConnecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  #endif
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
}