import pyshark

capture = pyshark.FileCapture('/home/c204-002/.ashu_34/ipp.pcap',display_filter='http')
for packet in capture:
	print(packet.http)
