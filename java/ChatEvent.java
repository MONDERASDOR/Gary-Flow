package garyflow;

public class ChatEvent extends PluginEvent {
    private final String message;

    public ChatEvent(String message, Object data) {
        super(Type.PLAYER_CHAT, data);
        this.message = message;
    }

    public String getMessage() { return message; }
}
