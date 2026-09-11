# EduMaker STEMKit — Pin Mapping Reference

This is the actual reference data used to train the companion chatbot (see [AI Chatbot](../README.md#ai-chatbot) in the main README). It documents every port on the board and what it's wired to.

## Microcontroller

**ESP32-S3 N16R8**, programmed via Arduino IDE. Board setting: `ESP32S3 Dev Module`.

## Port map

| Port group | Pins | Typical use |
|---|---|---|
| L298 motor driver | ENA = 42, IN1 = 41, IN2 = 40, IN3 = 39, IN4 = 38, ENB = 37 | Drives the L298 motor driver |
| Top row, right side (4× Type-C) | SDA = 8, SCL = 9 (shared bus across all 4 ports) | I2C peripherals by default, but usable for other functions if needed |
| Bottom row, right side (4× Type-C) | 14, 13, 12, 11 | Analog peripherals |
| Rear (4× Type-C, paired) | (18, 17), (16, 15), (7, 6) | UART peripherals, one pair per port |
| Rear (2× Type-C) | 5, 4 | One-wire sensors such as DS18B20 and DHT11 |
| Left side (4× Type-C) | 47, 48, 35, 36 | Direct control outputs for lamp/fan models |
| Bottom left (2× Type-C) | Wired to the L298's left/right motor channels | Motor base connector (board mounted vertically) |
| Buzzer | 21 | Onboard alert buzzer |
| Front (2× Type-C) | | Code upload / flashing |
| Onboard | I2C 16x2 LCD; buttons on pin 1 and pin 2 | Built-in display and input |

## Note on accent

The chatbot is trained to expect users speaking in a Mekong Delta / Southern Vietnamese accent, since that's who the kit is built for.
