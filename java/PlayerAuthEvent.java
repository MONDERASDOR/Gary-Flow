package garyflow;

public class PlayerAuthEvent extends PluginEvent {
    private final boolean authenticated;
    public PlayerAuthEvent(boolean authenticated, Object data) {
        super(Type.PLAYER_AUTH, data);
        this.authenticated = authenticated;
    }
    public boolean isAuthenticated() { return authenticated; }
}
