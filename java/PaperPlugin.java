package garyflow;

public interface PaperPlugin {
    String getName();
    void onEnable();
    void onDisable();
    void onEvent(PluginEvent event);
}
