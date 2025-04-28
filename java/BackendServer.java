package garyflow;

public class BackendServer {
    private final String address;
    private final int port;
    private int onlinePlayers;

    public BackendServer(String address, int port) {
        this.address = address;
        this.port = port;
        this.onlinePlayers = 0;
    }

    public String getAddress() { return address; }
    public int getPort() { return port; }
    public int getOnlinePlayers() { return onlinePlayers; }
    public void setOnlinePlayers(int onlinePlayers) { this.onlinePlayers = onlinePlayers; }
}
