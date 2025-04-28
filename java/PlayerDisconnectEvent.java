package garyflow;

public class PlayerDisconnectEvent extends PluginEvent {
    public PlayerDisconnectEvent(Object data) {
        super(Type.PLAYER_QUIT, data);
    }
}
