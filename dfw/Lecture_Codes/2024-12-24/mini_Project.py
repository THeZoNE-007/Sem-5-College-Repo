from scapy.all import rdpcap, DNS, IP, ICMP, TCP, ARP
from collections import Counter
from collections import defaultdict
import time

import sys
#Load the PCAP file

packets = rdpcap(sys.argv[1])
"""
# Inspect packets
for packet in packets:
	print(packet.summary())
"""
non_standard_ports = set()

# Rule 1: Detecting Traffic on Non-Standard Ports
for packet in packets:
	if packet.haslayer('TCP'):
		tcp_layer = packet['TCP']
		if tcp_layer.dport not in [80,443,22]: # Add standard destination ports
			non_standard_ports.add(tcp_layer.dport)

print("Non-standard ports detected:", non_standard_ports)
