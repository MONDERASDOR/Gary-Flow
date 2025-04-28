package garyflow;

public class PlayerPermissionEvent extends PluginEvent {
    private final String permission;
    private final boolean granted;
    public PlayerPermissionEvent(String permission, boolean granted, Object data) {
        super(Type.PLAYER_PERMISSION, data);
        this.permission = permission;
        this.granted = granted;
    }
    public String getPermission() { return permission; }
    public boolean isGranted() { return granted; }
}
