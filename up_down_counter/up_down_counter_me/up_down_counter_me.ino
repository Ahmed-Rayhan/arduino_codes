byte LUT[] = {
    0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
int digit, value=0;
int up=A1;
int down=A2;
int y;
void setup()
{
  Serial.begin(9600);
     for(int i=6; i<=15; i++)
    {
      pinMode(i, OUTPUT);
    }

  pinMode(up, INPUT);
  pinMode(down, INPUT);

  digit=LUT[value];

}

void loop() 
{
  
  if(digitalRead(up) == HIGH)
  {
    value++;
    Serial.print(value);
   y=LUT[value];
   PORTB=y;
   digitalWrite(6, bitRead(y, 6));
   digitalWrite(7, bitRead(y, 7));
   delay(1000);
  }
  else if(digitalRead(down) == HIGH)
  {
    value--;
    Serial.print(value);
  }
   y=LUT[value];
   PORTB=y;
   digitalWrite(6, bitRead(y, 6));
   digitalWrite(7, bitRead(y, 7));
   delay(1000);
}
