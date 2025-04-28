// Gary Flow - Java Plugin Loader
// Loads Paper plugins and exposes proxy events

package garyflow;

import java.io.File;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.jar.JarFile;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Map;

public class GaryFlowPluginLoader {
    private final Map<String, Object> loadedPlugins = new HashMap<>();

    public void loadPlugins(File pluginsDir) throws Exception {
        if (!pluginsDir.exists() || !pluginsDir.isDirectory()) return;
        for (File file : pluginsDir.listFiles()) {
            if (file.getName().endsWith(".jar")) {
                try (JarFile jar = new JarFile(file)) {
                    URL[] urls = { file.toURI().toURL() };
                    URLClassLoader cl = new URLClassLoader(urls, this.getClass().getClassLoader());
                    Enumeration<java.util.jar.JarEntry> entries = jar.entries();
                    while (entries.hasMoreElements()) {
                        String name = entries.nextElement().getName();
                        if (name.endsWith(".class")) {
                            String className = name.replace('/', '.').substring(0, name.length() - 6);
                            Class<?> clazz = cl.loadClass(className);
                            if (PaperPlugin.class.isAssignableFrom(clazz)) {
                                PaperPlugin plugin = (PaperPlugin) clazz.getDeclaredConstructor().newInstance();
                                loadedPlugins.put(plugin.getName(), plugin);
                                plugin.onEnable();
                            }
                        }
                    }
                }
            }
        }
    }

    public void dispatchEvent(PluginEvent event) {
        for (Object plugin : loadedPlugins.values()) {
            if (plugin instanceof PaperPlugin) {
                ((PaperPlugin) plugin).onEvent(event);
            }
        }
    }
}
