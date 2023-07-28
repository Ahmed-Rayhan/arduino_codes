byte LUT[] =
{
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
int sum;
int digit1;
int digit2;
const int LED=10;
int i;

void setup()
{
  for(int i=6; i<=15; i++)
    {
      pinMode(i, OUTPUT);
    }

    pinMode(A0, OUTPUT);
    pinMode(A1, INPUT);
    digitalWrite(A0, LOW);
}

void loop()
{
  int num1 = 0x12;
  int num2 = 0xD4;
  sum = num1 + num2;

  digit1 = (sum >> 4) & 0x0F;  
  digit2 = sum & 0x0F;         

  bool SwitchState=digitalRead(A1);
  if (SwitchState==HIGH)
  {
  byte y=LUT[digit1];
  PORTB=y;
  int n=bitRead(y, 6);
  digitalWrite(6, n);
  digitalWrite(7, bitRead(y, 7));

  delay(500);

  byte z=LUT[digit2];
  PORTB=z;
  int m=bitRead(z, 6);
  digitalWrite(6, m);
  digitalWrite(7, bitRead(z, 7));

  delay(500);
  }
  else
  {
    digitalWrite(A0, LOW);
  };

}