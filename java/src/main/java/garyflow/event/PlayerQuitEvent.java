package garyflow.event;

public class PlayerQuitEvent extends ProxyEvent {
    private final String playerName;
    public PlayerQuitEvent(String playerName) { this.playerName = playerName; }
    public String getPlayerName() { return playerName; }
}
