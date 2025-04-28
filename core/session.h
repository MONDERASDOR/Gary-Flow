#ifndef SESSION_H
#define SESSION_H
#include <stdint.h>
#include <stdbool.h>
#define USERNAME_MAX 32

typedef struct {
    int fd;
    char uuid[37];
    char username[USERNAME_MAX];
    bool online;
} Session;

Session* session_create(int fd, const char* uuid, const char* username);
void session_destroy(Session* session);
#endif // SESSION_H
