#include "session.h"
#include "protocols/protocol_versions.h"
#include "protocols/packet.h"
#include "protocols/handshake.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Session structure (should match handshake.c)
typedef struct {
    int fd;
    char uuid[37];
    char username[USERNAME_MAX];
    bool online;
    int protocol_version;
    char server_addr[256];
    uint16_t server_port;
    int next_state;
    int state;
} Session;

Session* session_create(int fd, const char* uuid, const char* username) {
    Session* s = malloc(sizeof(Session));
    s->fd = fd;
    strncpy(s->uuid, uuid, 37);
    strncpy(s->username, username, USERNAME_MAX);
    s->online = true;
    s->protocol_version = 0;
    s->next_state = 0;
    s->state = 0;
    return s;
}

void session_destroy(Session* session) {
    if (session) free(session);
}

// Entry point for new client session
void handle_client_session(Session* session, const uint8_t *initial_packet, int packet_len) {
    memset(&session->server_addr, 0, sizeof(session->server_addr));
    memset(&session->server_port, 0, sizeof(session->server_port));
    // 1. Parse handshake
    if (handle_handshake(initial_packet, packet_len, session) != 0) {
        printf("[Session] Handshake failed.\n");
        return;
    }
    // 2. Handle next state (status/login)
    if (session->state == 1) {
        // Status request: respond with MOTD, player count, etc. (implement per version)
        printf("[Session] Status request for protocol %d\n", session->protocol_version);
        // ... (real status packet handling goes here)
    } else if (session->state == 2) {
        // Login request: begin login sequence (implement per version)
        printf("[Session] Login request for protocol %d\n", session->protocol_version);
        // ... (real login packet handling goes here)
    } else {
        printf("[Session] Unknown state %d\n", session->state);
    }
}
