package garyflow.event;

public class PlayerChatEvent extends ProxyEvent {
    private final String playerName;
    private final String message;

    public PlayerChatEvent(String playerName, String message) {
        this.playerName = playerName;
        this.message = message;
    }

    public String getPlayerName() { return playerName; }
    public String getMessage() { return message; }
}
