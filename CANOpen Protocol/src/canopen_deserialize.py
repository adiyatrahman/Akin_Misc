import struct

def deserialize(message):
    # Extract the fixed part of the message (first 6 bytes)
    node_id, command, index, subindex, data_length = struct.unpack('B B H B B', message[:6])
    
    # Extract the variable length data part
    data = message[6:6+data_length].decode('utf-8')
    
    return {
        'node_id': node_id,
        'command': command,
        'index': index,
        'subindex': subindex,
        'data': data
    }

# Serialized CANopen message input (paste the message from C serialization here)
message = bytes.fromhex("01010020010d416469796174205261686d616e")  # Example input in hex format
deserialized_data = deserialize(message)

print("\nDeserialized CANopen message in Python:")
print(deserialized_data)
