#include <WiFiManager.h>

#define BOOT_BUTTON 9  // Boot button GPIO on ESP32-C6

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(BOOT_BUTTON, INPUT_PULLUP);

  // If boot button held during startup, clear saved WiFi
  if (digitalRead(BOOT_BUTTON) == LOW) {
    Serial.println("Boot button held — clearing saved WiFi...");
    WiFiManager wm;
    wm.resetSettings();
    Serial.println("Cleared! Release the button. Restarting...");
    delay(2000);
    ESP.restart();
  }

  Serial.println("Booting normally...");

  WiFiManager wm;
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
  // Nothing needed here
}