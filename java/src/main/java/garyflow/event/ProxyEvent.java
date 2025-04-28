package garyflow.event;

public abstract class ProxyEvent {
    private boolean cancelled = false;
    public boolean isCancelled() { return cancelled; }
    public void setCancelled(boolean cancel) { this.cancelled = cancel; }
}
