#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "ESP32-Transmitter";
const char* password = "12345678";
WiFiUDP udp;

const float RSSI_MEAN = -60.0;
const float RSSI_STD = 5.0;

constexpr int tensor_arena_size = 2 * 1024;
uint8_t tensor_arena[tensor_arena_size];

/* TODO: use the content of model_data.h, you will see two araies the first one is your ml model, use it and rename it as g_model */;

const tflite::Model* model = tflite::GetModel(g_model);
tflite::AllOpsResolver resolver;
tflite::MicroInterpreter interpreter(model, resolver, tensor_arena, tensor_arena_size);
TfLiteTensor* input;
TfLiteTensor* output;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  udp.begin(4210);

  interpreter.AllocateTensors();
  input = interpreter.input(0);
  output = interpreter.output(0);
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    udp.read(new char[255], 255);
    int rssi = /* TODO: Get live RSSI */;

    float norm_rssi = (rssi - RSSI_MEAN) / RSSI_STD;
    input->data.f[0] = norm_rssi;

    TfLiteStatus status = /* TODO: Run inference */;
    if (status != kTfLiteOk) {
      Serial.println("Inference failed!");
      return;
    }

    float predicted_distance = /* TODO: Read predicted output */;
    Serial.print("RSSI: ");
    Serial.print(rssi);
    Serial.print(" → Predicted distance: ");
    Serial.print(predicted_distance);
    Serial.println(" m");
  }

  delay(200);
}
