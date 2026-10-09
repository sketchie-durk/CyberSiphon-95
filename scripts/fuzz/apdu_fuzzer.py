import random
import time

class APDUFuzzer:
    def __init__(self, target_ip="127.0.0.1"):
        self.target = target_ip
        self.cla_range = [0x00, 0x80, 0xFF]
        self.ins_range = [0x00, 0xCA, 0x80]

    def generate_malformed_apdu(self):
        """Generates a high-entropy malformed APDU for boundary testing."""
        cla = random.choice(self.cla_range)
        ins = random.choice(self.ins_range)
        p1 = random.randint(0x00, 0xFF)
        p2 = random.randint(0x00, 0xFF)
        lc = random.randint(0, 255)
        payload = bytes([random.randint(0, 255) for _ in range(lc)])
        le = random.randint(0, 255)
        
        return bytes([cla, ins, p1, p2, lc]) + payload + bytes([le])

    def run_fuzz_cycle(self, iterations=100):
        print(f"[!] Starting Fuzzing Cycle on {self.target}...")
        for i in range(iterations):
            packet = self.generate_malformed_apdu()
            print(f"[*] Cycle {i:03}: Injecting {packet.hex().upper()}...")
            # Mock injection: in real use, this would call the C binary via subprocess
            time.sleep(0.01)
        print("[+] Fuzzing cycle complete.")

if __name__ == "__main__":
    fuzzer = APDUFuzzer()
    fuzzer.run_fuzz_cycle()
