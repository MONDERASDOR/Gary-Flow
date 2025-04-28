#include "event.h"
#include <stdio.h>
void event_dispatch(Event* event) {
    // Dispatch event to plugin system (to be bridged with Java)
    printf("Dispatched event type: %d\n", event->type);
}
