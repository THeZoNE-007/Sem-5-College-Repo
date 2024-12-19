from scapy.all import rdpcap, Ether, IP, TCP, UDP, ARP, DHCP

# Load the PCAP file
packets = rdpcap('example.pcap')

# Function to print details of each layer in a packet
def print_layer_details(layer):
    layer_name = layer.__class__.__name__ #extracts the name of the class of the given layer
    print(f"Layer: {layer_name}")  # Print the layer name
    try:
        # Print the fields of the layer
        fields = layer.fields
        for field_name, field_value in fields.items():
            print(f"  {field_name}: {field_value}")
    except Exception as e:
        print(f"  Error while processing fields: {e}")

# Process all packets in the PCAP file
print("Packet details:")
for packet in packets:
    print(f"Packet type: {type(packet)}")
    
    # If the packet is an Ethernet frame, check for specific protocols
    if isinstance(packet, Ether):
        # Check for ARP, IP, or other protocols encapsulated in Ethernet frames
        if packet.haslayer(ARP):
            print_layer_details(packet[ARP])  # ARP layer
        elif packet.haslayer(IP):
            print_layer_details(packet[IP])   # IP layer
            if packet.haslayer(TCP):
                print_layer_details(packet[TCP])  # TCP layer
            elif packet.haslayer(UDP):
                print_layer_details(packet[UDP])  # UDP layer
        else:
            print("Ethernet frame without higher layers")
    else:
        print_layer_details(packet)

    print("=" * 60)
