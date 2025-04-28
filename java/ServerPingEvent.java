package garyflow;

public class ServerPingEvent extends PluginEvent {
    private final String hostname;
    private final int port;
    public ServerPingEvent(String hostname, int port, Object data) {
        super(Type.SERVER_PING, data);
        this.hostname = hostname;
        this.port = port;
    }
    public String getHostname() { return hostname; }
    public int getPort() { return port; }
}
