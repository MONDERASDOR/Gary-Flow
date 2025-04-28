package garyflow.plugin;

import garyflow.event.*;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

public class PluginManager {
    private static final List<ProxyEventListener> listeners = new CopyOnWriteArrayList<>();

    public static void registerListener(ProxyEventListener listener) {
        listeners.add(listener);
    }

    public static void unregisterListener(ProxyEventListener listener) {
        listeners.remove(listener);
    }

    public static void fireEvent(ProxyEvent event) {
        for (ProxyEventListener listener : listeners) {
            if (event instanceof PlayerJoinEvent) {
                listener.onPlayerJoin((PlayerJoinEvent) event);
            } else if (event instanceof PlayerQuitEvent) {
                listener.onPlayerQuit((PlayerQuitEvent) event);
            } else if (event instanceof PlayerChatEvent) {
                listener.onPlayerChat((PlayerChatEvent) event);
            } else if (event instanceof ServerSwitchEvent) {
                listener.onServerSwitch((ServerSwitchEvent) event);
            }
        }
    }
}
