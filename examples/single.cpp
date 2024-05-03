#include "Arduino.h"
#include "ESP32Timers.h"

// Create an instance of the TimerSingle class
Timers::TimerSingle timer1(1000);

void setup() {
  // Setup the serial port
  Serial.begin(115200);

  // Initialize the filesystem
  SPIFFS.begin();
}

void loop() {
  // Check if the timer has reached its interval
  if (timer1.isTime()) {
    // Print a message to the serial port
    Serial.println("Timer 1 has reached its interval");
  }

  delay(100); // Make shure to avoid a busy loop
}