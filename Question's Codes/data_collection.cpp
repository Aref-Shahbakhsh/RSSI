#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "ESP32-Transmitter";
const char* password = "12345678";
WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  /* TODO: Connect to transmitter */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  udp.begin(4210);
  Serial.println("\nConnected. Starting data logging...");
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char incoming[255];
    int len = udp.read(incoming, 255);
    incoming[len] = '\0';

    int rssi = /* TODO: Get RSSI */;

    float distance_label = 1.5; // <-- Manually update this during data collection

    // Log format: RSSI,Distance
    /* TODO: Print rssi */
    /* TODO: Print comma and distance */
  }
  delay(200);
}
