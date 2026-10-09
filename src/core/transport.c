#include "cybersiphon/transport.h"
#include <string.h>

hal_status_t tcl_send_block(tcl_context_t *ctx, const uint8_t *data, size_t len) {
    if (!current_hal) return HAL_ERR_IO;
    
    // T=CL encapsulation: Simple block wrap
    uint8_t frame[1048]; 
    frame[0] = 0x01; // Start of block
    memcpy(&frame[1], data, len);
    frame[len + 1] = 0x02; // End of block
    
    return current_hal->transmit(frame, len + 2);
}

hal_status_t tcl_receive_block(tcl_context_t *ctx, uint8_t *out_data, size_t *out_len) {
    if (!current_hal) return HAL_ERR_IO;
    
    uint8_t rx_buf[1048];
    size_t rx_len = 0;
    
    if (current_hal->receive(rx_buf, 1048, &rx_len) != HAL_OK) {
        return HAL_ERR_TIMEOUT;
    }
    
    if (rx_len < 2 || rx_buf[0] != 0x01 || rx_buf[rx_len-1] != 0x02) {
        return HAL_ERR_INVALID_FRAME;
    }
    
    size_t data_len = rx_len - 2;
    memcpy(out_data, &rx_buf[1], data_len);
    *out_len = data_len;
    
    return HAL_OK;
}
