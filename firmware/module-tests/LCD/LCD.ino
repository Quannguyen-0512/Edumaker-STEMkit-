#include <Wire.h>  // khai báo thư viện wire
#include <LiquidCrystal_I2C.h> // khai báo thư viện LCD 

LiquidCrystal_I2C lcd(0x27,16,2);  // khai báo địa chỉ I2C và kiểu màn hình LCD, 

void setup()
{
  lcd.init(); // khởi tạo thư viện LCD i2C
  lcd.backlight(); //bật đèn nền
  lcd.setCursor(0,0); // đặt vị trí con trỏ (cột, hàng)
  lcd.print("THCS NHON NGHIA");
  lcd.setCursor(0,1);
  lcd.print("CHIEM YEN NHI");
}


void loop()
{
  
}
