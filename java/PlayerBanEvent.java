package garyflow;

public class PlayerBanEvent extends PluginEvent {
    private final String reason;
    private final long durationMillis;
    public PlayerBanEvent(String reason, long durationMillis, Object data) {
        super(Type.PLAYER_BAN, data);
        this.reason = reason;
        this.durationMillis = durationMillis;
    }
    public String getReason() { return reason; }
    public long getDurationMillis() { return durationMillis; }
}
