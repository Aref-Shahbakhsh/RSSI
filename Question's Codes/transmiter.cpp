#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "ESP32-Transmitter";
const char* password = "12345678";
WiFiUDP udp;

void setup() {
  Serial.begin(115200);

  // Start Wi-Fi Access Point
  /* TODO: Start WiFi AP with ssid and password */
  IPAddress apIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(apIP);

  /* TODO: Start UDP on port 4210 */
}

void loop() {
  /* TODO: Begin UDP packet (broadcast to 255.255.255.255, port 4210) */
  /* TODO: Send a message via UDP */
  /* TODO: End UDP packet */

  Serial.println("Packet sent!");
  delay(1000); // Send every 1 second
}
