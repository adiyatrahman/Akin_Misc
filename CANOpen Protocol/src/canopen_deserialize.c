#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to deserialize a CANopen-like message
void deserialize(const unsigned char* message) {
    // Extract the fixed part of the message
    unsigned char node_id = message[0];               // Node ID (1 byte)
    unsigned char command = message[1];               // Command (1 byte)
    unsigned short index = message[2] | (message[3] << 8);  // Index (2 bytes, little-endian)
    unsigned char subindex = message[4];              // Subindex (1 byte)
    unsigned char data_length = message[5];           // Data length (1 byte)

    // Extract the variable length data part
    char data[data_length + 1];                       // Create a buffer for data
    memcpy(data, &message[6], data_length);           // Copy data from the message
    data[data_length] = '\0';                         // Null-terminate the string

    printf("Deserialized CANopen message in C:\n");
    printf("Node ID: %d\n", node_id);
    printf("Command: 0x%X\n", command);
    printf("Index: 0x%X\n", index);
    printf("Subindex: %d\n", subindex);
    printf("Data: %s\n", data);
}

int main() {
    // Serialized CANopen message input (paste the message from Python serialization here)
    const unsigned char message[] = {0x0A, 0xA1, 0x00, 0x20, 0x01, 0x0D, 0x41, 0x64, 0x69, 0x79, 0x61, 0x74, 0x20, 0x52, 0x61, 0x68, 0x6D, 0x61, 0x6E};
    // Deserialize the message
    deserialize(message);

    return 0;
}
