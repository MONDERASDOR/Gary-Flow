package garyflow;

public class PlayerSession {
    private final String uuid;
    private final String username;
    private boolean online;

    public PlayerSession(String uuid, String username) {
        this.uuid = uuid;
        this.username = username;
        this.online = true;
    }

    public String getUuid() { return uuid; }
    public String getUsername() { return username; }
    public boolean isOnline() { return online; }
    public void setOnline(boolean online) { this.online = online; }
}
