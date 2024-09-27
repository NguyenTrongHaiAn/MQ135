
#include "MQ135.h"  // Thêm thư viện

#define PIN_MQ135 A0   // Khai báo pin nối với chân AO của MQ-135
#define BUZZER_PIN 2    // Khai báo chân nối với buzzer
#define THRESHOLD 500  // Ngưỡng PPM để kích hoạt còi (bạn có thể thay đổi)

MQ135 mq135_sensor = MQ135(PIN_MQ135);   // Khai báo đối tượng thư viện

void setup() {
  Serial.begin(9600);   // Mở Serial Monitor
  pinMode(BUZZER_PIN, OUTPUT);  // Thiết lập chân buzzer là OUTPUT
}

void loop() {
  float ppm = mq135_sensor.getPPM();  // Đọc giá trị ppm
  Serial.print("PPM: ");
  Serial.print(ppm);
  Serial.println(" ppm");

  // Kiểm tra nếu giá trị PPM vượt ngưỡng
  if (ppm > THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);  // Kích hoạt còi
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Tắt còi
  }

  delay(500);  // Chờ 500ms trước khi đọc lại
}
