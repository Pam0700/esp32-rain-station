#include <Arduino.h>

// ===== KHAI BAO CHAN =====
#define CHAN_DEN 2
#define CHAN_CAM_BIEN 15

// ===== BIEN TRANG THAI =====
bool trangThaiDen = false;

int trangThaiCamBien = LOW;
int trangThaiCamBienTruoc = LOW;

// ===== BIEN CHONG DOI =====
unsigned long thoiGianNhan = 0;
const unsigned long DO_TRE_CHONG_DOI = 50;

void setup() {
  pinMode(CHAN_DEN, OUTPUT);
  pinMode(CHAN_CAM_BIEN, INPUT);

  Serial.begin(115200);
  Serial.println("ESP32 bat dau hoat dong");
}

void loop() {
  docCamBien();
  xuLyBatTatDen();
}

// ===== DOC CAM BIEN (CO CHONG DOI) =====
void docCamBien() {
  int giaTriDoc = digitalRead(CHAN_CAM_BIEN);

  if (giaTriDoc != trangThaiCamBienTruoc) {
    thoiGianNhan = millis();
  }

  if (millis() - thoiGianNhan > DO_TRE_CHONG_DOI) {
    trangThaiCamBien = giaTriDoc;
  }

  trangThaiCamBienTruoc = giaTriDoc;
}

// ===== XU LY BAT TAT DEN =====
void xuLyBatTatDen() {
  static int trangThaiCuoi = LOW;

  if (trangThaiCamBien == HIGH && trangThaiCuoi == LOW) {
    trangThaiDen = !trangThaiDen;
    digitalWrite(CHAN_DEN, trangThaiDen);
  }

  trangThaiCuoi = trangThaiCamBien;
}
