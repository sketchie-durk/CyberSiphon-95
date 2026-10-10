#ifndef CYBERSIPHON_LOGGER_H
#define CYBERSIPHON_LOGGER_H

#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    struct timespec timestamp;
    const char *event;
    uint8_t data[256];
    size_t len;
} signal_log_entry_t;

void log_signal_event(const char *event, const uint8_t *data, size_t len);
void dump_signal_logs(void);

#endif
