#include "bridge.h"
#include <jni.h>
#include <stdio.h>
#include <string.h>

void bridge_send_event(JNIEnv* env, Event* event) {
    printf("[Bridge] Event sent to Java plugin system: type=%d\n", event->type);
}

// Example JNI event dispatch for PlayerJoinEvent
void dispatch_player_join_event(JNIEnv *env, jobject pluginManager, const char *playerName, const char *address, int protocolVersion) {
    jclass eventClass = (*env)->FindClass(env, "garyflow/event/PlayerJoinEvent");
    if (!eventClass) { printf("[JNI] PlayerJoinEvent class not found\n"); return; }
    jmethodID constructor = (*env)->GetMethodID(env, eventClass, "<init>", "(Ljava/lang/String;Ljava/lang/String;I)V");
    if (!constructor) { printf("[JNI] PlayerJoinEvent constructor not found\n"); return; }
    jstring jPlayerName = (*env)->NewStringUTF(env, playerName);
    jstring jAddress = (*env)->NewStringUTF(env, address);
    jobject eventObj = (*env)->NewObject(env, eventClass, constructor, jPlayerName, jAddress, protocolVersion);
    jclass managerClass = (*env)->GetObjectClass(env, pluginManager);
    jmethodID fireEvent = (*env)->GetStaticMethodID(env, managerClass, "fireEvent", "(Lgaryflow/event/ProxyEvent;)V");
    if (!fireEvent) { printf("[JNI] fireEvent method not found\n"); return; }
    (*env)->CallStaticVoidMethod(env, managerClass, fireEvent, eventObj);
    (*env)->DeleteLocalRef(env, jPlayerName);
    (*env)->DeleteLocalRef(env, jAddress);
    (*env)->DeleteLocalRef(env, eventObj);
}

// Similar JNI dispatch functions would be implemented for PlayerChatEvent, PlayerQuitEvent, ServerSwitchEvent, etc.
