#include <WiFi.h>
#include <HTTPClient.h>
#include <Update.h>

const char* ssid = "PAVAN";  
const char* password = "pavan0109";  
const char* firmware_url = "http://192.168.100.5:8080/BasicOTA.ino.esp32.bin";  // Change this

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi!");

    Serial.println("Starting OTA Update...");
    if (updateFirmware(firmware_url)) {
        Serial.println("Update successful! Restarting...");
        ESP.restart();
    } else {
        Serial.println("Update failed!");
    }
}

bool updateFirmware(const char* url) {
    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode == HTTP_CODE_OK) {
        int contentLength = http.getSize();
        bool canBegin = Update.begin(contentLength);
        
        if (canBegin) {
            WiFiClient* stream = http.getStreamPtr();
            Update.writeStream(*stream);
            
            if (Update.end(true)) {
                Serial.println("Firmware updated successfully!");
                return true;
            } else {
                Serial.println("Update failed.");
            }
        } else {
            Serial.println("Not enough space for update.");
        }
    } else {
        Serial.println("Failed to download firmware.");
    }

    http.end();
    return false;
}

void loop() {}
