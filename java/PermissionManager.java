package garyflow;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class PermissionManager {
    private final Map<String, Set<String>> permissions = new HashMap<>();

    public void grantPermission(String player, String permission) {
        permissions.computeIfAbsent(player, k -> new HashSet<>()).add(permission);
    }

    public boolean hasPermission(String player, String permission) {
        return permissions.getOrDefault(player, new HashSet<>()).contains(permission);
    }
}
