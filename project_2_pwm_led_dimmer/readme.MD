# Project 2: ESP32 PWM LED Dimmer

## Overview
[![Watch the video](https://img.youtube.com/vi/_QxMZr2dCBA/hqdefault.jpg)](https://youtu.be/_QxMZr2dCBA)

This project is an embedded systems exercise using an **ESP32 development board**, an **LED**, and a **pushbutton**. The firmware controls LED brightness using **Pulse Width Modulation (PWM)** and allows the user to cycle through predefined brightness levels with each button press.

The goal of this project is to build on the GPIO, button debouncing, and timing concepts from Project 1 while learning how PWM can control LED brightness.

----------

## What This Project Does

The ESP32 controls an LED connected to a GPIO output pin using PWM.

A button connected to an input pin is used to change the LED brightness.

Each press of the button advances to the next brightness level:

- **Level 0:** 0% — LED Off
- **Level 1:** 25% Brightness
- **Level 2:** 50% Brightness
- **Level 3:** 75% Brightness
- **Level 4:** 100% Brightness

After reaching 100% brightness, the next button press returns the LED to 0%.

The program continuously updates the button state and applies the selected brightness level to the LED. Serial output reports the selected brightness percentage.

----------

## Skills Learned / Concepts Practiced

### Pulse Width Modulation (PWM)

Learned how PWM controls LED brightness by rapidly switching a GPIO output between HIGH and LOW.

Practiced configuring PWM using the ESP32 Arduino framework's LED control (LEDC) functionality:

- Configured a PWM frequency of **500 Hz**.
- Set the PWM resolution to **8 bits**.
- Calculated the maximum duty-cycle value from the selected resolution.
- Used duty cycle to control the LED's perceived brightness.

### PWM Duty Cycle and Resolution

Learned how PWM resolution determines the range of available duty-cycle values.

With an 8-bit resolution, the duty cycle ranges from **0 to 255**, providing 256 possible values.

The firmware converts predefined brightness percentages into duty-cycle values:

- 0% brightness → duty cycle 0
- 25% brightness → approximately 64
- 50% brightness → approximately 128
- 75% brightness → approximately 191
- 100% brightness → duty cycle 255

These values control the proportion of each PWM cycle during which the output is HIGH.

### Button Debouncing

Continued using the [Bounce2](https://www.arduinolibraries.info/libraries/bounce2) library to handle mechanical button bounce.

Configured a **50 ms debounce interval** and set the button's pressed state to LOW because the input uses the ESP32's internal pull-up resistor.

This allows each button press to advance the brightness level without unintended repeated changes caused by contact bounce.

### State Management

Used a `mode` variable to track the currently selected brightness level.

An array stores the five available brightness percentages. Each button press increments the mode, and the mode resets to zero after the final brightness level.

This builds on the mode-control approach introduced in Project 1.

### Functions and Code Organization

Separated button-driven mode changes from LED brightness control using dedicated functions:

- `changeMode()` advances the selected brightness level and reports the new value over Serial.
- `led()` applies the selected brightness level using the ESP32 LEDC PWM functionality.

This keeps the main loop focused on reading button events and updating the LED.

### Serial Debugging

Used UART serial output at **115200 baud** to display the currently selected brightness percentage.

Serial logging provides feedback when testing the button and verifying that the brightness state changes as expected.

----------

## Hardware Required

- ESP32 Development Board
- Breadboard
- LED
- 1000Ω resistor
- Pushbutton
- Jumper wires
- USB data cable

----------

## Wiring

### LED Wiring

- ESP32 GPIO 23 → Resistor → LED anode (+)
- LED cathode (–) → GND

The LED is driven using PWM on GPIO 23 to control its brightness.

### Button Wiring

- ESP32 GPIO 22 → Button leg
- Other button leg → GND

The button uses the internal pull-up resistor, meaning:

- Not pressed = HIGH
- Pressed = LOW

----------

## How to Run

### Web (Wokwi)
Try my project online using [Wokwi](https://wokwi.com/projects/477907641201159169)

### PlatformIO

1. Clone this repository:

   ```bash
   git clone <repo_url>
   ```

2. Open the `project-02-pwm-led-dimmer` folder in VSCodium.
3. Ensure the PlatformIO IDE extension is installed.
4. Connect the ESP32 to your PC using a USB data cable.
5. Build and upload the firmware using PlatformIO.
6. Open the Serial Monitor and set the baud rate to `115200`.

### Arduino IDE

1. Install the ESP32 board package in Arduino IDE.
2. Select the board:
   - **ESP32 Dev Module**
3. Select the correct serial port.
4. Install the required libraries:
   - [Bounce2](https://www.arduinolibraries.info/libraries/bounce2)
   - [elapsedMillis](https://www.arduinolibraries.info/libraries/elapsed-millis)
5. Upload the sketch.
6. Open Serial Monitor at `115200` baud.

----------

## Expected Behavior

- The LED starts at 0% brightness.
- Each button press advances brightness to the next level.
- The LED progresses through 0%, 25%, 50%, 75%, and 100% brightness.
- After 100%, the next press returns the LED to 0%.
- Serial output reports the selected brightness percentage.
- Button debouncing prevents unintended multiple brightness changes from a single press.

----------