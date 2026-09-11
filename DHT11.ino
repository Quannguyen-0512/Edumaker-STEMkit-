#include "DHT.h"
#include <Wire.h>  // khai báo thư viện wire
#include <LiquidCrystal_I2C.h> // khai báo thư viện LCD 
#define DHTPIN 11     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  lcd.init(); // khởi tạo thư viện LCD i2C
  pinMode(13, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  lcd.backlight(); //bật đèn nền
  lcd.setCursor(0,0); // đặt vị trí con trỏ (cột, hàng)
  lcd.print("Nhiet do: ");
  lcd.setCursor(10,0); // đặt vị trí con trỏ (cột, hàng)
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
  lcd.setCursor(7,1);
  lcd.print(h);
if (t >= 33) {
    digitalWrite(13, HIGH);
} else {
   digitalWrite(13, LOW);;
}
}
