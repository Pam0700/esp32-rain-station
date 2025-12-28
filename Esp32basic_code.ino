#define LED_PIN 2 // Khai báo chân code

void setup() {
  pinMode(LED_PIN, OUTPUT); // Khai báo chân 
  // tín hiệu đầu ra
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // LED ON
  delay(1000);                 // chờ 1 giây
  digitalWrite(LED_PIN, LOW);  // LED OFF
  delay(1000);                 // chờ 1 giây
}
