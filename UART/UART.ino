#include <SoftwareSerial.h>
SoftwareSerial Serial_1(10, 11);

String sendMessage="";
String receivedMessage="";
String value="";
void setup() {
  Serial.begin(9600);    // Initialize the Serial monitor for debugging
  Serial_1.begin(9600);   // Initialize Serial1 for sending data
}

void loop() {
  
   if(Serial_1.available() > 0) {
    char receivedChar = Serial_1.read();
    if (receivedChar == '\n') {
      Serial.println(receivedMessage);  // Print the received message in the Serial monitor
      receivedMessage = "";  // Reset the received message
    } else {
      receivedMessage+= receivedChar;  // Append characters to the received message
    }
  }

  if (Serial.available() > 0) {
    char inputChar = Serial.read();
    if (inputChar == '\n') {
      Serial_1.println(sendMessage);  // Send the message through Serial1 with a newline character
      sendMessage = "";  // Reset the message
    } else {
      sendMessage += inputChar;  // Append characters to the message
    }
  }
}
