#define ENA 37
#define IN1 39
#define IN2 38
#define IN3 40
#define IN4 41
#define ENB 42

void setup() 
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 8, 9);

  pinMode(ENA, OUTPUT); digitalWrite(ENA,1);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT); digitalWrite(ENB,1);
}

void loop() 
{
  if (Serial2.available()) 
  {
    char DATA = Serial2.read();


    if(DATA == 'G') {GO();}
    if(DATA == 'B') {BACK();}
    if(DATA == 'L') {LEFT();}
    if(DATA == 'R') {RIGHT();}
    if(DATA == 'S') {STOP();}
  }
}
