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
  DDRD=0xFF;
  pinMode(8, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(8, LOW);
  Serial.begin(9600);
}

void loop()
{
  int num1 = 0x12;
  int num2 = 0xD4;
  sum = num1 + num2;

  digit1 = (sum >> 4) & 0x0F;  
  digit2 = sum & 0x0F;         

  Serial.println(sum, HEX);
  Serial.println(digit1, HEX);
  Serial.println(digit2, HEX);
	bool Switch=digitalRead(LED);
      
  if (Switch == HIGH)
    {
        PORTD = LUT[digit1]; 
  delay(500);
  PORTD = LUT[digit2];  
  delay(500);
    }
  else if (Switch == LOW)
  {
    digitalWrite(8, LOW);
  };

}
