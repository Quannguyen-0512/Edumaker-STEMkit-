void setup() {
  pinMode(36, OUTPUT); digitalWrite(36, 0);
  pinMode(35, OUTPUT); digitalWrite(35, 0);
  pinMode(48, OUTPUT); digitalWrite(48, 0);
  pinMode(47, OUTPUT); digitalWrite(47, 0);

}

void loop() {
  digitalWrite(36, 1); delay(500);
  digitalWrite(35, 1); delay(500);
  digitalWrite(48, 1); delay(500);
  digitalWrite(47, 1); delay(500);

  digitalWrite(36, 0); delay(500);
  digitalWrite(35, 0); delay(500);
  digitalWrite(48, 0); delay(500);
  digitalWrite(47, 0); delay(500);
}
