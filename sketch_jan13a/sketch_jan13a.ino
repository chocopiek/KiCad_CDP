#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "CHOCOPIE 4283";
const char* password = "7T03m=88";

WebServer server(80);

const int tempPin = 23;   // GPIO23 (ADC)

void handleStatus() {
  int adcValue = analogRead(tempPin);

  // ESP32 ADC: 0–4095 tương ứng 0–3.3V
  float voltage = adcValue * (3.3 / 4095.0);

  // LM35: 10mV = 1°C
  float temperature = voltage * 100.0;

  String msg = "Temp=" + String(temperature, 1) + "C";

  Serial.println(">> Gui ve: " + msg);
  server.send(200, "text/plain", msg);
}

void setup() {
  Serial.begin(115200);

  analogReadResolution(12); // 12-bit ADC
  pinMode(tempPin, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  server.on("/status", handleStatus);
  server.begin();

  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
