byte LUT[] = {
    0x3F, 0x06, 0x5B, 0x4F,
    0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C,
    0x39, 0x5E, 0x79, 0x71
};

const int segmentPins[] = {10, 9, 8, 7, 6, 5, 4};
const int numSegments = sizeof(segmentPins) / sizeof(segmentPins[0]);

void setup() {
    for (int i = 0; i < numSegments; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
    Serial.begin(9600);
}

void displayDigit(int digit) {
    if (digit >= 0 && digit <= 15) {
        byte hexCode = LUT[digit];
        for (int i = 0; i < numSegments; i++) {
            bool segmentState = bitRead(hexCode, i);
            digitalWrite(segmentPins[i], segmentState);
        }
    } else {
        for (int i = 0; i < numSegments; i++) {
            digitalWrite(segmentPins[i], LOW);
        }
    }
}

void loop() {
    if (Serial.available() > 0) {
        int number = Serial.parseInt();
        displayDigit(number);
        delay(500);  
        
        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}
