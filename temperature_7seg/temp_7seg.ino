byte LUT[] =
{
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
int digit1; int digit2;
void setup()
{ 
  Serial.begin(9600);
  analogReference(DEFAULT);
  for (int i = 6; i <= 15; i++)
    {
    pinMode(i, OUTPUT);
    }
  pinMode(A0, INPUT);
}
void loop() {
  int x = analogRead(A0);
  int T = (float)((100 * (5 / 1023.0)) * x);
  
  digit1 = T/10;  
  digit2 = T%10;
  Serial.print(digit1);
  byte y = LUT[digit1];
  PORTB = y;
  int m = bitRead(y, 6);
  digitalWrite(6, m);
  digitalWrite(7, bitRead(y, 7));
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  delay(10);

  byte z = LUT[digit2];
  PORTB = z;
  int n = bitRead(z, 6);
  digitalWrite(6, n);
  digitalWrite(7, bitRead(z, 7));
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  delay(10);
  
}
