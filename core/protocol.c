#include "protocol.h"
#include <stdlib.h>
#include <string.h>

Packet* packet_parse(const uint8_t* buf, uint32_t len) {
    if (len == 0 || len > MAX_PACKET_SIZE) return NULL;
    Packet* pkt = malloc(sizeof(Packet));
    pkt->data = malloc(len);
    memcpy(pkt->data, buf, len);
    pkt->length = len;
    return pkt;
}

void packet_destroy(Packet* packet) {
    if (packet) {
        free(packet->data);
        free(packet);
    }
}
