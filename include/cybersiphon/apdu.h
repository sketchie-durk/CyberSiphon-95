#ifndef CYBERSIPHON_APDU_H
#define CYBERSIPHON_APDU_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t cla;    // Class byte
    uint8_t ins;    // Instruction byte
    uint8_t p1;     // Parameter 1
    uint8_t p2;     // Parameter 2
    uint8_t lc;     // Length of data
    uint8_t *data;  // Payload
    uint8_t le;     // Expected response length
} apdu_t;

typedef enum {
    APDU_SUCCESS = 0x90,
    APDU_ERR_NOT_FOUND = 0x6A,
    APDU_ERR_WRONG_LENGTH = 0x67,
    APDU_ERR_UNKNOWN = 0x6F
} apdu_status_t;

apdu_status_t apdu_send(const apdu_t *cmd);
apdu_status_t apdu_receive(apdu_t *resp);

#endif
