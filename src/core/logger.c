#include "cybersiphon/logger.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1024
static signal_log_entry_t log_buffer[MAX_LOGS];
static size_t log_count = 0;

void log_signal_event(const char *event, const uint8_t *data, size_t len) {
    if (log_count >= MAX_LOGS) return;

    signal_log_entry_t *entry = &log_buffer[log_count++];
    clock_gettime(CLOCK_MONOTONIC, &entry->timestamp);
    entry->event = event;
    entry->len = len > 256 ? 256 : len;
    if (data) memcpy(entry->data, data, entry->len);
}

void dump_signal_logs(void) {
    printf("\\n--- CYBERSIPHON-95 SIGNAL DUMP ---\\n");
    for (size_t i = 0; i < log_count; i++) {
        printf("[%ld.%09ld] %s: ", log_buffer[i].timestamp.tv_sec, log_buffer[i].timestamp.tv_nsec, log_buffer[i].event);
        for (size_t j = 0; j < log_buffer[i].len; j++) {
            printf("%02X ", log_buffer[i].data[j]);
        }
        printf("\\n");
    }
}
