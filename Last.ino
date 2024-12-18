#include "SPIFFS.h"
#include <ESP32Servo.h>

#define NUM_MOTORS 3
Servo motors[NUM_MOTORS];
int motorPins[NUM_MOTORS] = {25, 4, 32}; // Replace with your motor control pins

void setup() {
    Serial.begin(115200);

    // Initialize motors
    for (int i = 0; i < NUM_MOTORS; i++) {
        motors[i].attach(motorPins[i]);
        motors[i].write(0); // Initialize all motors to 0 degrees
        delay(100);
    }

    // Mount SPIFFS
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS Mount Failed");
        return;
    }

    // Write a test file
    File file = SPIFFS.open("/test.txt", FILE_WRITE);
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }
    file.print("abcdefghijklmnopqrstuvwxyz "); // Example Braille characters
    file.close();
    Serial.println("File written successfully!");

    // Read the file
    file = SPIFFS.open("/test.txt", FILE_READ);
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    Serial.println("File Content:");
    String fileContent = "";
    while (file.available()) {
        char c = file.read();
        Serial.write(c);
        fileContent += c;
    }
    file.close();

    // Process the file content and control motors
    controlMotorsForBraille(fileContent);
}

void loop() {}

// Controls motors based on Braille text
void controlMotorsForBraille(String text) {
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        setMotorAngles(c);
        delay(3000); // Pause for 2.5 seconds to let the user read
        resetMotors();
        delay(3000);
    }
}

// Sets motor angles for a given character
void setMotorAngles(char ch) {
    int angles[NUM_MOTORS] = {0, 0, 0}; // Default motor positions

    // Define motor angle logic for each character
    switch (ch) {
        case 'a': angles[0] = 45; break;
    case 'b': angles[0] = 45; angles[1] = 45; break;
    case 'c': angles[0] = 135; angles[2] = 0; break;
    case 'd': angles[0] = 135; angles[1] = 90; angles[2] = 0; break;
    case 'e': angles[0] = 45; angles[1] = 90; break;
    case 'f': angles[0] = 135; angles[1] = 45; angles[2] = 0; break;
    case 'g': angles[0] = 135; angles[1] = 135; angles[2] = 0; break;
    case 'h': angles[0] = 45; angles[1] = 135; break;
    case 'i': angles[0] = 90; angles[1] = 45; break;
    case 'j': angles[0] = 90; angles[1] = 135; break;
    case 'k': angles[0] = 45; angles[2] = 45;break;
    case 'l': angles[0] = 45; angles[1] = 45; angles[2] = 45; break;
    case 'm': angles[0] = 135; angles[2] = 45; break;
    case 'n': angles[0] = 135; angles[1] = 90; angles[2] = 45; break;
    case 'o': angles[0] = 45; angles[1] = 90; angles[2] = 45; break;
    case 'p': angles[0] = 135; angles[1] = 45; angles[2] = 45; break;
    case 'q': angles[0] = 135; angles[1] = 135; angles[2] = 45; break;
    case 'r': angles[0] = 45; angles[1] = 135; angles[2] = 45; break;
    case 's': angles[0] = 90; angles[1] = 45; angles[2] = 45; break;
    case 't': angles[0] = 90; angles[1] = 135; angles[2] = 45; break;
    case 'u': angles[0] = 45; angles[2] = 135; break;
    case 'v': angles[0] = 45; angles[1] = 45; angles[2] = 135; break;
    case 'w': angles[0] = 90; angles[1] = 135; angles[2] = 90; break;
    case 'x': angles[0] = 135; angles[2] = 135; break;
    case 'y': angles[0] = 135; angles[1] = 90; angles[2] = 135; break;
    case 'z': angles[0] = 45; angles[1] = 90; angles[2] = 135;  break;
    case ' ': break; // Space, keep motors in reset position
    default:
            Serial.println("Unknown character, skipping...");
            return;
    }

    // Move motors to defined angles
    for (int i = 0; i < NUM_MOTORS; i++) {
        motors[i].write(angles[i]);
    }
}

// Resets all motors to the default position
void resetMotors() {
    for (int i = 0; i < NUM_MOTORS; i++) {
        motors[i].write(0); // Reset all motors to 0 degrees
    }
}
