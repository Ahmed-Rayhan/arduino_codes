#include <Arduino.h>
void setup() 
{
  for(int i=0; i<=20; i++)
  {
    pinMode(i,OUTPUT);
  }
  
}

void loop()
{
    byte y=0x07;
    PORTD=y;
    bool m=bitRead(y,6);
    digitalWrite(6,m);
    digitalWrite(7, bitRead(y,7));
    digitalWrite(A0,LOW);
    digitalWrite(A1, HIGH);
    delay(10);

    byte z=0x07;
    PORTD=z;
    m=bitRead(z,6);
    digitalWrite(6,m);
    digitalWrite(7, bitRead(z,7));
    digitalWrite(A0,HIGH);
    digitalWrite(A1, LOW);
    delay(10);

    
}
