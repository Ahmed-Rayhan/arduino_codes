#include <Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
    lcd.init();
    lcd.backlight();

}

void loop() 
{
  
    lcd.setCursor(0, 0);
    lcd.print("Aj amar");

    lcd.setCursor(0, 1);
    delay(1000);
    
    lcd.print("MON BHALO NEI ");
    delay(1000);

    lcd.setCursor(0, 0);
    lcd.print("                   ");
    lcd.setCursor(0, 1);
    lcd.print("                   ");
    delay(1000);

    lcd.setCursor(0, 0);
    lcd.print("aaaaaaaaaaa");
    delay(1000);
}
