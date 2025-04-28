package garyflow;

public class CommandEvent extends PluginEvent {
    private final String command;
    private final String[] args;

    public CommandEvent(String command, String[] args, Object data) {
        super(Type.PLAYER_COMMAND, data);
        this.command = command;
        this.args = args;
    }

    public String getCommand() { return command; }
    public String[] getArgs() { return args; }
}
