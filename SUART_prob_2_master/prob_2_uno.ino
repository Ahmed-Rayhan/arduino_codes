#include <SoftwareSerial.h>
SoftwareSerial SUART (6,7);
const int LED1=2;

char pos[20];
void setup() 
{
    pinMode(2, OUTPUT);

Serial.begin(9600);
SUART.begin(9600);
};
int i=0;

void loop()
{
  
  //Serial.println("Guess Slider position ");
    if (Serial.available() > 0)
    {   for(i=0; i<5; i++)
        {
          pos[i]=Serial.read();
          
        }
    		pos[6]='\0';
    }
   
  Serial.println(pos);
  
  SUART.write(pos);
  char x[20];
  byte a= SUART.available();
  
  if(a!=0)
  
  {for(int i=0; i<a; i++)
    {
    x[i]=SUART.read();
   
  }
  
    Serial.print("nano sent ");
    Serial.println(x); 
  }
  bool z= strcmp(pos, x);
  if(z==0x00)
  { 
      digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  delay(2000);
}

