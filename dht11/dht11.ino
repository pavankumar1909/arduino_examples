#include "DHT.h"
#define DHT_PIN 5
#define DHTTYPE DHT11
//initialise DHT sensor
DHT dht(DHT_PIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1500);

  float temp= dht.readTemperature(); //temperature values
  
  float humidity = dht.readHumidity();  //humidity
  
  float tempInFah = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp) || isnan(tempInFah)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 
    // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(tempInFah, humidity);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(temp, humidity, false);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temp);
  Serial.print("°C ");
  Serial.print(tempInFah);
  Serial.print("°F  Heat index: ");
  Serial.print(hic);
  Serial.print("°C ");
  Serial.print(hif);
  Serial.println("°F");
}
