#include "networking.h"
#include "constants_defines.h"
#include "time.h"
#include <WiFiManager.h>

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -18000;
const int   daylightOffset_sec = 0;


networking::networking(){
}
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
void networking::webserver(){
	WiFiServer server(80);
}