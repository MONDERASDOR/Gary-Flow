package garyflow;

public class PluginEvent {
    public enum Type {
        PLAYER_JOIN,
        PLAYER_QUIT,
        PLAYER_CHAT,
        PLAYER_COMMAND
    }

    private final Type type;
    private final Object data;

    public PluginEvent(Type type, Object data) {
        this.type = type;
        this.data = data;
    }

    public Type getType() { return type; }
    public Object getData() { return data; }
}
