from scapy.all import rdpcap

def find_unique_entries(array):
	return list(set(array))

clients = []
servers = []
srcPort = []
dstPort = []	
# Read the PCAP file
packets = rdpcap('./ipp.pcap')
# Iterate through the packets
for packet in packets:
	if packet.haslayer('IP'):
		clients.append(packet['IP'].src) #append src to client list
		srcPort.append(packet['IP'].dport)
		servers.append(packet['IP'].dst)
		dstPort.append(packet['IP'].sport) 
		
		
print("Unique servers:-",len(find_unique_entries(servers)))
print("Unique clients:-",len(find_unique_entries(clients)))

c_s_comm = [f"{a}<->{b}" for a, b in zip(clients, servers)] #Client-Server IP merger array
#Unique c_s_comms
print("Unique Client-Server communications:- ",len(find_unique_entries(c_s_comm)))
		
print("Unique server ports:-",len(find_unique_entries(dstPort)))
print("Unique client ports:-",len(find_unique_entries(srcPort)))

protocol_names = [] #List to store protocol names
for packet in packets: #iterating through each packet
	layer_names = [] #List to store layer names
	while packet: #iterating through each layer
		layer_names.append(packet.name)
		packet=packet.payload
		protocol_names.append(layer_names[-1])
print("Name of protocols:",find_unique_entries(protocol_names))
