#ifndef BACKEND_H
#define BACKEND_H
#include <stdint.h>

typedef struct {
    char address[64];
    int port;
    int online_players;
} Backend;

Backend* backend_create(const char* address, int port);
void backend_destroy(Backend* backend);
#endif // BACKEND_H
