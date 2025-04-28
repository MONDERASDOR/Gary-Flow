#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stdint.h>

#define MAX_PACKET_SIZE 65536

typedef struct {
    uint8_t* data;
    uint32_t length;
} Packet;

Packet* packet_parse(const uint8_t* buf, uint32_t len);
void packet_destroy(Packet* packet);
#endif // PROTOCOL_H
