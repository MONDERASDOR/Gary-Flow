package garyflow;

public class PluginLogger {
    public void info(String msg) {
        System.out.println("[INFO] " + msg);
    }
    public void warn(String msg) {
        System.out.println("[WARN] " + msg);
    }
    public void error(String msg) {
        System.err.println("[ERROR] " + msg);
    }
}
