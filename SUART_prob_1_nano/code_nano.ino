#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial SUART (6,7);
byte m, n;

void setup() 
{
Serial.begin(9600);
SUART.begin(9600);
}

void loop() 
{  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  Serial.println("Enter n ");
    if (Serial.available() > 0)
    {
    n = Serial.parseInt();
    }
  Serial.print("n = ");
  Serial.println(n);
  SUART.write(n); 
  byte a= SUART.available();
  if(a!=0)
  {
    m=SUART.read();
  }
   Serial.print("m = ");
   Serial.println(m);
  if(m<=n)
  { 
    lcd.print(m);
  }
  delay(3000);
}
