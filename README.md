# PulsePad 🔌🌐
### A Standalone Web-Based Electronics & IoT Learning Platform

**PulsePad** is a standalone, interactive learning platform designed to help beginners explore **electronics and Internet of Things (IoT)** concepts through hands-on hardware experimentation.

The system is built around a **NodeMCU v3 (ESP8266)** configured as a **Soft Access Point (AP)**. It hosts a local web server that provides a browser-based interface for interacting with connected electronic components.

Users can connect to the NodeMCU directly using a **smartphone, tablet, or laptop**, without requiring an external Wi-Fi network during operation.

---

## 🚀 Project Overview

PulsePad aims to make electronics and IoT experimentation more accessible to beginners by combining:

- 🔌 Physical electronic components
- 📡 ESP8266 wireless communication
- 🌐 A browser-based interface
- 📚 Interactive learning
- 💻 Simple hardware control

Instead of requiring a computer and programming environment for every interaction, users can connect to the **PulsePad Wi-Fi network** and control or monitor the connected hardware through a web browser.

---

## ✨ Features

PulsePad currently supports several interactive hardware demonstrations:

- 📡 **Standalone Wi-Fi Access Point**
- 🌐 **Built-in Web Server**
- 💡 **LED ON/OFF Control**
- 🌡️ **DHT11 Temperature Monitoring**
- 🚶 **Motion Detection**
- 🔦 **Laser Module Control**
- 💡 **PWM-Based LED Fading**
- 🔊 **Piezo/Buzzer Control**
- ⚙️ **System Status Monitoring**
- 📱 Browser-based control from Wi-Fi-enabled devices

---

## 🛠️ Tech Stack

### Hardware

- **NodeMCU v3 (ESP8266)**
- **DHT11 Temperature Sensor**
- LED
- Motion Sensor
- Laser Module
- Piezo/Buzzer
- Additional electronic modules

### Software & Languages

- **C++ / Arduino**
- **HTML**
- **CSS**
- **JavaScript**
- **Arduino IDE**

### ESP8266 Libraries

- `ESP8266WiFi`
- `ESP8266WebServer`
- `DHT11`

---

## ⚙️ How It Works

PulsePad operates as a self-contained local IoT system.

### 1. ESP8266 Creates a Wi-Fi Network

The NodeMCU is configured as a **Soft Access Point**.

```cpp
WiFi.softAP("PulsePad", "12345678");
```

This creates the Wi-Fi network:

```text
SSID: PulsePad
Password: 12345678
```

### 2. User Connects

A smartphone, tablet, or laptop connects directly to the PulsePad Wi-Fi network.

```text
📱 Smartphone
      │
      │ Wi-Fi
      ▼
┌───────────────────┐
│ NodeMCU ESP8266   │
│    PulsePad AP    │
└───────────────────┘
```

### 3. Local Web Server

The ESP8266 runs a web server on **port 80**.

The server handles different requests for the webpage, styling, JavaScript, and hardware commands.

```text
/
        → Main Web Interface

/style.css
        → CSS

/script.js
        → JavaScript

/command
        → Hardware Commands
```

### 4. Hardware Interaction

The web interface sends commands to the ESP8266.

For example:

```text
LED_ON
LED_OFF
TEMP_READ
