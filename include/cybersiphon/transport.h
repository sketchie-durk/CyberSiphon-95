#ifndef CYBERSIPHON_TRANSPORT_H
#define CYBERSIPHON_TRANSPORT_H

#include "cybersiphon/hal.h"
#include <stdint.h>
#include <stddef.h>

typedef enum {
    TCL_IDLE,
    TCL_WAITING_FOR_BLOCK,
    TCL_BLOCK_RECEIVED,
    TCL_ERROR
} tcl_state_t;

typedef struct {
    tcl_state_t state;
    uint8_t current_block;
    size_t total_received;
    uint8_t buffer[1024];
} tcl_context_t;

// ISO 14443-4 Transport Layer (T=CL)
hal_status_t tcl_send_block(tcl_context_t *ctx, const uint8_t *data, size_t len);
hal_status_t tcl_receive_block(tcl_context_t *ctx, uint8_t *out_data, size_t *out_len);

#endif
