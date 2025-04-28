#include "protocol_versions.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Session struct (simplified for this example)
typedef struct {
    int protocol_version;
    char server_addr[256];
    uint16_t server_port;
    int next_state;
    int state;
} session;

#define STATE_HANDSHAKE 0
#define STATE_STATUS    1
#define STATE_LOGIN     2

#define HANDSHAKE_STATE_STATUS 1
#define HANDSHAKE_STATE_LOGIN  2

// Helper to read a VarInt from a buffer
static int read_varint(const uint8_t *buf, int *offset) {
    int numRead = 0;
    int result = 0;
    uint8_t read;
    do {
        read = buf[(*offset)++];
        int value = (read & 0b01111111);
        result |= (value << (7 * numRead));
        numRead++;
        if (numRead > 5) return -1; // VarInt too big
    } while ((read & 0b10000000) != 0);
    return result;
}

// Helper to read a UTF-8 string from a buffer
static int read_string(const uint8_t *buf, int *offset, char *out, int maxlen) {
    int strlen = read_varint(buf, offset);
    if (strlen <= 0 || strlen >= maxlen) return -1;
    memcpy(out, buf + *offset, strlen);
    out[strlen] = '\0';
    *offset += strlen;
    return strlen;
}

// Helper to read unsigned short
static uint16_t read_ushort(const uint8_t *buf, int *offset) {
    uint16_t val = (buf[*offset] << 8) | buf[*offset + 1];
    *offset += 2;
    return val;
}

// Check if protocol version is supported
static int is_supported_protocol(int protocol_version) {
    switch (protocol_version) {
        case PROTOCOL_1_7:
        case PROTOCOL_1_8:
        case PROTOCOL_1_12:
        case PROTOCOL_1_16:
        case PROTOCOL_1_19:
        case PROTOCOL_1_20:
            return 1;
        default:
            return 0;
    }
}

// Send disconnect (stub)
static void send_disconnect(session *sess, const char *msg) {
    printf("[Proxy] Disconnect: %s\n", msg);
}

// Log handshake
static void log_handshake(session *sess) {
    printf("[Protocol] Handshake: version=%d, addr=%s, port=%u, next_state=%d\n",
        sess->protocol_version, sess->server_addr, sess->server_port, sess->next_state);
}

// Main handshake handler
int handle_handshake(const uint8_t *packet, int length, session *sess) {
    int offset = 0;
    int protocol_version = read_varint(packet, &offset);
    char server_addr[256];
    if (read_string(packet, &offset, server_addr, sizeof(server_addr)) < 0) {
        send_disconnect(sess, "Malformed handshake: bad server address");
        return -1;
    }
    uint16_t port = read_ushort(packet, &offset);
    int next_state = read_varint(packet, &offset);

    sess->protocol_version = protocol_version;
    strncpy(sess->server_addr, server_addr, sizeof(sess->server_addr)-1);
    sess->server_addr[sizeof(sess->server_addr)-1] = '\0';
    sess->server_port = port;
    sess->next_state = next_state;

    if (!is_supported_protocol(protocol_version)) {
        send_disconnect(sess, "Unsupported Minecraft version!");
        return -1;
    }

    if (next_state == HANDSHAKE_STATE_STATUS) {
        sess->state = STATE_STATUS;
    } else if (next_state == HANDSHAKE_STATE_LOGIN) {
        sess->state = STATE_LOGIN;
    } else {
        send_disconnect(sess, "Invalid handshake state!");
        return -1;
    }

    log_handshake(sess);
    return 0;
}
