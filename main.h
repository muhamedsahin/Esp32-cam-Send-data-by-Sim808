#define RXD2 14
#define TXD2 15
String SaatDeger = "";
void setup()
{
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);              // the GPRS baud rate   
  Serial.begin(9600);    // the GPRS baud rate 
 
  delay(1000);
}
 
void loop()
{
   Serial2.println("AT+SAPBR=3,1,APN,vodafone");
     while(Serial2.available())
 Serial.write(Serial2.read());
  delay(1000);
    Serial2.println("AT+SAPBR=1,1");
     while(Serial2.available())
 Serial.write(Serial2.read());
  delay(1000);
      Serial2.println("AT+HTTPINIT");
     while(Serial2.available())
 Serial.write(Serial2.read());
  delay(1000);
  Serial2.println("AT+HTTPPARA=\"CID\",1");
     while(Serial2.available())
 Serial.write(Serial2.read());
  delay(2000);
  Serial2.println("AT+HTTPPARA=URL,http://www.iforce2d.net/test.php");
     while(Serial2.available())
 Serial.write(Serial2.read());
  delay(5000);
  Serial2.println("AT+HTTPACTION=0");
     while(Serial2.available())
 Serial.write(Serial2.read());
  delay(3000);
   Serial2.println("AT+HTTPREAD=0,100");
        while(Serial2.available())
  SaatDeger = Serial2.readString();
  delay(2000);
  Serial.println(SaatDeger);
  } 
void ShowSerialData()
{
  while(Serial2.available()!=0)
  Serial.write(Serial2.read());
  delay(1500); 
  
}
