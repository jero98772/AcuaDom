#include "networking.h"
#include "constants_defines.h"
#include "time.h"
#include "sensors.h"
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiManager.h>

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -18000;
const int   daylightOffset_sec = 0;

WebServer server(80);

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
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
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
	wm.resetSettings();
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
