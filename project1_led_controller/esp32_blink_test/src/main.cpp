#include <Arduino.h>
#include <elapsedMillis.h>
#include <Bounce2.h> 
Bounce2::Button button = Bounce2::Button(); // INSTANTIATE A Bounce2::Button OBJECT

// Prevent elapsed time from reset
elapsedMillis timeElapsed; 

// delay in milliseconds between blinks of the LED
unsigned int interval = 1000;

#define LED_PIN 32
boolean ledState = LOW;

#define BUTTON_PIN 26

//Store LED Behavior Mode
int mode = 0;

//Forward delcarations
void changeMode();
void led();

void setup() {
  // put your setup code here, to run once:
  // Start the serial communication at 115200 baud rate
  Serial.begin(115200);
  // Set ESP pins
  pinMode(LED_PIN, OUTPUT);
  button.attach(BUTTON_PIN, INPUT_PULLUP);
  button.interval(50); // 50ms interval
  button.setPressedState(LOW); // Set the pressed state to LOW (active LOW button)
}

void loop() {
  // put your main code here, to run repeatedly:
  // Update Button
  button.update();
  if (button.pressed()) {
    changeMode();
  }
  // Call LED function
  led();
}

// Function to change the LED behavior mode
void changeMode() {
  mode++;
  // Reset mode to 0 if it exceeds 2
  if (mode > 2) {
    mode = 0;
  }
  Serial.print("Mode changed to: ");
  Serial.println(mode);
}

void led() {
  if (mode == 0) {
    // Mode 0: LED is off
    digitalWrite(LED_PIN, LOW);
  } else if (mode == 1) {
    // Mode 1: LED is on
    digitalWrite(LED_PIN, HIGH);
  } else if (mode == 2) {
    // Mode 2: LED blinks
    if (timeElapsed > interval)
    {
      ledState = !ledState; // toggle the state from HIGH to LOW to HIGH to LOW ...
      digitalWrite(LED_PIN, ledState);
      timeElapsed = 0; // reset the counter to 0 so the counting starts over...
    }
  }
}