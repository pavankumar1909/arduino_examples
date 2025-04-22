//#include"headers.h"
//#include"MQTTClient.h"
//#include"network_credentials.h"

void handle_message(String msg)
{
  if(msg=="ON")
  {
    digitalWrite(2,HIGH);
    delay(2000);
  }
  else if(msg=="OFF")
  {
    digitalWrite(2,LOW);
    delay(2000);
  }
}
