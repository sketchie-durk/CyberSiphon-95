# 📐 SYSTEM ARCHITECTURE: CYBERSIPHON-95

## 1. Physical Layer (L1)
The system operates at 13.56 MHz. It utilizes a modified load modulation technique to intercept data transmitted from the PICC to the PCD.
- **Modulation:** ASK 100% (PCD to PICC), Load Modulation (PICC to PCD).
- **Bit Coding:** Miller encoding (Type A), Manchester encoding (Type B).

## 2. Data Link Layer (L2)
Implements the ISO/IEC 14443-3 anti-collision loop:
1. **REQA/WUPA:** Wake-up commands.
2. **CASCADE:** Bit-level collision detection using the `SEL` command.
3. **SAK:** Selection Acknowledge to determine protocol capabilities.

## 3. Application Layer (L3 - APDU)
The core logic handles ISO/IEC 7816-4 APDUs:
- **CLA:** Class byte (Indicator of the instruction class).
- **INS:** Instruction byte (The specific command to be executed).
- **P1/P2:** Parameter bytes.
- **Lc:** Length of data sent.
- **Le:** Expected length of response.

## 4. Component Diagram
`[PCD Hardware] <-> [UART/USB Driver] <-> [Frame Buffer] <-> [State Machine] <-> [User Interface]`
