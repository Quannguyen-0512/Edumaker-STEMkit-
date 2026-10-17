# EduMaker STEMKit - Pin Mapping Reference

This is the reference data used as the companion chatbot's knowledge base (see AI Chatbot in the main README). It documents every port on the board and what it's wired to.

## Microcontroller

**ESP32-S3 N16R8**, programmed via Arduino IDE. Board setting: `ESP32S3 Dev Module`.

## Port map

| Port group                         | Pins                                                       | Typical use                                                                 |
| ---------------------------------- | ---------------------------------------------------------- | --------------------------------------------------------------------------- |
| L298 motor driver                  | ENA = 42, IN1 = 41, IN2 = 40, IN3 = 39, IN4 = 38, ENB = 37 | Drives the L298 motor driver                                                |
| Top row, right side (4× Type-C)    | SDA = 8, SCL = 9 (shared bus across all 4 ports)           | I2C peripherals (HEART, MPU6050, TEMP, RTC), usable for other functions too |
| Bottom row, right side (4× Type-C) | 14 (RAIN), 13 (LDR), 12 (FIRE), 11 (GAS)                   | Analog peripherals. The four ports are interchangeable analog inputs        |
| Rear (3× Type-C, paired)           | (18, 17) SIM, (16, 15) DF, (7, 6) SRF04 TRIG/ECHO          | Serial peripherals (SIM, DF) and the SRF04 ultrasonic sensor                |
| Rear (2× Type-C)                   | 5 (DHT11), 4 (DS18B20)                                     | One-wire sensors                                                            |
| Left side (4× Type-C)              | 47 (RELAY1), 48 (RELAY2), 35 (RELAY3), 36 (RELAY4)         | Relay outputs for lamp/fan models                                           |
| Bottom left (2× Type-C)            | Wired to the L298's left/right motor channels              | Motor base connector (board mounted vertically)                             |
| Buzzer                             | 21                                                         | Onboard alert buzzer, driven through a transistor                           |
| Front (2× Type-C)                  |                                                            | Code upload / flashing                                                      |
| Onboard                            | I2C 16x2 LCD and OLED headers; buttons on pin 1 (BTN1) and pin 2 (BTN2) | Built-in display and input                                     |

## Note on accent

The chatbot's prompt tells it to expect users speaking in a Mekong Delta / Southern Vietnamese accent, since that's who the kit is built for.
