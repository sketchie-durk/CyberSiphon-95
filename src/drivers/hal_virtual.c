#include "cybersiphon/hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Internal buffers for virtual HAL
static uint8_t v_rx_buf[256];
static size_t v_rx_len = 0;

static hal_status_t v_transmit(const uint8_t *data, size_t len) {
    printf("[HAL-VIRT] TX (%zu bytes): ", len);
    for(size_t i=0; i<len; i++) printf("%02X ", data[i]);
    printf("\\n");
    return HAL_OK;
}

static hal_status_t v_receive(uint8_t *buffer, size_t max_len, size_t *received_len) {
    if (v_rx_len == 0) return HAL_ERR_TIMEOUT;
    size_t copy_len = (v_rx_len < max_len) ? v_rx_len : max_len;
    memcpy(buffer, v_rx_buf, copy_len);
    *received_len = copy_len;
    v_rx_len = 0;
    return HAL_OK;
}

static bool v_reset(void) {
    v_rx_len = 0;
    return true;
}

static hal_device_t v_dev = {
    .transmit = v_transmit,
    .receive = v_receive,
    .reset = v_reset
};

hal_device_t *current_hal = NULL;

void hal_init_virtual(void) {
    current_hal = &v_dev;
}

// Simulation helper to push data into virtual RX buffer
void hal_virtual_push_rx(const uint8_t *data, size_t len) {
    if (len <= 256) {
        memcpy(v_rx_buf, data, len);
        v_rx_len = len;
    }
}
