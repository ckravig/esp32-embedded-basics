#include <Arduino.h>
#include <elapsedMillis.h>
#include <Bounce2.h> 
Bounce2::Button button = Bounce2::Button(); // INSTANTIATE A Bounce2::Button OBJECT

// Prevent elapsed time from reset
elapsedMillis timeElapsed; 

// Pin Variables
#define LED_PIN 23
//boolean ledState = LOW;

#define BUTTON_PIN 22

// PWM Variables
const int PWM_FREQ = 500;
const int PWM_RESOLUTION = 8;

// The max duty cycle value based on PWM resolution
const int MAX_DUTY_CYCLE = (1 << PWM_RESOLUTION) - 1;

const double BRIGHTNESS_LEVELS[] = {0.0, 0.25, 0.50, 0.75, 1.0};

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
  //pinMode(LED_PIN, OUTPUT);
  
  ledcAttach(LED_PIN, PWM_FREQ, PWM_RESOLUTION);

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
  if (mode > 4) {
    mode = 0;
  }
  Serial.print("Brightness changed to: ");
  Serial.print(BRIGHTNESS_LEVELS[mode] * 100, 0);  // 0 = no decimal places
  Serial.println("%");
}

void led() {
  ledcWrite(LED_PIN, MAX_DUTY_CYCLE * BRIGHTNESS_LEVELS[mode]);
}