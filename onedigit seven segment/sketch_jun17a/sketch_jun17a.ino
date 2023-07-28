// byte LUT[] = {
//     0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07,
//     0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
// };

// void setup() 
// {

// for (int i=6; i<15; i++)
// {
//   pinMode(i, OUTPUT);
// }

// }

// void loop() 
// {
// byte y;
// for(int i=0; i<=15; i++)
// {
//   y=LUT[i];
//   delay(1000);
// }
// PORTB=y;

// int n=bitRead(y, 6);
// digitalWrite(6,n);
// n=bitRead(y, 7);
// digitalWrite(7, bitRead(y,7));

// }

//Problem 3
byte LUT[]=
{
0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07,
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 
};

void setup()
{
 DDRD=0xFF;
 pinMode(8, OUTPUT);
 digitalWrite(8, LOW);   
	
//for(int i=0; i<16; i++)
 // {
   PORTD=LUT[0];
  //  delay(800);
 // }
	
  //digitalWrite(8,HIGH);

}

void loop()
{}