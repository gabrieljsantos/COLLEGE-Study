#include <esp_now.h>
#include <WiFi.h>

uint8_t peer_mac[] = {0x24, 0x6F, 0x28, 0xAA, 0xBB, 0xCC};  // coloque o MAC do receptor

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  esp_now_init();

  esp_now_peer_info_t peer{};
  memcpy(peer.peer_addr, peer_mac, 6);
  peer.channel = 0;
  peer.encrypt = false;
  esp_now_add_peer(&peer);

  uint8_t data = 42;  // dado mínimo
  esp_now_send(peer_mac, &data, 1);
}

void loop() {}
