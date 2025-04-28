package garyflow.event;

public class PlayerJoinEvent extends ProxyEvent {
    private final String playerName;
    private final String address;
    private final int protocolVersion;

    public PlayerJoinEvent(String playerName, String address, int protocolVersion) {
        this.playerName = playerName;
        this.address = address;
        this.protocolVersion = protocolVersion;
    }

    public String getPlayerName() { return playerName; }
    public String getAddress() { return address; }
    public int getProtocolVersion() { return protocolVersion; }
}
