package garyflow;

public class PluginLifecycleEvent extends PluginEvent {
    public enum LifecycleType {
        ENABLE,
        DISABLE,
        RELOAD
    }
    private final LifecycleType lifecycleType;
    public PluginLifecycleEvent(LifecycleType lifecycleType, Object data) {
        super(Type.PLUGIN_LIFECYCLE, data);
        this.lifecycleType = lifecycleType;
    }
    public LifecycleType getLifecycleType() { return lifecycleType; }
}
