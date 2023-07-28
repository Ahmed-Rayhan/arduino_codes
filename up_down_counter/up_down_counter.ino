byte LUT[] = {
    0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
byte j;
int z=15;

void setup()  
{
 Serial.begin(9600);
 for(int i=6; i<15; i++)
 {
   pinMode(i, OUTPUT);
 }
  pinMode(5, INPUT);
  showDigit(LUT[j]);
  pinMode(4,INPUT);

}

void loop() 
{
  while (digitalRead(5) != HIGH)
  {
    ;//wait
  }
  Serial.println("Pressed");
  delay(500);
  j++;
  if(j==0x10)
  {
    while (digitalRead(4) != HIGH)
  {
    ;//wait
  }
  j--;
  }
  showDigit(LUT[j]);
}

void showDigit(byte y)
{
  PORTB=y;
  int n=bitRead(y,6);
  digitalWrite(6,n);
  n=bitRead(y, 7);
  digitalWrite(7,n);
}