#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to serialize data into a CANopen-like message
void serialize(unsigned char node_id, unsigned char command, unsigned short index, unsigned char subindex, const char* data) {
    unsigned char data_length = strlen(data);  // Get the length of the data
    unsigned char message[6 + data_length];    // Create a message array of appropriate size

    // Pack the fixed part of the message
    message[0] = node_id;                       // Node ID (1 byte)
    message[1] = command;                       // Command (1 byte)
    message[2] = index & 0xFF;                  // Lower byte of index (2 bytes)
    message[3] = (index >> 8) & 0xFF;           // Higher byte of index (2 bytes)
    message[4] = subindex;                      // Subindex (1 byte)
    message[5] = data_length;                   // Data length (1 byte)

    // Copy the variable length data part into the message
    memcpy(&message[6], data, data_length);     // Copy data into the message array

    // Print the serialized message in hex format
    printf("Serialized CANopen message in C:\n");
    for (int i = 0; i < 6 + data_length; i++) {
        printf("%02x", message[i]);              // Print each byte as a two-digit hex value
    }
    printf("\n");
}

int main() {
    unsigned char node_id = 1;                  // Node ID
    unsigned char command = 0x01;               // Write command
    unsigned short index = 0x2000;              // Index in CANopen dictionary
    unsigned char subindex = 1;                 // Subindex in CANopen dictionary
    const char* data = "Adiyat Rahman";         // Data to be sent

    // Serialize the data
    serialize(node_id, command, index, subindex, data);

    return 0;
}
