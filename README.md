Digital Input to Tactile Feedback Project
Project Overview
This project aims to create a cost-effective and accessible device that translates digital text into tactile Braille feedback for visually impaired individuals. By leveraging an ESP32 microcontroller, servo motors, and a real-time processing system, the device enhances Braille literacy and bridges the gap between digital content and tactile learning.

Key Features
Real-Time Text-to-Braille Conversion:
Reads text files from local storage (SPIFFS) and dynamically converts characters into tactile Braille patterns.

Accurate Servo Motor Control:
Three servo motors actuate Braille dots precisely using PWM signals.

Compact and Cost-Effective Design:
Utilizes commonly available components like ESP32 and servo motors, making it affordable and portable.

Energy Efficiency:
Designed for low power consumption, increasing usability and sustainability.

System Architecture
Components Used
ESP32: Central controller for processing and motor control.
Servo Motors: Three servos actuating Braille dots.
SPIFFS: Local storage for .txt files to read input text.
Workflow
Read Input: Text data is read from a .txt file stored in SPIFFS.
Mapping: Each character is mapped to its corresponding Braille pattern.
Actuation: Servo motors actuate the Braille dots based on the mapped pattern.
Feedback: The system provides tactile feedback in real-time for Braille reading.

Setup Instructions
Hardware Requirements:

ESP32 board
3 servo motors
Power supply
Connecting wires
Software Requirements:

Arduino IDE
Libraries: Servo.h, FS.h, SPIFFS.h
Installation Steps:

Install the ESP32 board package in the Arduino IDE.
Upload the .txt file to SPIFFS.
Flash the code to the ESP32.
Connect the servo motors to appropriate GPIO pins.
Code Structure
main.ino:
Core logic for reading the text file, mapping characters, and controlling the servos.

braille_mapping.h:
Contains mappings of characters to Braille patterns.
