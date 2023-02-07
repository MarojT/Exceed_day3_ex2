#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
const char *ssid = "Jtb";
const char *password = "zlsq1912";
const String baseUrl = "https://exceed-hardware-stamp465.koyeb.app/leddelay";

void Connect_Wifi(){
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.print("OK! IP=");
}

int Get_Led(){
    DynamicJsonDocument doc(65536);
    HTTPClient http;
    http.begin(baseUrl);

    int httpResponseCode = http.GET();
    if (httpResponseCode >= 200 && httpResponseCode < 300){
        String payload = http.getString();
        deserializeJson(doc,payload);

        Serial.println(doc["value"].as<int>());
    }
return doc["value"].as<int>();
}


