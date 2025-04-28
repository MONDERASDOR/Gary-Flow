package garyflow.event;

public class ServerSwitchEvent extends ProxyEvent {
    private final String playerName;
    private final String fromServer;
    private final String toServer;
    public ServerSwitchEvent(String playerName, String fromServer, String toServer) {
        this.playerName = playerName;
        this.fromServer = fromServer;
        this.toServer = toServer;
    }
    public String getPlayerName() { return playerName; }
    public String getFromServer() { return fromServer; }
    public String getToServer() { return toServer; }
}
