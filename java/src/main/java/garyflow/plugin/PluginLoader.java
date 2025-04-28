package garyflow.plugin;

import garyflow.event.ProxyEventListener;
import java.util.ServiceLoader;

public class PluginLoader {
    public static void loadPlugins() {
        ServiceLoader<ProxyEventListener> loader = ServiceLoader.load(ProxyEventListener.class);
        for (ProxyEventListener listener : loader) {
            PluginManager.registerListener(listener);
            System.out.println("[PluginLoader] Registered plugin: " + listener.getClass().getName());
        }
    }
}
