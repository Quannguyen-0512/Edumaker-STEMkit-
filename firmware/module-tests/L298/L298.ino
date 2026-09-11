#define ENA 37
#define IN1 38
#define IN2 39
#define IN3 40
#define IN4 41
#define ENB 42

void setup() 
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop() 
{
  for(int i = 0; i<255; i++)
  {
    analogWrite(ENB, i);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(10);
  }

  for(int i = 255; i>0; i--)
  {
    analogWrite(ENB, i);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
    delay(10);
  }
}
