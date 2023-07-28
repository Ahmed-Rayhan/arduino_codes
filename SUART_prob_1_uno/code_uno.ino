#include <SoftwareSerial.h>
SoftwareSerial SUART (6,7);
const int LED=8;
int m, n;
void setup() 
{
Serial.begin(9600);
SUART.begin(9600);
};

void loop()
{
  Serial.println("Enter m ");
    if (Serial.available() > 0)
    {
    m = Serial.parseInt();
    }
   SUART.write(m);
   Serial.print("m = ");
   Serial.println(m);
  
  byte a= SUART.available();
  if(a!=0)
  {
    n=SUART.read();
  }
  Serial.print("n=");
  Serial.print(n);
  if(m>n)
  { 
    for(int i=1; i<=n; i++)
    {
      digitalWrite(8, HIGH);
      delay(1000);
      digitalWrite(8, LOW);
      delay(1000);
    }
    
  }
  delay(3000);
}