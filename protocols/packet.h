#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>
#include "protocol_versions.h"

// Packet types
#define PACKET_HANDSHAKE 0x00
#define PACKET_STATUS    0x01
#define PACKET_LOGIN     0x02
#define PACKET_PLAY      0x03

// Maximum packet size
#define MAX_PACKET_SIZE  32767

// Packet structure for all versions
struct mc_packet {
    int version; // Protocol version
    uint8_t id;  // Packet ID
    uint8_t *data;
    int length;
};

// Parse a packet from raw bytes (version-aware)
int parse_packet(const uint8_t *buf, int buflen, int protocol_version, struct mc_packet *out);

// Serialize a packet to raw bytes (version-aware)
int serialize_packet(const struct mc_packet *packet, uint8_t *buf, int maxlen);

#endif // PACKET_H
