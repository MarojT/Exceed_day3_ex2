#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
const char *ssid = "Jtb";
const char *password = "zlsq1912";
const String baseUrl = "https://exceed-hardware-stamp465.koyeb.app/leddelay";
extern int led_delay = 0;

void Connect_Wifi(){
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.print("OK! IP=");
}

void Get_Led(){
    DynamicJsonDocument doc(65536);
    HTTPClient http;
    http.begin(baseUrl);

    int httpResponseCode = http.GET();
    if (httpResponseCode >= 200 && httpResponseCode < 300){
        String payload = http.getString();
        deserializeJson(doc,payload);

        Serial.println(doc["value"].as<int>());
    }
led_delay = doc["value"].as<int>();
}


