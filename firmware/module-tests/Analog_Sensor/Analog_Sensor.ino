// Analog sensor test for the EduMaker STEMKit board (ESP32-S3).
// The four analog ports are on the bottom row, right side of the board.
#define RAIN 14  // Rain sensor
#define LDR  13  // Light sensor (LDR)
#define FIRE 12  // Fire (flame) sensor
#define GAS  11  // Gas sensor

void setup() 
{
  Serial.begin(9600);
  pinMode(RAIN, INPUT);
  pinMode(LDR, INPUT);
  pinMode(FIRE, INPUT);
  pinMode(GAS, INPUT);
}

void loop() 
{
  Serial.print("Light: "); Serial.print(analogRead(LDR));
  Serial.print(", Rain: "); Serial.print(analogRead(RAIN));
  Serial.print(", Fire: "); Serial.print(analogRead(FIRE));
  Serial.print(", Gas: "); Serial.print(analogRead(GAS));
  Serial.println();
}
