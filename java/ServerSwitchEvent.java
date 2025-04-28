package garyflow;

public class ServerSwitchEvent extends PluginEvent {
    private final String fromServer;
    private final String toServer;

    public ServerSwitchEvent(String fromServer, String toServer, Object data) {
        super(Type.SERVER_SWITCH, data);
        this.fromServer = fromServer;
        this.toServer = toServer;
    }

    public String getFromServer() { return fromServer; }
    public String getToServer() { return toServer; }
}
