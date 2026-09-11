#define LDR  A3 //Ánh sáng
#define RAIN A2 //Mưa
#define FIRE A1 //Lửa
#define GAS  A0 //Gas

void setup() 
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(RAIN, INPUT);
  pinMode(FIRE, INPUT);
  pinMode(GAS, INPUT);
}

void loop() 
{
  Serial.print("Ánh sáng: "); Serial.print(analogRead(LDR));
  Serial.print("Độ ẩm đất: "); Serial.print(analogRead(RAIN));
  Serial.print("Lửa: "); Serial.print(analogRead(FIRE));
  Serial.print("Gas: "); Serial.print(analogRead(GAS));
  Serial.println();
}
