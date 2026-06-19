# Vibroacoustic Sensor System

A real-time wireless vibration sensing platform for structural health monitoring, 
developed as part of my PgCert in Systems Design at Cranfield University. 
The system streams live dual-channel piezoelectric sensor data over WiFi via UDP 
to a MATLAB/Simulink model for real-time signal processing and visualisation.

---

## Files

- `Vibroacoustic_Arduino.ino` — Arduino firmware for sensor reading and WiFi UDP streaming
- `Vibro_Simulink Model.slx` — Simulink model for receiving, processing and visualising data

---

## How It Works

1. Two piezoelectric sensors are read simultaneously on analog pins A0 and A1
2. A 50-sample running average baseline is computed on-device for each channel
3. Raw readings and baseline averages are packed into a UDP packet and streamed 
   wirelessly over WiFi to a host PC
4. The MATLAB/Simulink model receives the packets, unpacks the data, and performs 
   real-time signal processing and visualisation

---

## Setup

1. Open `Vibroacoustic_Arduino.ino` and update your WiFi credentials and PC IP address
2. Flash to the Arduino MKR WiFi 1010
3. Open `Vibro_Simulink Model.slx` in MATLAB on the same network
4. Run the Simulink model — it will begin receiving data from the Arduino

---

## Hardware

- Arduino UNO With WiFi modeule
- 2× Piezoelectric sensors
- Breadboard signal conditioning circuit

---

## Key Outcomes

- Built a dual-channel wireless vibration sensing platform using low-cost hardware
- Implemented real-time UDP streaming from embedded hardware to MATLAB/Simulink
- Validated system accuracy through systematic calibration and experimental testing

---

## Author

**Krishna Praveen Kasilingam**
PgCert Systems Design — Cranfield University
📧 krishnapraveenka@gmail.com
🌐 [Portfolio](https://krishnapraveen-k.github.io/portfolio)
💼 [LinkedIn](https://linkedin.com/in/krishna-praveen-k)
