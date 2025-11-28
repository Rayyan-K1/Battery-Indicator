# Battery-Indicator 🔋

**Battery-Indicator** is a small Arduino C++ component that:

1. Reads a battery’s voltage via an analog pin  
2. Converts it into an estimated **0–100% charge level**  
3. Displays that level using an **RGB LED** (Red / Amber / Green / Blue)

It’s designed to be dropped into existing Arduino projects where you want a **quick visual indication of battery level**, not just raw ADC readings.

---

## High-Level Overview

This library wraps the typical “battery + voltage divider + analogRead” pattern into a reusable class:

- You give it:
  - An analog pin connected to a voltage divider (`BATVOLT_PIN`)
  - An RGB LED connected to `LED_RED`, `LED_GREEN`, `LED_BLUE`
- It:
  - Measures the battery voltage using the ADC
  - Estimates how “full” the battery is based on configurable min/max voltages
  - Lights the RGB LED:
    - 🔴 Red – very low  
    - 🟠 Amber – medium  
    - 🟢 Green – good  
    - 🔵 Blue – high / full  

The core method:

```cpp
float batteryIndicator::getBatteryVoltage();
