// Here is the link to the schematics: https://ibb.co/Gns7FFr


#include <Servo.h>

volatile long A;
Servo servos[] = {Servo(), Servo(), Servo()};
int servo_pins[] = {3, 6, 9};

float checkdistance_11_10() {
    digitalWrite(11, LOW);
    delayMicroseconds(2);
    digitalWrite(11, HIGH);
    delayMicroseconds(10);
    digitalWrite(11, LOW);
    return pulseIn(10, HIGH) / 58.00;
}

void setup() {
    A = 0;
    pinMode(11, OUTPUT);
    pinMode(10, INPUT);
    pinMode(12, OUTPUT);
    for (int i = 0; i < 3; ++i) {
        servos[i].attach(servo_pins[i]);
    }
}

void loop() {
    float distance = checkdistance_11_10();
    if (distance > 0 && distance < 200) { // Valid range for ultrasonic sensor
        if (distance < 20) {
            A = random(0, 3);
            tone(12, 131);
            delay(100);
            noTone(12);
            moveServo(A, 179); // Move to the extreme position
            delayWithServoRetry(1000); // Wait with retry for servo movement
            moveServo(A, 90); // Move back to the initial position
            delay(500);
        }
    }
}

void moveServo(int index, int angle) {
    servos[index].write(angle);
}

void delayWithServoRetry(unsigned long milliseconds) {
    unsigned long start_time = millis();
    while (millis() - start_time < milliseconds) {
        // Check if the servo movement is completed
        if (servos[A].read() == 90) {
            delay(10); // Small delay for stability
            return; // Exit the function if movement is completed
        }
    }
}
