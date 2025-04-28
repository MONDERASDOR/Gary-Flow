package garyflow;

public class PluginContext {
    private final BackendServer backendServer;
    private final PlayerSession playerSession;

    public PluginContext(BackendServer backendServer, PlayerSession playerSession) {
        this.backendServer = backendServer;
        this.playerSession = playerSession;
    }

    public BackendServer getBackendServer() { return backendServer; }
    public PlayerSession getPlayerSession() { return playerSession; }
}
