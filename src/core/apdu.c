#include "cybersiphon/apdu.h"
#include "cybersiphon/hal.h"
#include <stdio.h>
#include <stdlib.h>

apdu_status_t apdu_send(const apdu_t *cmd) {
    uint8_t buffer[512];
    size_t len = 0;
    
    buffer[len++] = cmd->cla;
    buffer[len++] = cmd->ins;
    buffer[len++] = cmd->p1;
    buffer[len++] = cmd->p2;
    buffer[len++] = cmd->lc;
    
    if (cmd->data && cmd->lc > 0) {
        for(int i=0; i < cmd->lc; i++) buffer[len++] = cmd->data[i];
    }
    
    if (cmd->le > 0) {
        buffer[len++] = cmd->le;
    }

    if (!current_hal) return APDU_ERR_UNKNOWN;
    
    if (current_hal->transmit(buffer, len) != HAL_OK) {
        return APDU_ERR_UNKNOWN;
    }
    
    return APDU_SUCCESS;
}

apdu_status_t apdu_receive(apdu_t *resp) {
    if (!current_hal) return APDU_ERR_UNKNOWN;
    
    uint8_t rx_buf[512];
    size_t rx_len = 0;
    
    if (current_hal->receive(rx_buf, 512, &rx_len) != HAL_OK) {
        return APDU_ERR_UNKNOWN;
    }
    
    if (rx_len < 2) return APDU_ERR_UNKNOWN;
    
    // In a real scenario, we would parse the response according to ISO 7816
    // Here we map the status from the last 2 bytes (SW1 SW2)
    uint8_t sw1 = rx_buf[rx_len-2];
    uint8_t sw2 = rx_buf[rx_len-1];
    
    if (sw1 == 0x90 && sw2 == 0x00) return APDU_SUCCESS;
    
    return APDU_ERR_UNKNOWN;
}
