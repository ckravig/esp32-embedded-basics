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

# Month 1: Embedded Fundamentals + C + GPIO

### Goal:

Understand microcontrollers, learn embedded C basics, and control hardware.

### Topics

- Embedded C basics (pointers, structs, bitwise ops)
- Memory mapped registers (conceptually)
- GPIO input/output
- Debouncing buttons
- Timers and interrupts (basic intro)

### Projects (portfolio-worthy mini projects)

✅ **Project 1: LED Controller**

- blink patterns
- button changes mode
- implement software debounce

✅ **Project 2: PWM LED dimmer**

- fade LED using PWM
- adjust brightness with button

### Deliverables

- GitHub repo with clean README
- wiring diagram photo
- short demo video (optional but strong)

### Tools

- ESP32 with Arduino framework OR STM32CubeIDE
- Learn to use a serial console (UART logging)

---

# Month 2: Communication Protocols (UART, I2C, SPI)

### Goal:

Learn how embedded devices talk to peripherals.

### Topics

- UART serial debugging
- I2C fundamentals (addressing, pull-ups)
- SPI fundamentals
- reading datasheets for sensors

### Projects

✅ **Project 3: OLED Status Display**

- show uptime counter
- show button state
- show sensor data later

✅ **Project 4: Sensor Reader**

- read MPU6050 (I2C)
- print raw accelerometer/gyro values to UART

### Deliverables

- demonstrate I2C scan
- explain in README how you wired it
- include logic analyzer screenshots if possible

**This month is huge** because “embedded = communication protocols + datasheets”.

---

# Month 3: Interrupts, Timers, and Real-Time Thinking

### Goal:

Stop writing delay-based code and start writing real firmware.

### Topics

- Interrupt Service Routines (ISR)
- Timer interrupts
- scheduling tasks (superloop design)
- ring buffers (UART receive)
- state machines

### Projects

✅ **Project 5: UART Command Interface**  
Make your device accept commands like:

- `led on`
- `led off`
- `status`
- `read sensor`

This is extremely portfolio-worthy.

✅ **Project 6: Event-driven button + LED system**  
No delay loops. Use interrupts/timers.

### Deliverables

- README describing architecture (superloop + ISR)
- diagram of firmware structure

---

# Month 4: RTOS (FreeRTOS) + Multitasking

### Goal:

Learn the “professional” way embedded teams structure firmware.

### Topics

- FreeRTOS tasks
- queues
- semaphores/mutex
- task priorities
- stack size issues
- watchdog timers (basic)

### Projects

✅ **Project 7: FreeRTOS Sensor System**

- Task 1: read sensor every 100ms
- Task 2: update OLED every 250ms
- Task 3: serial logging task
- use queue to pass sensor data between tasks

This project alone can qualify you for entry-level embedded roles.

### Deliverables

- clean repo
- block diagram of tasks + queues
- measured timing results (even simple logs)

---

# Month 5: Debugging Skills + Low-Level Discipline

### Goal:

Build the skills that separate “hobby embedded” from “hireable embedded”.

### Topics

- using a debugger (breakpoints/watch variables)
- stack overflow debugging
- race conditions
- using a logic analyzer for I2C/SPI timing
- reading and writing clean driver code
- error handling + retry logic

### Projects

✅ **Project 8: Build a reusable driver**  
Write your own driver library for:

- OLED SSD1306  
    or
- MPU6050

Make it modular:

- `ssd1306.c / ssd1306.h`
- `mpu6050.c / mpu6050.h`

Add:

- init function
- read function
- error return codes

### Deliverables

- driver-style code in repo
- README showing API usage
- mention how you validated it (logic analyzer / test outputs)

---

# Month 6: Capstone Portfolio Project

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
-   Produce documented portfolio projects

----------

## Future Improvements / Planned Projects

As additional projects are completed, they will be added here along with documentation and demo results.
