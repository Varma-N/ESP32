# IoT Environmental Monitoring and Data Logging System

## Overview
The IoT Environmental Monitoring and Data Logging System is an IoT-based project designed to monitor environmental parameters, such as temperature and humidity, in real-time. Using an ESP32 microcontroller, DHT22 sensor, and WiFi connectivity, this system collects data and uploads it to the cloud via ThingSpeak for remote analysis and logging.

## Components Used
ESP32: Microcontroller with built-in WiFi used to control the sensors and send data to the cloud.<br>
DHT22 Sensor: Measures temperature and humidity.<br>
Potentiometer: Simulates additional environmental parameters (optional).<br>
ThingSpeak: Cloud platform for IoT data storage and visualization.
## Features
Real-time monitoring of temperature and humidity.<br>
WiFi-based communication for remote data logging.<br>
Cloud data visualization via ThingSpeak.<br>
Fully simulated online using Wokwi.
## Project Details
Sensor: DHT22<br>
Data: Temperature (°C) and Humidity (%)<br>
Microcontroller: ESP32 (with WiFi)<br>
Cloud Platform: ThingSpeak for data storage and analysis<br>
## Setup Instructions
Hardware Connections:<br>

Connect the DHT22 sensor's VCC to 3.3V and GND to ground.<br>
Connect the data pin of the DHT22 to any GPIO pin (e.g., GPIO4) on the ESP32.<br>
Optionally, connect the potentiometer to simulate additional environmental parameters.
## Software Setup:

Install the DHT and WiFi libraries in your Arduino IDE or simulation platform.<br>
Replace your WiFi credentials and ThingSpeak API key in the code.<br>
Upload the code to the ESP32 using the Arduino IDE or simulate it using Wokwi.<br>
## Code
The code measures temperature and humidity using the DHT22 sensor and sends the data to ThingSpeak for real-time monitoring. The potentiometer can be used to simulate environmental variations if needed.

## How to Run the Project
Clone this repository to your local machine or run the simulation online using Wokwi.<br>
Make sure to configure your WiFi credentials and ThingSpeak API keys in the code.<br>
Upload the code to the ESP32 or run the Wokwi simulation.<br>
View the collected data in real-time on your ThingSpeak channel.<br>
## Results
You can monitor the temperature and humidity data in real time via the ThingSpeak platform, with graphical visualizations showing trends over time.<br>
Sample Result in ThingSpeak Channel:<br>
![image](https://github.com/user-attachments/assets/7cc74ea2-8839-4d8a-82da-c8b3a1d90000)

