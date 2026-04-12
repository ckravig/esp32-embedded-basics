
# Project 1: ESP32 LED Mode Controller (Button + Debounce)

## Overview
[![Watch the video](https://img.youtube.com/vi/RIophxl7fDM/hqdefault.jpg)](https://www.youtube.com/embed/RIophxl7fDM)

This project is a beginner embedded systems exercise using an **ESP32 development board**, an **LED**, and a **pushbutton**. The firmware cycles through multiple LED behaviors (modes) each time the button is pressed.

The goal of this project is to build confidence working with GPIO, embedded timing, and clean firmware structure.

----------

## What This Project Does

The ESP32 controls an LED connected to a GPIO output pin.

A button connected to an input pin is used to change LED behavior.

Each press of the button advances the LED to the next mode:

Example modes:

-   **Mode 0:** LED Off
-   **Mode 1:** LED On
-   **Mode 2:** Blink

The program loops continuously and updates the LED based on the current mode.

----------

## Skills Learned / Concepts Practiced

### GPIO Input and Output

-   Configured an ESP32 GPIO pin as an output to drive an LED.
-   Configured a GPIO pin as an input to read a pushbutton state.


### Button Debouncing

Mechanical pushbuttons often generate rapid noise ("bounce") when pressed or released.  
This project implements **software debounce logic** using the [Bounce2](https://www.arduinolibraries.info/libraries/bounce2) library to ensure a single press results in only one mode change.

### State Machines / Mode Control

Implemented a simple firmware state machine using a `mode` variable to represent the current LED behavior.

### Timing and Delay Management

Learned the difference between:

-   simple blocking delays (`delay()`)
-   non-blocking timing using the [elapsedMillis](https://www.arduinolibraries.info/libraries/elapsed-millis) library

### Serial Debugging

Used UART serial logging to print button events and mode changes, improving debugging and visibility into program behavior.

----------

## Hardware Required

-   ESP32 Development Board
-   Breadboard
-   LED
-   1000Ω resistor
-   Pushbutton
-   Jumper wires

----------

## Wiring

### LED Wiring

-   ESP32 GPIO (LED_PIN) → Resistor → LED anode (+)
-   LED cathode (–) → GND

### Button Wiring

-   ESP32 GPIO (BUTTON_PIN) → Button leg
-   Other button leg → GND

The button pin uses an internal pull-up resistor, meaning:

-   Not pressed = HIGH
-   Pressed = LOW

----------

## How to Run

### Web (Wokwi)
Try my project online using [Wokwi](https://wokwi.com/projects/460939814703764481)

### PlatformIO

1.  Clone this repository:
    
    git clone <repo_url>
    
2.  Open the project folder in VS Code.
3.  Ensure the PlatformIO extension is installed.
4.  Connect the ESP32 to your PC via USB.
5.  Build and upload:
    -   Click **Upload** in PlatformIO
6.  Open the serial monitor:
    -   Set baud rate to `115200` (or whatever your code uses)

### Arduino IDE 

1.  Install the ESP32 board package in Arduino IDE.
2.  Select board:
    -   **ESP32 Dev Module**
3.  Select the correct COM port.
4.  Upload the sketch.
5.  Open Serial Monitor (baud rate must match code).

----------

## Expected Behavior

-   LED changes behavior each time the button is pressed.
-   Serial output logs mode changes for debugging.
-   Debounce prevents accidental multiple mode changes from a single press.
