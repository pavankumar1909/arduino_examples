#include "headers.h"                // contains all header files
#include "network_credentials.h"    // wifi,mqtt usernameand passwords
#include "WiFiManager.h"            // prototypes of WIFIManager  
#include "MQTTHandler.h"             // prototypes of MQTTClient

int val=0;
int inPin=5;

void setup() 
{
    Serial.begin(115200);
    pinMode(2,OUTPUT);
    pinMode(inPin,INPUT);
    wifi_setup();    //initialising wifi
    mqtt_setup();    //initialising mqtt
}

void loop() 
{
  
  if (nonblocking_timerDelay(wifi_reconnection_time, 1000)) 
  {
    if(!check_wifi_connection())       // reconnects to wifi in case if dis-connected
    {
      reconnect_wifi();
    }
  }
  if (nonblocking_timerDelay(mqtt_reconnection_time, 3000)) 
  {
    if(!check_mqtt_connection())      // reconnects to mqtt function to listen to the topic&broker
    {
      reconnect_mqtt();
    }
  }
  else if (nonblocking_timerDelay(handle_msg_time, 1000)) 
  {
      val = digitalRead(inPin);   // read the input pin
      Serial.println(val);
  }
}
