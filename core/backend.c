#include "backend.h"
#include <stdlib.h>
#include <string.h>

Backend* backend_create(const char* address, int port) {
    Backend* b = malloc(sizeof(Backend));
    strncpy(b->address, address, 64);
    b->port = port;
    b->online_players = 0;
    return b;
}

void backend_destroy(Backend* backend) {
    if (backend) free(backend);
}
