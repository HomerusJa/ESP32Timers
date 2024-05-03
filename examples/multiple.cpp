#include "Arduino.h"
#include "ESP32Timers.h"
#include "SPIFFS.h" // Used as a filesystem

// Create an instance of the Timers class
Timers::Timers timers(SPIFFS, "timer_state.json");

void setup() {
  // Setup the serial port
  Serial.begin(115200);

  // Initialize the filesystem
  SPIFFS.begin();

  // Load the state of the timers
  timers.addTimer("timer1", 1000); // Add a timer with an interval of 1000 ms
  timers.addTimer("timer2", 1500); // Add a timer with an interval of 1500 ms
}

void loop() {
  // Check if the timer has reached its interval
  if (timers.isTime("timer1")) {
    // Print a message to the serial port
    Serial.println("Timer 1 has reached its interval");
  }

  // Check if the timer has reached its interval
  if (timers.isTime("timer2")) {
    // Print a message to the serial port
    Serial.println("Timer 2 has reached its interval");
  }

  delay(100); // Make shure to avoid a busy loop
}