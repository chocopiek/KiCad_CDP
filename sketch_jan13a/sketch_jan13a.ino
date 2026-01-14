#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "CHOCOPIE 4283";
const char* password = "7T03m=88";

WebServer server(80);

const int ledPin = 2;  // LED onboard ESP32

void handleOn() {
  Serial.println(">> Nhan lenh: ON");
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/plain", "LED ON");
}

void handleOff() {
  Serial.println(">> Nhan lenh: OFF");
  digitalWrite(ledPin, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void handleStatus() {
  float temp = 27.5;   // ví dụ, sau này thay bằng cảm biến thật
  String msg = "Temp=" + String(temp);

  Serial.println(">> Gui ve: " + msg);
  server.send(200, "text/plain", msg);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/status", handleStatus);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
