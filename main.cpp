#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *ssid = "Star";
const char *password = "935062766";

ESP8266WebServer server(80);

// Function declarations
void handleRoot();
int getDistance();
int getWaterLevel();

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Define server routes
  server.on("/", HTTP_GET, handleRoot);

  // Start server
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Hello from ESP8266!</h1>";
  html += "<p>Distance: " + String(getDistance()) + " cm</p>";
  html += "<p>Water Level: " + String(getWaterLevel()) + "</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

// Replace these functions with your actual sensor readings
int getDistance() {
  return 25; // Example distance value in centimeters
}

int getWaterLevel() {
  return analogRead(A0); // Example water level reading
}
