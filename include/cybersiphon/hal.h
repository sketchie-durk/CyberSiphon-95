#ifndef CYBERSIPHON_HAL_H
#define CYBERSIPHON_HAL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum {
    HAL_OK = 0,
    HAL_ERR_TIMEOUT,
    HAL_ERR_IO,
    HAL_ERR_COLLISION,
    HAL_ERR_INVALID_FRAME
} hal_status_t;

// Hardware Abstraction Layer Interface
typedef struct {
    hal_status_t (*transmit)(const uint8_t *data, size_t len);
    hal_status_t (*receive)(uint8_t *buffer, size_t max_len, size_t *received_len);
    bool (*reset)(void);
} hal_device_t;

// Global HAL handle
extern hal_device_t *current_hal;

// Driver registration
void hal_init_virtual(void);
void hal_init_pn532(const char *device_path);

#endif
