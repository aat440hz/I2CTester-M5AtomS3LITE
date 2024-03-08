#include <M5AtomS3.h>
#include "Wire.h"

void setup() {
    Serial.begin(115200); // Initialize serial communication at 115200 baud rate
    AtomS3.begin(); // Init M5Atom. For AtomS3LITE, initialization of internal I2C is also included.
    Wire.begin(2, 1); // Detect external I2C, if this sentence is not added, detect internal I2C.
    Serial.println("M5AtomS3LITE I2C Scanner"); // Print a string to the serial monitor.
    delay(3000);
}

void loop() {
    int address;
    int error;
    Serial.println("\nScanning I2C Addresses [HEX]...");
    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address); // Start transmission to device
        error = Wire.endTransmission(); // Stop transmission and capture any error code

        if (error == 0) {
            Serial.print("Found I2C device at 0x");
            if(address < 16) Serial.print("0"); // Print leading zero for addresses less than 0x10
            Serial.println(address, HEX);
        } else {
            Serial.print("."); // Indicate a scan with no device found
        }

        delay(10);
    }
    Serial.println("\nScan Complete.");
    delay(1000);
}