byte LUT[] =
{
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
  0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};
int sum; int digit1; int digit2;
void setup() {
  Serial.begin(9600);
  for (int i = 6; i <= 15; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int num1=0x23;
  int num2=0x42;
  sum=num1+num2;

  digit1 = sum/16;  
  digit2 = sum%16; 


  byte y = LUT[digit1];
  PORTB = y;
  int m = bitRead(y, 6);
  digitalWrite(6, m);
  digitalWrite(7, bitRead(y, 7));
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  delay(10);

  byte z = LUT[digit2];
  PORTB = z;
  int n = bitRead(z, 6);
  digitalWrite(6, n);
  digitalWrite(7, bitRead(z, 7));
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  delay(10);
}
