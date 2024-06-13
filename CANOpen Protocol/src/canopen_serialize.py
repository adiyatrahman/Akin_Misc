import struct

def serialize(node_id, command, index, subindex, data):
    # Convert the data to bytes
    data_bytes = data.encode('utf-8')
    data_length = len(data_bytes)
    
    # Create the CANopen message
    # struct.pack creates a packed binary string from the given values
    # 'B' stands for unsigned char (1 byte)
    # 'H' stands for unsigned short (2 bytes)
    message = struct.pack('B B H B B', node_id, command, index, subindex, data_length) + data_bytes
    
    return message

# Example data to be serialized
node_id = 10
command = 0xA1  # Write command
index = 0x2000  # Index in CANopen dictionary
subindex = 1    # Subindex in CANopen dictionary
data = "Adiyat Rahman"  # Data to be sent

# Serialize the data
message = serialize(node_id, command, index, subindex, data)
print("Serialized CANopen message in Python:")
# Print the serialized message as a hexadecimal string
print(message.hex())
hex_string = str(message.hex())
print(hex_string)

# convert the hex string into an array of bytes
byte_array = [int(hex_string[i:i+2], 16) for i in range(0, len(hex_string), 2)]
c_byte_array = "{" + ", ".join([f"0x{byte:02X}" for byte in byte_array]) + "}"
print(c_byte_array)


