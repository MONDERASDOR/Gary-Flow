#ifndef EVENT_H
#define EVENT_H
#include <stdint.h>

typedef enum {
    EVENT_PLAYER_JOIN,
    EVENT_PLAYER_QUIT,
    EVENT_PLAYER_CHAT,
    EVENT_PLAYER_COMMAND,
    EVENT_PLAYER_KICK,
    EVENT_PLAYER_BAN,
    EVENT_PLAYER_AUTH,
    EVENT_SERVER_SWITCH,
    EVENT_SERVER_PING,
    EVENT_NETWORK,
    EVENT_PLUGIN_LIFECYCLE,
    EVENT_PLUGIN_MESSAGE,
    EVENT_PLAYER_PERMISSION,
    EVENT_PLAYER_DEATH
} EventType;

typedef struct {
    EventType type;
    void* data;
} Event;

void event_dispatch(Event* event);
#endif // EVENT_H
