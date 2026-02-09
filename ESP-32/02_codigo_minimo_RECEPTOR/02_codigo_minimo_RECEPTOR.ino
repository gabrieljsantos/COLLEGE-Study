void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("Serial OK");
}

void loop() {
  if (Serial.available()) {
    int c = Serial.read();
    Serial.print("Recebido: ");
    Serial.println((char)c);
  }
}
