# Group-11---Arduino-Based-Kinetic-Mat-with-Step-Counter-and-Low-Voltage-Bulb-Lighting-Demonstration
Group 11 -  Arduino-Based Kinetic Mat with Step Counter and Low-Voltage Bulb Lighting Demonstration

This project is an Arduino-based kinetic mat system designed to detect footstep pressure, count steps, display real-time voltage, and compute the electrical energy generated using numerical integration (Trapezoidal Rule). It includes a visual LED bar display and can light up a low-voltage bulb, demonstrating the principle of energy harvesting from human motion.

## Project Objectives

- Detect footsteps using analog signals from a pressure or piezoelectric sensor.
- Count and display the number of steps on an I2C 16x2 LCD.
- Convert analog readings to voltage and display the value.
- Compute the energy generated using the Trapezoidal Rule.
- Provide visual feedback using a 5-LED bar based on pressure level.
- Light up a small low-voltage bulb to demonstrate harvested energy usage.

## Functional Overview

1. Footstep Detection
   A sensor beneath a mat detects pressure caused by a footstep. When the analog value exceeds a defined threshold, and debouncing conditions are met, a valid step is recorded.

2. Voltage Reading
   Analog sensor data is converted to a voltage value (0–5 V) and displayed on the LCD.

3. Numerical Integration
   Every 500 milliseconds, the system calculates the energy output using the Trapezoidal Rule:
where Δt is the time interval in seconds. The computed energy (in joules) is displayed on the Serial Monitor.

4. LED Bar Visualization
A 5-segment LED bar lights up proportionally to the intensity of the sensor reading, giving real-time visual feedback.

5. Bulb Demonstration
A small low-voltage bulb is powered to simulate a real-world energy harvesting application.

## Hardware Components

- Arduino Uno 
- Piezoelectric sensor 
- 16x2 I2C LCD module
- 5 LEDs with current-limiting resistors
- Jumper wires and breadboard
- Low-voltage bulb
- External power source (battery)
- 

## Features
  
Step Counter - Tracks and displays number of valid steps         
Voltage Display - Shows real-time sensor voltage (0–5 V)            
Energy Computation - Uses Trapezoidal Rule to compute energy in joules 
LED Bar Display - Indicates pressure intensity visually             
Bulb Lighting Output Demonstrates conversion of mechanical to electrical energy 

## Development Environment

- Arduino IDE
- Standard Arduino libraries
- Serial Monitor for data observation and debugging

## License

This project is released for educational and prototyping purposes and may be modified or extended freely with attribution.
