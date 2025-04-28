#include "packet.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Helper to read/write VarInt (used in handshake.c as well)
static int read_varint(const uint8_t *buf, int *offset) {
    int numRead = 0;
    int result = 0;
    uint8_t read;
    do {
        read = buf[(*offset)++];
        int value = (read & 0b01111111);
        result |= (value << (7 * numRead));
        numRead++;
        if (numRead > 5) return -1;
    } while ((read & 0b10000000) != 0);
    return result;
}

static void write_varint(uint8_t *buf, int *offset, int value) {
    do {
        uint8_t temp = value & 0b01111111;
        value >>= 7;
        if (value != 0) temp |= 0b10000000;
        buf[(*offset)++] = temp;
    } while (value != 0);
}

// Parse a packet from raw bytes (version-aware)
int parse_packet(const uint8_t *buf, int buflen, int protocol_version, struct mc_packet *out) {
    int offset = 0;
    int packet_length = read_varint(buf, &offset);
    if (packet_length < 1 || packet_length > MAX_PACKET_SIZE || packet_length > buflen - offset)
        return -1;
    int packet_id = read_varint(buf, &offset);
    out->version = protocol_version;
    out->id = packet_id;
    out->length = packet_length;
    out->data = malloc(packet_length);
    if (!out->data) return -1;
    memcpy(out->data, buf + offset, packet_length - (offset - (buf - buf)));
    return 0;
}

// Serialize a packet to raw bytes (version-aware)
int serialize_packet(const struct mc_packet *packet, uint8_t *buf, int maxlen) {
    int offset = 0;
    write_varint(buf, &offset, packet->length);
    write_varint(buf, &offset, packet->id);
    if (offset + packet->length > maxlen) return -1;
    memcpy(buf + offset, packet->data, packet->length);
    return offset + packet->length;
}

// Status, login, and play packet handling would be implemented here for each protocol version.
// For brevity, only the protocol-agnostic parse/serialize logic is shown, but each version's
// packet fields and translation logic would be handled in extended functions.
