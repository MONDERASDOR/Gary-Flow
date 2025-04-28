package garyflow;

public class PlayerConnectEvent extends PluginEvent {
    public PlayerConnectEvent(Object data) {
        super(Type.PLAYER_JOIN, data);
    }
}
