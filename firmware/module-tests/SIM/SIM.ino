String ADMIN = "0941841546";            //Số ĐT ADMIN


void setup() {
  
  Serial.begin(9600);
  Serial.println("Test Module SIM800L"); 

  for(int i=5; i>0; i--){Serial.println(i); delay(1000);}

  Serial2.begin(115200);
  Serial2.println("AT+CMGF=1");                delay(100);
  Serial2.println("AT+CNMI=2,2,0,0,0");        delay(100);
  Serial2.println("AT+CMGL=\"REC UNREAD\"");   delay(100);
  Serial2.println("AT+CMGD=1,4");              delay(100);

  Serial2.println("AT+CMGF=1"); delay(500);
  Serial2.println("AT+CMGS=\"" + ADMIN + "\"\r"); delay(500);
  Serial2.println("SIM OK");
  Serial2.println((char)26); delay(2500);

  // SIMSerial.print (F("ATD"));
  // SIMSerial.print (ADMIN);
  // SIMSerial.print (F(";\r\n"));
  // delay(20000);
  // SIMSerial.print (F("ATH"));
  // SIMSerial.print (F(";\r\n"));
  // delay(500);
}

void loop() {
  while(Serial2.available())
  {
    String inputString;
    while(Serial2.available()){inputString = Serial2.readString();}
    delay(65);
    Serial.println(inputString);
  }

  while(Serial.available())
  {
    Serial2.println(Serial.readString()); 
  }
}

 
