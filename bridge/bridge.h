#ifndef BRIDGE_H
#define BRIDGE_H
#include <jni.h>
#include "event.h"

// Bridge: Send event from C to Java plugin system
void bridge_send_event(JNIEnv* env, Event* event);

#endif // BRIDGE_H
