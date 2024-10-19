#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

// DHT22 setup
#define DHTPIN 4          // Pin where the DHT22 is connected
#define DHTTYPE DHT22     // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

// WiFi credentials
const char* ssid = "Wokwi-GUEST";           // Replace with your WiFi SSID
const char* password = "";    // Replace with your WiFi Password

// ThingSpeak channel details
const char* server = "api.thingspeak.com";
const char* apiKey = "LYZO6SZAYUSU2AZI";       // Replace with your ThingSpeak API key

void setup() {
  Serial.begin(115200);
  
  // Initialize DHT sensor
  dht.begin();
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read temperature and humidity from DHT22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read potentiometer value (0-4095 for ESP32)
  int potValue = analogRead(34);  // GPIO34

  // Print values to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Potentiometer Value: ");
  Serial.println(potValue);

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String("http://") + server + "/update?api_key=" + apiKey +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity) +
                 "&field3=" + String(potValue);
    
    http.begin(url);
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error on sending: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();  // Close connection
  }

  delay(2000);  // Wait for 2 seconds before the next reading
}
