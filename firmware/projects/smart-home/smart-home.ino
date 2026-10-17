//-------------------------------------------------------------------------------------------------------- Blynk
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
//-------------------------------------------------------------------------------------------------------- Màn hình
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//-------------------------------------------------------------------------------------------------------- Cảm biến DHT11
#include "DHT.h"
DHT dht(5, DHT11);
//-------------------------------------------------------------------------------------------------------- Biến toàn cục
unsigned long timer; 
//-------------------------------------------------------------------------------------------------------- Thông tin kết nối (thay bằng giá trị thật trên máy bạn, không đưa lên GitHub)
#define MY_BLYNK_TOKEN  "YOUR_BLYNK_AUTH_TOKEN"
#define MY_WIFI_SSID    "YOUR_WIFI_SSID"
#define MY_WIFI_PASS    "YOUR_WIFI_PASSWORD"
#define MY_BLYNK_SERVER "YOUR_BLYNK_SERVER"
//-------------------------------------------------------------------------------------------------------- Khởi tạo ngoại vi
#define LAMP 47
#define FAN 48
#define GAS 14
#define FIRE 13
#define BUZZE 21

BLYNK_WRITE(V2){ digitalWrite(LAMP, param.asInt()); }
BLYNK_WRITE(V3){ digitalWrite(FAN, param.asInt()); }
void setup() 
{
//-------------------------------------------------------------------------------------------------------- Serial debug
  Serial.begin(9600);
//-------------------------------------------------------------------------------------------------------- Khởi động ngoại vi
  pinMode(LAMP, OUTPUT);
  pinMode(FAN, OUTPUT);
  pinMode(BUZZE, OUTPUT);
  pinMode(GAS, INPUT);
  pinMode(FIRE, INPUT);
//-------------------------------------------------------------------------------------------------------- Khởi động cảm biến nhiệt độ
  dht.begin();
//-------------------------------------------------------------------------------------------------------- Khởi động màn hình
  Wire.begin(8,9);
  lcd.init();                  
  lcd.backlight();
  lcd.setCursor(3,0); lcd.print("Hello, world!");
  delay(1000);
//-------------------------------------------------------------------------------------------------------- Server connecting
  Blynk.begin(MY_BLYNK_TOKEN, MY_WIFI_SSID, MY_WIFI_PASS, MY_BLYNK_SERVER, 8080);
  lcd.clear();
}

void loop() 
{
  Blynk.run();
//-------------------------------------------------------------------------------------------------------- Đọc gas và lửa
  int gas_value = analogRead(GAS);
  int fire_value = 4095-analogRead(FIRE);
//-------------------------------------------------------------------------------------------------------- Detection
  if(gas_value > 2000 || fire_value > 2000)
  {
    digitalWrite(BUZZE,1); delay(50);
    digitalWrite(BUZZE,0); delay(50);
  }
//-------------------------------------------------------------------------------------------------------- Đọc nhiệt độ, độ ẩm
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {Serial.println(F("Failed to read from DHT sensor!"));return;}
//-------------------------------------------------------------------------------------------------------- Monitor
  lcd.setCursor(0,0); lcd.print("H:"); lcd.print(h); 
  lcd.setCursor(0,1); lcd.print("T:"); lcd.print(t); 
  lcd.setCursor(9,0); lcd.print("G:"); lcd.print(gas_value); 
  lcd.setCursor(9,1); lcd.print("F:"); lcd.print(fire_value); 
//-------------------------------------------------------------------------------------------------------- Cloud send data
  if(millis()-timer > 500)
  {
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Blynk.virtualWrite(V4, gas_value);
    Blynk.virtualWrite(V5, fire_value);
    timer = millis();
  }
}
