package: header + topic + message
header: sequence number + topic length + message length + message type
message type: 'M' (message) or 'H' (heartbeat)

The length of a heartbeat message is 0.
