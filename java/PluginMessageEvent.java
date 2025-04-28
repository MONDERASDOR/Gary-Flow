package garyflow;

public class PluginMessageEvent extends PluginEvent {
    private final String channel;
    private final byte[] data;
    public PluginMessageEvent(String channel, byte[] data, Object context) {
        super(Type.PLUGIN_MESSAGE, context);
        this.channel = channel;
        this.data = data;
    }
    public String getChannel() { return channel; }
    public byte[] getData() { return data; }
}
