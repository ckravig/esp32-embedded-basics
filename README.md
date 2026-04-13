# ESP32 Embedded Systems Portfolio Projects

## Overview

This repository contains a collection of embedded systems projects built using an **ESP32 development board**. The purpose of these projects is to develop hands-on experience with embedded firmware concepts including GPIO, timers, interrupts, communication protocols, and real-time design patterns.

Each project is stored in its own folder with:

-   source code
-   wiring documentation
-   a dedicated README explaining functionality and what was learned

This repo is intended to serve as both a learning archive and a portfolio for embedded/firmware development.

----------

## Hardware Platform

-   ESP32 Dev Board (ESP-WROOM-32)
-   Breadboard + jumper wires
-   LEDs, resistors, pushbuttons
-   Common sensors and modules from an ESP32 starter kit

----------

## Development Environment

This repository is designed to be built using:

-   **VS Code + PlatformIO** (recommended)

PlatformIO provides a structured workflow similar to professional embedded development environments.

----------

## Repository Structure

esp32-embedded-projects/  
│  
├── project1_led_controller/  
│   ├── src/  
│   ├── include/  
│   ├── platformio.ini  
│   └── README.md  
│  
├── project2_pwm_dimmer/  
│   ├── src/  
│   ├── include/  
│   ├── platformio.ini  
│   └── README.md  
│  
└── README.md

Each project folder is intended to be a standalone PlatformIO project.

----------

## Projects

### Project 1: LED Mode Controller (GPIO + Button Debounce)

**Description:**  
A simple firmware project that controls an LED using multiple modes (off, on, blink patterns). A pushbutton is used to cycle through the modes. This project includes software debouncing and serial logging for debugging.

**Concepts practiced:**

-   GPIO input/output
-   internal pull-up resistors
-   software debouncing
-   mode/state tracking
-   serial debugging over UART

📁 Location: `project1_led_controller/`

----------

## Current Learning Roadmap

This repo follows a structured roadmap designed to build embedded skills in a portfolio-friendly way:

### Project 1: Embedded Fundamentals + GPIO

-   GPIO input/output
-   debouncing
-   timing (`delay()` vs `millis()`)
-   basic state machines

### Project 2+: Protocols and Peripheral Communication

-   UART, I2C, SPI
-   sensor interfacing
-   reading datasheets

### Project 3+: Timers, Interrupts, and Real-Time Design

-   event-driven design
-   superloop architecture
-   ring buffers

### Project 4+: FreeRTOS

-   tasks, queues, semaphores
-   real-time scheduling patterns

----------

## How to Build and Upload (PlatformIO)

### Prerequisites

-   Install **VS Code**
-   Install the **PlatformIO IDE extension**

### Uploading a project

1.  Open the desired project folder in VS Code  
    (example: `project1_led_controller/`)
2.  Connect the ESP32 board via USB
3.  Build and upload using PlatformIO:
    -   Click **Upload**
4.  Monitor serial output:
    -   Click **Serial Monitor**

----------

## Goals of This Repository

-   Develop strong embedded C/C++ fundamentals
-   Build reusable firmware patterns (drivers, state machines, timing)
-   Learn debugging workflows (serial logs, logic analyzer, etc.)
-   Produce documented portfolio projects suitable for embedded job applications

----------

## Future Improvements / Planned Projects

As additional projects are completed, they will be added here along with documentation and demo results.
