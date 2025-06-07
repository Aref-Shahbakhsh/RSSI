#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "ESP32-Transmitter";
const char* password = "12345678";
WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  /* TODO: Connect to transmitter AP using ssid and password */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to transmitter");

  udp.begin(4210);
  Serial.println("Listening for UDP packets...");
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize > 0) {
    char incoming[255];
    int len = /* TODO: Read UDP packet */;
    if (len > 0) {
      incoming[len] = '\0';
    }

    int rssi = /* TODO: Get RSSI value */;

    Serial.print("Received: ");
    Serial.print(incoming);
    Serial.print(" | RSSI: ");
    Serial.print(rssi);
    Serial.println(" dBm");
  }

  delay(100);
}
