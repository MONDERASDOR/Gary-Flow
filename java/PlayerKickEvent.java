package garyflow;

public class PlayerKickEvent extends PluginEvent {
    private final String reason;
    public PlayerKickEvent(String reason, Object data) {
        super(Type.PLAYER_KICK, data);
        this.reason = reason;
    }
    public String getReason() { return reason; }
}
