# IoT Temperature & Humidity Logger

This repository contains firmware and documentation for an IoT Temperature and Humidity Logger. The project uses an ESP32 microcontroller to periodically read temperature and humidity data from a DHT22 sensor and then log the data locally on SD card.

## Features
- Periodic temperature and humidity readings using a DHT22 sensor
- Data logging to SD card
- Configurable sampling interval
- Simple, modular codebase for easy expansion

## Hardware Requirements
- ESP32 development board
- DHT11 or DHT22 sensor
- MicroSD card module for local logging
- Optional: Battery power supply for standalone operation