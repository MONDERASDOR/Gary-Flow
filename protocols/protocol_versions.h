#ifndef PROTOCOL_VERSIONS_H
#define PROTOCOL_VERSIONS_H

// Supported Minecraft protocol versions
#define PROTOCOL_1_7   4
#define PROTOCOL_1_8   47
#define PROTOCOL_1_12  340
#define PROTOCOL_1_16  735
#define PROTOCOL_1_19  761
#define PROTOCOL_1_20  763

// Function to get protocol version from handshake packet
int get_protocol_version(const unsigned char *handshake_packet, int length);

#endif // PROTOCOL_VERSIONS_H
