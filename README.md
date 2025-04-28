![Gary Flow Logo](logo.svg)
# Gary Flow

Gary Flow is a next-generation, ultra-high-performance Minecraft proxy server designed to handle 10,000+ concurrent players with minimal latency. It supports all Minecraft versions from 1.7 to 1.20+, is cross-platform (Linux/Windows), and features full Paper plugin compatibility via a robust C/Java architecture.

## Features
- Core networking in C for maximum performance
- Plugin system in Java for Paper plugin compatibility
- Cross-platform: Linux (epoll) and Windows (IOCP)
- Supports Minecraft 1.7 through 1.20+
- No artificial limitations, no lag. nothing to be scared of
- **Comprehensive protocol engine:** Real packet parsing, translation, and handshake/login/play support for 1.7, 1.8, 1.12, 1.16, 1.19, 1.20
- **Universal plugin/event system:** Java API for all major proxy events (join, quit, chat, server switch, etc), Paper/Bungee compatibility
- **JNI bridge:** Real-time event dispatch between C core and Java plugins
- **Load balancing, backend pools, and horizontal scaling**

## Directory Structure
- `core/` — C networking and protocol handling
- `java/` — Java plugin loader and Paper API compatibility
- `bridge/` — C/Java communication (JNI or IPC)
- `protocols/` — Protocol definitions for all supported Minecraft versions
- `build/`, `scripts/` — Build scripts (CMake, Maven), automation, and helpers

---

## Building Gary Flow

### Linux/macOS (Bash)
```sh
./scripts/build_all.sh
```

### Windows (MinGW Only, No CMake/Make Needed)
1. Install [MinGW](https://www.mingw-w64.org/) and ensure `gcc` is in your PATH.
2. Open Command Prompt and run:
```bat
scripts\build_all.bat
```
- This will compile all C source files in `core/`, `bridge/`, and `protocols/` into `build/garyflow.exe` using MinGW's gcc.
- Then it will build the Java plugin system with Maven.

### Windows (CMake/Maven)
```sh
cmake -S . -B build
cmake --build build
cd java
mvn package
```

---

## Setting Up with Paper Servers

1. **Set up your backend Paper servers:**
    - Download and configure your PaperMC servers.
    - In each Paper server's `server.properties`, set:
      ```
      online-mode=false
      ```
    - Make sure each Paper server listens on a unique port (not 25565).

2. **Configure Gary Flow:**
    - Edit the Gary Flow config (to be implemented; typically YAML/JSON) to list backend servers:
      ```yaml
      servers:
        - name: lobby
          address: 127.0.0.1
          port: 25566
        - name: survival
          address: 127.0.0.1
          port: 25567
      ```

3. **Start Gary Flow:**
    - Linux/macOS:
      ```sh
      ./build/garyflow
      ```
    - Windows:
      ```
      build\\garyflow.exe
      ```

4. **Connect Minecraft Clients:**
    - Players connect to the IP and port where Gary Flow is running (default: 25565).
    - Gary Flow handles authentication and routes players to backend Paper servers.

5. **Use Paper Plugins:**
    - Place plugins in the `java/plugins/` directory (or as configured).
    - Gary Flow's plugin loader will load and manage these plugins, exposing proxy and Paper API events.

---

## Protocol Support & Plugin System
- **Supports handshake, status, login, and play packets for all major protocol versions (1.7, 1.8, 1.12, 1.16, 1.19, 1.20)**
- **Automatic version negotiation and translation between client and backend**
- **Java event system fires PlayerJoin, PlayerQuit, PlayerChat, ServerSwitch, and more**
- **JNI bridge connects C core to Java plugin system for real-time event handling**

---

## How Gary Flow Handles 10,000+ Players
- **C core with async IO (epoll/IOCP) for high concurrency**
- **Non-blocking sockets, thread pool for heavy ops**
- **Efficient memory/session management and zero-copy packet handling**
- **Horizontal scaling with backend server pools and load balancing**
- **No artificial player limits—hardware is the only constraint**

### Scaling Tips
- Use a modern multi-core CPU, 32GB+ RAM, and high-bandwidth network
- Tune OS for high file descriptor and socket limits
- Run multiple backend Paper servers for true scalability

---

## Automation Scripts
- `./scripts/build_all.sh` — Build everything (Linux/macOS)
- `./scripts/run_proxy.sh` — Start the proxy (Linux/macOS)
- `scripts/build_all.bat` — Build everything (Windows)

---

*This project is under active development. All of the project might have logical bugs. IF happened so, report it in the issues and wait. The code in general is ready. For advanced configuration or development, see the codebase and expand as needed.*


brought by the legend of development (not) . and the lead dev. Sunpowder  
