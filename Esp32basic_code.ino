#include <Arduino.h>     // Thư viện mặc định (ESP32 thường có sẵn)

#define CHAN_DEN 2       // Chân GPIO 2 nối LED
#define CHAN_NUT 15      // Chân GPIO 15 nối nút nhấn
int trangThaiNut = 0;        // Trạng thái đọc từ nút
int trangThaiNutCu = 0;      // Trạng thái nút lần trước
bool trangThaiDen = false;  // Đèn đang bật hay tắt
bool trangThaiNutTruoc = HIGH; // Kiểm tra trạng tháu nút trước
unsigned long thoiGianNhan = 0;
unsigned long doTreChongDoi = 50; // ms
void setup() {
  pinMode(CHAN_DEN, OUTPUT); 
  pinMode(CHAN_NUT, INPUT_PULLUP);

  Serial.begin(115200);
  Serial.println("ESP32 bat dau hoat dong");
}
void loop() {
  docNutNhan();
  xuLyBatTatDen();
}
// Xử lí riêng lẻ
void docNutNhan() {
  int giaTriDoc = digitalRead(CHAN_NUT);

  if (giaTriDoc != trangThaiNutCu) {
    thoiGianNhan = millis();
  }

  if (millis() - thoiGianNhan > doTreChongDoi) {
    trangThaiNut = giaTriDoc;
  }

  trangThaiNutCu = giaTriDoc;
}
void xuLyBatTatDen() {
  if (trangThaiNut == LOW && trangThaiNutTruoc == HIGH) {y
    trangThaiDen = !trangThaiDen;
    digitalWrite(CHAN_DEN, trangThaiDen);
  }
  trangThaiNutTruoc = trangThaiNut;
}
