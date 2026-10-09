#include "cybersiphon/apdu.h"
#include <stdio.h>
#include <stdlib.h>

apdu_status_t apdu_send(const apdu_t *cmd) {
    printf("[TX] CLA: %02X INS: %02X P1: %02X P2: %02X LC: %02X\\n", 
            cmd->cla, cmd->ins, cmd->p1, cmd->p2, cmd->lc);
    return APDU_SUCCESS;
}

apdu_status_t apdu_receive(apdu_t *resp) {
    printf("[RX] Waiting for response...\\n");
    return APDU_SUCCESS;
}
