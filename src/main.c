#include "cybersiphon/apdu.h"
#include "cybersiphon/hal.h"
#include "cybersiphon/transport.h"
#include "cybersiphon/logger.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    printf("⚡ CYBERSIPHON-95 | BOOTING CORE...\\n");
    
    // Initialize Virtual HAL for testing
    hal_init_virtual();
    
    // Define a target APDU: Select File (ISO 7816)
    apdu_t select_file = {
        .cla = 0x00,
        .ins = 0xA4,
        .p1 = 0x00,
        .p2 = 0x04,
        .lc = 0x02,
        .data = (uint8_t[]){0x01, 0x02},
        .le = 0x00
    };

    printf("[*] Executing Select File...\\n");
    log_signal_event("APDU_TX", (uint8_t*)&select_file, sizeof(select_file));
    
    if (apdu_send(&select_file) == APDU_SUCCESS) {
        printf("[+] Packet transmitted successfully.\\n");
    } else {
        printf("[!] Transmission failure.\\n");
    }

    // Simulate a response arriving in the HAL
    uint8_t mock_resp[] = {0x4F, 0x01, 0x02, 0x90, 0x00};
    extern void hal_virtual_push_rx(const uint8_t *data, size_t len);
    hal_virtual_push_rx(mock_resp, sizeof(mock_resp));

    apdu_t response = {0};
    if (apdu_receive(&response) == APDU_SUCCESS) {
        printf("[+] Response received: 9000 (Success)\\n");
        log_signal_event("APDU_RX", mock_resp, sizeof(mock_resp));
    } else {
        printf("[!] Response error or timeout.\\n");
    }

    dump_signal_logs();
    printf("\\n⚡ CYBERSIPHON-95 | SHUTDOWN\\n");
    return 0;
}
