int ledArray[] = {3, 5, 6, 9, 10};
unsigned long timeArray[] = {20000, 10000, 5000, 200, 100};

int ledState[] = {LOW, LOW, LOW, LOW, LOW};
unsigned long previousMSec[] = {0, 0, 0, 0, 0};

void setup() {
    for (int ledN = 0; ledN < 5; ledN++) {
        pinMode(ledArray[ledN], OUTPUT);
    }
}

void loop() {
    for (int ledN = 0; ledN < 5; ledN++) {
        unsigned long currentMilliseconds = micros();
        if (currentMilliseconds - previousMSec[ledN] >= timeArray[ledN]){
            previousMSec[ledN] = currentMilliseconds;
            if (ledState[ledN] == LOW) {
                ledState[ledN] = HIGH;
            }
            else {
                ledState[ledN] = LOW;
            }
            digitalWrite(ledArray[ledN], ledState[ledN]);
        }
    }
}
