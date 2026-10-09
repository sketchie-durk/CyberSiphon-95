# 🔋 ANALYSIS ENGINE: SIGNAL-SPACE MAPPING

## 1. Signal-to-Noise Ratio (SNR) Calculation
The analysis engine utilizes a sliding-window Root Mean Square (RMS) to calculate the noise floor of the 13.56 MHz carrier.

$$ SNR_{dB} = 20 \log_{10} \left( \frac{A_{signal}}{A_{noise}} \right) $$

## 2. Load Modulation Profiling
By analyzing the magnitude of the current drop during the PICC's load modulation, `CyberSiphon-95` can identify the type of antenna used by the target card.

- **Deep Modulation:** High-gain antenna, strong signal.
- **Shallow Modulation:** Small-form factor card, high susceptibility to interference.

## 3. Frame Timing Analysis
The system measures the Inter-Frame Space (IFS) with microsecond precision to detect:
- **Processing Lag:** Latency in the smart card OS (indicates complex internal operations).
- **Clock Drift:** Variance in the PICC's internal oscillator.
