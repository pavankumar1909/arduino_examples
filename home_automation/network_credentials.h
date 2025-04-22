#ifndef __NETWORK_CREDENTIALS_H__
#define __NETWORK_CREDENTIALS_H__

//wifi credentials
const char* ssid =     "Galaxy A3075C4";  //"PAVAN";        //replace with your wifi username
const char* password =  "99999999" ;                  //"pavan0109";  //replace with your wifi password      

//mqtt credentials
const char* mqtt_server = "test.mosquitto.org";      //  MQTT brokerIP
const char* topic = "ESP32/home";               // subscribing topic
const char* progress_topic = "pavandevice/progress"; // publishing topic
const char* mqtt_client_id = "ESP32_HOME_AUTOMATION";    // mqtt client name(ESP32-S3)


#endif //__NETWORK_CREDENTIALS_H__
