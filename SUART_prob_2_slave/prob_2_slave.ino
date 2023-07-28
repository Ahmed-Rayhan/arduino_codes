#include <SoftwareSerial.h>
SoftwareSerial SUART(6, 7);
const int LED2 = 10;
char x[10];

void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  SUART.begin(9600);
}

void loop() {

  if (digitalRead(3) == LOW) {
    x[5] = "left";
    Serial.println("Switch at left");

  } else {
    x[5] = "right";
    Serial.println("Switch at right");
  }

  SUART.write(x);

  char m[10];
  byte a = SUART.available();
  if (a != 0) {
    for (int i = 0; i < a; i++) {
      m[i] = SUART.read();
    }
    Serial.print("m = ");
    Serial.println(m);
  }

  bool z = strcmp(m, x);
  if (z == 0x01) {
    digitalWrite(11, LOW);
  } else {
    digitalWrite(11, HIGH);
  }
  delay(1000);
}
