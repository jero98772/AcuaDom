#include "networking.h"
#include "constants_defines.h"
#include "time.h"
#include "sensors.h"
#include "relays.h"
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiManager.h>

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -18000;
const int   daylightOffset_sec = 0;

WebServer server(80);
relays relayNet;
String SendHTML() {
  sensors sensor;
  String humidity = String(sensor.dhtHumidityGet());
  String farenhit = String(sensor.dhtTemperatureGetFahrenheit());
  String celsius = String(sensor.dhtTemperatureGetCelcius());
  String turbity = String(sensor.turbityGet());
  String waterTemperatureC = String(sensor.waterTemperatureGet());
  String waterLevel = String(sensor.waterLevelSensorGet());
  String ptr = "<!DOCTYPE html> <html>\n";  
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>ACUADOM</title>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ACUADOM</h1>\n";
  ptr += "<h3>Temperatura y humedad de ambiente</h3>\n";
  ptr += "<br><b>Humedad</b>\n";
  ptr += humidity;
  ptr += "<br><b>Temperatura (C°)</b>\n";
  ptr += celsius;
  ptr += "<br><b>Temperatura (F°)</b>\n";
  ptr += farenhit;
  ptr += "<hr><br><h3>Parametros del agua del Acuario</h3>\n";
  ptr += "<br><b>Turbidez</b>\n";
  ptr += turbity;
  ptr += "<br><b>Temperatura del agua (C°)</b>\n";
  ptr += waterTemperatureC;
  ptr += "<br><b>Nivel de agua</b>\n";
  ptr += waterLevel;
  ptr += "<hr><br><h3>Control dispositivos</h3>\n";
  ptr += "<br><b>Filtro</b>\n";
  ptr += "<br><a href='/filterOn'><button type='button'>Filtro ON</button></a>\n";
  ptr += "<a href='/filterOff'><button type='button'>Filtro OFF</button></a>\n";
  ptr += "<br><b>Luz Externa</b>\n";
  ptr += "<br><a href='/ligthOn'><button type='button'>luz ON</button></a>\n";
  ptr += "<a href='/ligthOff'><button type='button'>Luz OFF</button></a>\n";
  ptr += "<br><b>Termostato</b>\n";
  ptr += "<br><a href='/thermostatOn'><button type='button'>Termostato ON</button></a>\n";
  ptr += "<a href='/thermostatOff'><button type='button'>Termostato OFF</button></a>\n";
  ptr += "<br><b>Todos los dispostivos</b>\n";
  ptr += "<br><a href='/turnOn'><button type='button'>Encender Todo</button></a>\n";
  ptr += "<a href='/turnOff'><button type='button'>Apagar Todo</button></a>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}

void filterOn() {
  relayNet.turnOnFilters();
  server.send(200, "text/html", SendHTML()); 
}
void filterOff() {
  relayNet.turnOffFilters();
  server.send(200, "text/html", SendHTML()); 
}

void ligthOn() {
  relayNet.turnOnFilters();
  server.send(200, "text/html", SendHTML()); 
}
void ligthOff() {
  relayNet.turnOffFilters();
  server.send(200, "text/html", SendHTML()); 
}
void turnOnThermostat() {
  relayNet.turnOnThermostat();
  server.send(200, "text/html", SendHTML()); 
}
void turnOffThermostat() {
  relayNet.turnOffFilters();
  server.send(200, "text/html", SendHTML()); 
}
void allOn() {
  relayNet.turnOnAll();
  server.send(200, "text/html", SendHTML()); 
}
void allOff() {
  relayNet.turnOffAll();
  server.send(200, "text/html", SendHTML()); 
}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}
void handle_NotFound() {
  server.send(404, "text/plain", "La pagina no existe");
}

networking::networking(){}
networking::~networking(){}
bool networking::wifimanager(){
	WiFi.mode(WIFI_STA);
	WiFiManager wm;
	//wm.resetSettings();
	bool res = wm.autoConnect("ACUADOMCONECT");
	if(res) {
		Serial.print("Conected to wifi");
		return true;
	}else{
		Serial.print("failed to conect");
		return false;
	}
}
String networking::getTime(){
   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    	Serial.println("Failed to obtain time");
    	return "";
  }
  char timeHourMin[6];
  strftime(timeHourMin,6, "%H:%M", &timeinfo);
  Serial.println(timeHourMin);
  return timeHourMin;

}
void networking::webServerSetup(){
	
server.on("/", handle_OnConnect);
server.onNotFound(handle_NotFound);
server.begin();
}
void networking::webServerRun(){
	server.handleClient();
}
