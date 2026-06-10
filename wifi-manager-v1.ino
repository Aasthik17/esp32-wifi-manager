#include <WiFiManager.h>

void setup() {
  Serial.begin(115200);
  delay(300);

  WiFiManager wm;

  // Uncomment the line below ONLY when testing to clear saved WiFi
  // wm.resetSettings();

  bool connected = wm.autoConnect("ESP32-C6-Setup");

  if (!connected) {
    Serial.println("Failed to connect. Rebooting...");
    delay(3000);
    ESP.restart();
  }

  Serial.println("WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing needed here for now
}