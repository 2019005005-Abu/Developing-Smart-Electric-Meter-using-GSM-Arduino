# Developing-Smart-Electric-Meter-using-GSM-Arduino
# Smart Energy Monitoring System

A Smart Energy Monitoring System using **Arduino UNO**, **PZEM-004T Energy Meter**, **SIM800 GSM Module**, and **16×2 I2C LCD Display** for real-time monitoring of electrical parameters and remote reporting.

---

## 📖 Overview

This project measures and displays electrical parameters such as:

- Voltage (V)
- Current (A)
- Power (W)
- Energy Consumption (kWh)
- Frequency (Hz)
- Power Factor (PF)

The system uses the PZEM-004T module to collect energy data, displays it on an LCD screen, and can send reports remotely using the SIM800 GSM module.

---

## 🛠 Hardware Components

| Component | Description |
|------------|------------|
| Arduino UNO | Main microcontroller |
| PZEM-004T V3.0 | Energy monitoring module |
| Current Transformer (CT) | Current sensing up to 100A |
| SIM800 GSM Module | SMS/GPRS communication |
| LCD 16×2 I2C | Local display |
| Breadboard | Circuit prototyping |
| Jumper Wires | Connections |
| AC Load | Device under monitoring |

---

## 📋 PZEM-004T Specifications

| Parameter | Value |
|------------|--------|
| Operating Voltage | 80–260 VAC |
| Rated Current | 100 A |
| Rated Power | 22,000 W |
| Frequency Range | 45–65 Hz |
| Accuracy | Class 1.0 |
| Communication | TTL Serial |
| Protocol | Modbus RTU (V3.0) |
| Baud Rate | 9600 bps |
| Energy Range | 0–9999.99 kWh |
| Power Factor Range | 0.00–1.00 |

---

## ⚡ Current Transformer (CT)

The Current Transformer is used to safely measure AC current.

### Working Principle

1. The load conductor passes through the CT core.
2. The conductor acts as the primary winding.
3. A proportional current is induced in the CT secondary winding.
4. The PZEM-004T converts the measured signal into current values.

### Advantages

- Electrical isolation
- Safe current measurement
- High accuracy
- Suitable for high-current applications

---

## 🔌 Circuit Connections

### Arduino UNO ↔ PZEM-004T

| Arduino | PZEM-004T |
|----------|-----------|
| 5V | VCC |
| GND | GND |
| D10 | TX |
| D9 | RX |

---

### Arduino UNO ↔ SIM800

| Arduino | SIM800 |
|----------|---------|
| D7 | TX |
| D8 | RX |
| GND | GND |
| External Supply | VCC |

> **Note:** SIM800 requires an external power source capable of delivering peak currents up to 2A.

---

### Arduino UNO ↔ LCD I2C

| Arduino | LCD |
|----------|------|
| A4 | SDA |
| A5 | SCL |
| 5V | VCC |
| GND | GND |

---

## 🔄 System Architecture

```text
AC Supply
    │
    ▼
PZEM-004T + CT
    │
    ▼
Arduino UNO
    │
 ┌──┴──┐
 ▼     ▼
LCD   SIM800
Display GSM
```

---

## 📟 LCD Output Example

```text
Voltage : 230.5V
Current : 2.45A

Power   : 563W
Energy  : 1.28kWh
```

---

## 📡 GSM Reporting Example

```text
Smart Energy Report

Voltage : 230V
Current : 2.5A
Power   : 575W
Energy  : 3.8kWh
PF      : 0.96
```

---

## 💻 Software Requirements

### Arduino IDE Libraries

Install the following libraries:

```cpp
PZEM004Tv30.h
SoftwareSerial.h
LiquidCrystal_I2C.h
```

---

## 🚀 Working Process

1. PZEM-004T measures voltage, current, power, energy, frequency, and power factor.
2. Arduino reads the values through serial communication.
3. Data is displayed on the LCD screen.
4. SIM800 transmits energy information remotely via SMS/GPRS.
5. Users receive energy usage reports in real time.

---

## ⚠ Safety Notes

- Work carefully with AC mains voltage.
- Disconnect power before wiring.
- Ensure proper insulation.
- Use the CT coil correctly around the load conductor.
- Verify all connections before powering the system.

---

## 📈 Applications

- Home Energy Monitoring
- Industrial Energy Management
- Smart Metering Systems
- Energy Auditing
- Load Monitoring
- IoT-Based Power Monitoring

---

## 🔮 Future Improvements

- Cloud dashboard integration
- Mobile application support
- Data logging with SD card
- Wi-Fi connectivity using ESP8266/ESP32
- Energy cost calculation
- Automatic overload notifications

---

## 📄 License

This project is intended for educational and research purposes. Modify and distribute according to your project requirements.

---

## 👨‍💻 Author

Smart Energy Monitoring System Project using Arduino UNO, PZEM-004T, SIM800 GSM Module, and LCD Display.
