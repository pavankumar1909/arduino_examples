#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <WiFi.h>
#include <PubSubClient.h>
#include <Update.h>


unsigned long wifi_reconnection_time = 0;
unsigned long mqtt_reconnection_time = 0;
unsigned long handle_msg_time = 0;

bool nonblocking_timerDelay(unsigned long &lastTime, unsigned long interval) 
{
    unsigned long currentTime = millis();
    if (currentTime - lastTime >= interval) 
    {
        lastTime = currentTime;
        return true;  // Time interval has passed
    }
    return false;  // Not yet reached
}

#endif //__HEADERS_H__
