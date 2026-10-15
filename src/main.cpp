#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Airtel_My_Network";
const char* password = "9910357357";

WebServer server(80);

void handleRoot() {
  String html = "<!DOCTYPE html>";
  html += "<html>";
  html += "<head><title>ESP32-S3 Web Server</title></head>";
  html += "<body>";
  
  html += "<h1>ESP32-S3 Web Server Dashboard</h1>";
  html += "<h2>System Status and Overview</h2>";
  html += "<br>";
  html += "<p>This page demonstrates various HTML elements rendered directly from your microcontroller.</p>";
  
  html += "<h3>Hardware Comparison: ESP32 vs Standard Arduino</h3>";
  html += "<table border=\"1\">";
  html += "<tr><th>Feature</th><th>ESP32-S3</th><th>Classic Arduino (Uno)</th></tr>";
  html += "<tr><td>Clock Speed</td><td>240 MHz (Dual Core)</td><td>16 MHz (Single Core)</td></tr>";
  html += "<tr><td>Flash Memory</td><td>16 MB</td><td>32 KB</td></tr>";
  html += "<tr><td>RAM</td><td>512 KB SRAM</td><td>2 KB SRAM</td></tr>";
  html += "<tr><td>Connectivity</td><td>Wi-Fi and Bluetooth 5</td><td>None</td></tr>";
  html += "</table>";

  html += "<h3>Key Features of this Build</h3>";
  html += "<ul>";
  html += "<li>High-speed 16MB QIO Flash storage</li>";
  html += "<li>Asynchronous-ready web server architecture</li>";
  html += "<li>Optimized PlatformIO workflow</li>";
  html += "</ul>";

  html += "<br>";
  html += "<p>Learn more about official microcontrollers at the <a href=\"https://www.espressif.com\" target=\"_blank\">Espressif Official Website</a>.</p>";
  
  html += "</body>";
  html += "</html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}