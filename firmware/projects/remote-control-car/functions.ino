void GO()
{
  digitalWrite(IN1, 1); digitalWrite(IN2, 0);
  digitalWrite(IN3, 1); digitalWrite(IN4, 0);
}
 

void BACK()
{
  digitalWrite(IN1, 0); digitalWrite(IN2, 1);
  digitalWrite(IN3, 0); digitalWrite(IN4, 1);
}


void LEFT()
{
  digitalWrite(IN1, 0); digitalWrite(IN2, 1);
  digitalWrite(IN3, 1); digitalWrite(IN4, 0);
}


void RIGHT()
{
  digitalWrite(IN1, 1); digitalWrite(IN2, 0);
  digitalWrite(IN3, 0); digitalWrite(IN4, 1);
}


void STOP()
{
  digitalWrite(IN1, 0); digitalWrite(IN2, 0);
  digitalWrite(IN3, 0); digitalWrite(IN4, 0);
}