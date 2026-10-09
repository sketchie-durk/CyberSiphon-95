# ⚡ CYBERSIPHON-95 ⚡
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build: Passing](https://img.shields.io/badge/Build-Passing-brightgreen.svg)]()
[![Platform: Multi-Arch](https://img.shields.io/badge/Platform-Multi--Arch-blue.svg)]()
[![Security: Hardened](https://img.shields.io/badge/Security-Hardened-red.svg)]()
[![Standard: ISO/IEC 14443](https://img.shields.io/badge/Standard-ISO/IEC%2014443-orange.svg)]()

**STATUS: OPERATIONAL | VERSION: 0.1.0-ALPHA | CODENAME: NEON_Siphon**

`CyberSiphon-95` is a high-density research framework designed for the deep-packet inspection, signal analysis, and architectural reverse-engineering of Near Field Communication (NFC) and Radio Frequency Identification (RFID) systems. This project implements a low-level abstraction layer for interacting with Proximity Integrated Circuit Cards (PICCs) and Proximity Coupling Devices (PCDs) via the ISO/IEC 14443 standard.

## 🛠 Technical Specification
The framework focuses on the physical and data-link layers of the NFC stack, providing tools for:
- **APDU Protocol Fuzzing:** Generation and injection of malformed Application Protocol Data Units (APDUs) to identify edge-case vulnerabilities in smart card OS implementations.
- **L3/L4 Signal Analysis:** Quantitative analysis of Load Modulation and ASK (Amplitude Shift Keying) patterns.
- **Anti-collision Sequence Mapping:** Detailed tracing of the UID (Unique Identifier) selection process in multi-card environments.
- **PICC Emulation:** Software-defined implementation of ISO/IEC 7816-4 compliant response sets.

## 🏗 Architecture
The system follows a modular pipeline:
`Hardware Driver` ➔ `Frame Decoder` ➔ `Protocol Parser` ➔ `Analysis Engine` ➔ `Export/Log`

- **Core:** C11 implementation for deterministic timing and memory management.
- **Drivers:** Pluggable backends for PN532, ACR122U, and Proxmark3.
- **Frontend:** Python-based analysis suite for signal visualization.

## 📜 Open Source Manifesto
CyberSiphon-95 is released under the MIT License. We advocate for the transparency of wireless protocols to ensure the security of global payment and identity infrastructure. This tool is intended for academic research, penetration testing, and security auditing.

## 🚀 Quick Start
```bash
git clone https://github.com/sketchie-durk/CyberSiphon-95.git
cd CyberSiphon-95
make build
./bin/cybersiphon --interface /dev/ttyUSB0 --mode sniff
```

---
*Built for the grid. 1995 Aesthetics. Pure Technicality.*
