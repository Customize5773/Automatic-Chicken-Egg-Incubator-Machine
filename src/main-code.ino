#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <Servo.h>

// Wi-Fi Credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// DHT Sensor
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Pin assignments
#define RELAY_PIN 18
#define SERVO_PIN 19
#define FAN_PIN 23

Servo ventServo;
WebServer server(80);

// Thresholds
const float TEMP_MIN = 36.5;
const float TEMP_MAX = 37.5;
const float HUMIDITY_MAX = 60.0;

// Bulb cycling
unsigned long lastCycleTime = 0;
bool bulbState = false;
const unsigned long CYCLE_INTERVAL = 2000;

void setup() {
  Serial.begin(115200);

  dht.begin();
  ventServo.attach(SERVO_PIN);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, HIGH); // Fan always ON

  // Wi-Fi Setup
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected. IP: " + WiFi.localIP().toString());

  // Web server route
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Temperature Control Logic
  unsigned long currentTime = millis();
  if (!isnan(temperature)) {
    if (temperature < TEMP_MIN) {
      if (currentTime - lastCycleTime >= CYCLE_INTERVAL) {
        bulbState = !bulbState;
        digitalWrite(RELAY_PIN, bulbState ? HIGH : LOW);
        lastCycleTime = currentTime;
      }
    } else if (temperature > TEMP_MAX) {
      digitalWrite(RELAY_PIN, LOW);
      bulbState = false;
    }
  }

  // Humidity Control
  if (!isnan(humidity)) {
    if (humidity > HUMIDITY_MAX) {
      ventServo.write(90); // Open
    } else {
      ventServo.write(0);  // Close
    }
  }

  // Handle web requests
  server.handleClient();
}

void handleRoot() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  String html = "<!DOCTYPE html><html><head><meta http-equiv='refresh' content='5'/>";
  html += "<title>Egg Incubator Monitor</title></head><body>";
  html += "<h1>🐣 Automatic Egg Incubator</h1>";
  html += "<p><b>Temperature:</b> " + String(t) + " °C</p>";
  html += "<p><b>Humidity:</b> " + String(h) + " %</p>";
  html += "<p><b>Heating Bulb:</b> " + String(bulbState ? "ON" : "OFF") + "</p>";
  html += "<p><b>Vent Status:</b> " + String(h > HUMIDITY_MAX ? "Open" : "Closed") + "</p>";
  html += "<p><b>IP Address:</b> " + WiFi.localIP().toString() + "</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}
