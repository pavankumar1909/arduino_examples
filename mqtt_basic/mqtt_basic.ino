#include <WiFi.h>
#include <PubSubClient.h>

// WiFi Credentials
const char* ssid = "PAVAN";  
const char* password = "pavan0109";  

// MQTT Broker Details
const char* mqtt_broker = "test.mosquitto.org";  
const char* mqtt_topic = "pavantest/topic";  
const char* mqtt_client_id = "ESP32_PAVAN";  

// Create WiFi and MQTT client objects
WiFiClient espClient;
PubSubClient client(espClient);

// Callback function when a message is received
void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    Serial.print("Message: ");

    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);  // Print message character by character
    }

    Serial.println();
}

// Connect to WiFi
void setup_wifi() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi");
}

// Connect to MQTT Broker
void connect_mqtt() {
    while (!client.connected()) {
        Serial.print("Connecting to MQTT...");
        if (client.connect(mqtt_client_id)) {
            Serial.println("Connected to MQTT Broker!");
            client.subscribe(mqtt_topic);  // Subscribe to topic
        } else {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    setup_wifi();

    client.setServer(mqtt_broker, 1883);  // Set MQTT broker and port
    client.setCallback(callback);         // Attach callback function

    connect_mqtt();
}

void loop() {
    if (!client.connected()) {
        connect_mqtt();  // Reconnect if connection is lost
    }
    client.loop();  // Maintain MQTT connection
}
