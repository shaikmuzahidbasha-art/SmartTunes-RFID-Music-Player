# SmartTunes RFID Music Player

## Overview

SmartTunes is an RFID-based music player that allows users to play audio tracks by simply scanning RFID cards. Each RFID card is mapped to a specific MP3 file stored on a microSD card connected to a DFPlayer Mini module.

The project combines RFID technology, embedded systems, and audio playback to create an interactive and user-friendly music experience.

---

## Features

* RFID card-based song selection
* ESP32-based control system
* DFPlayer Mini audio playback
* Multiple RFID card support
* Plug-and-play operation
* Real-time card identification
* Low-cost embedded solution

---

## Hardware Components

* ESP32 Development Board
* MFRC522 RFID Reader
* DFPlayer Mini MP3 Module
* MicroSD Card
* Speaker
* Jumper Wires
* Breadboard

---

## Working Principle

1. User scans an RFID card.
2. ESP32 reads the card UID.
3. UID is compared with registered card IDs.
4. Matching card triggers the corresponding MP3 file.
5. DFPlayer Mini plays the selected track through the speaker.

---

## Circuit Connections

### MFRC522 RFID Reader

| MFRC522 | ESP32   |
| ------- | ------- |
| SDA     | GPIO 5  |
| SCK     | GPIO 18 |
| MOSI    | GPIO 23 |
| MISO    | GPIO 19 |
| RST     | GPIO 4  |
| 3.3V    | 3.3V    |
| GND     | GND     |

### DFPlayer Mini

| DFPlayer | ESP32   |
| -------- | ------- |
| TX       | GPIO 16 |
| RX       | GPIO 17 |
| VCC      | 5V      |
| GND      | GND     |

---

## RFID Card Mapping

| RFID Card UID | Audio File |
| ------------- | ---------- |
| 43 E2 B9 E4   | 0001.mp3   |
| 7E C7 7D C4   | 0002.mp3   |
| 0E 19 A6 C4   | 0003.mp3   |
| 24 22 93 A7   | 0004.mp3   |

---

## Software Requirements

* Arduino IDE 2.x
* ESP32 Board Package
* MFRC522 Library
* DFRobotDFPlayerMini Library

---

## Demonstration

A working demonstration of SmartTunes is available on LinkedIn.

Demo Video:
https://www.linkedin.com/posts/muzahidbashashaik_rfid-cygnus2025-eee-activity-7320064960867299328-93ob?utm_source=social_share_send&utm_medium=member_desktop_web&rcm=ACoAAE17bScBBkX-4hfswYaQ5dPr5wY7B_6gTW4

The demonstration shows:

* RFID card scanning
* UID detection
* Card-to-song mapping
* DFPlayer Mini audio playback
* Real-time system response

---

## Applications

* Smart Music Systems
* RFID-Based Media Players
* Educational Demonstrations
* Interactive Learning Toys
* Embedded Systems Projects

---

## Future Enhancements

* OLED/LCD Display Integration
* Bluetooth Connectivity
* Mobile App Control
* Playlist Management
* Voice Feedback System

---

## Acknowledgements

This project was inspired by RFID-based jukebox concepts shared by the maker community.

Reference:
https://techtalkies.in/2025/04/12/esp32-rfid-jukebox/

The SmartTunes implementation, RFID mapping, hardware integration, project demonstration, and documentation were developed as part of an academic project.

---

## Developer

Shaik Muzahid Basha

B.Tech – Electronics and Communication Engineering

B.S. Abdur Rahman Crescent Institute of Science and Technology

---

## License

This project is intended for educational and research purposes.
