package garyflow;

public class NetworkEvent extends PluginEvent {
    public enum NetworkType {
        CONNECTION_LOST,
        CONNECTION_ESTABLISHED,
        PACKET_RECEIVED,
        PACKET_SENT
    }
    private final NetworkType networkType;
    public NetworkEvent(NetworkType networkType, Object data) {
        super(Type.NETWORK, data);
        this.networkType = networkType;
    }
    public NetworkType getNetworkType() { return networkType; }
}
