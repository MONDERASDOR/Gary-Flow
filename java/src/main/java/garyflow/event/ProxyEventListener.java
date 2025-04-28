package garyflow.event;

public interface ProxyEventListener {
    void onPlayerJoin(PlayerJoinEvent event);
    void onPlayerQuit(PlayerQuitEvent event);
    void onPlayerChat(PlayerChatEvent event);
    void onServerSwitch(ServerSwitchEvent event);
}
