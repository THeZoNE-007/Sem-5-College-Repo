import sys
from collections import Counter
import re
from  datetime import timedelta

#Funtion to read nth column separated by given separator
def read_nth_column(file_path, n, separator):
	column_data = []
	with open(file_path, 'r') as file:
		for line in file:
# Split the line into columns based on the specified separator
			columns = line.split(separator)
			if len(columns) > n: # Check if the nth column exists
				column_data.append(columns[n])
	return column_data


#Function to read unique entries only
def find_unique_entries(array):
	return list(set(array))

file_path = sys.argv[1]


client = read_nth_column(file_path, 1, "|") # Array storing raw client ip/port
cIP = [] # Array storing raw client ip only
cPort = [] # Array storing client ports only
for i in client:	
	pattern = "/"
	client = i.split(pattern)[0]
	port = i.split(pattern)[-1] 
	cIP.append(client)
	cPort.append(port)

server = read_nth_column(file_path, 2, "|") # Array storing raw server ip/port
sIP = [] # Array storing raw server ip only
sPort = [] # Array storing server ports only
for i in server:
	pattern = "/"
	client = i.split(pattern)[0]
	port = i.split(pattern)[-1] 
	sIP.append(client)
	sPort.append(port)

print("Q8 - (i)\n")
print("No. of Unique Client(s) :", len(find_unique_entries(cIP)))
print("No. of Unique Server(s) :", len(find_unique_entries(sIP)))


print("\nQ8 - (ii)\n")
c_s_comm = [f"{a}<->{b}" for a, b in zip(cIP, sIP)] #Client-Server merger array
#Unique c_s_comms
print("Unique Client-Server communications :", len(find_unique_entries(c_s_comm)))


print("\nQ8 - (iii)\n")
print("Unique Client Ports :",len(find_unique_entries(cPort)))
print("Unique Server Ports :",len(find_unique_entries(sPort)))


print("\nQ8 - (iv & v)\n")

PortsCombine = cPort + sPort
PortOccurrence = Counter(PortsCombine)


minOccur = min(PortOccurrence.values())
maxOccur = max(PortOccurrence.values())
min = []
max = []

for i in PortOccurrence:
	if PortOccurrence[i] == minOccur:
		min.append(i)
	if PortOccurrence[i] == maxOccur:
		max.append(i)

print("Most popular ports\n",max)
print("Least popular ports\n",min)

print("\nQ8 - (v)\n")
with open(sys.argv[1], 'r') as file:
	l = file.readlines()
	oldest = l[0]
	recent = l[-1]
	print(f"(iv)\nTimestamp of recent packet is:\n",recent[1:20])
	print(f"(iv)\nTimestamp of oldest packet is:\n",oldest[1:20])
	
print("\nQ8 - (vi)\n")
osCol = read_nth_column(file_path, 4, "|")
os = []
for i in osCol:
	if i.startswith("os"):
		os.append(i[3:])
print(find_unique_entries(os))

print("\nQ8 - (vii)\n")
uptimeCol = read_nth_column(file_path, 4, "|")
uptime = []
print("Available uptimes:")
for i in uptimeCol:
	if i.startswith("uptime"):
		uptime.append(i[7:-17])
		print(i[7:-17])

def convert_uptime(uptime):
    parts=uptime.split()
    days=int(parts[0])
    hours=int(parts[2])
    minutes=int(parts[4])
    return timedelta(days=days,hours=hours,minutes=minutes)

maxUptime=timedelta(days=0,hours=0,minutes=0)
max_uptime_str=""
def compare(t,time):
    global maxUptime
    global max_uptime_str
    if t>maxUptime:
        maxUptime=t
        max_uptime_str=time
    
for time in uptime:
    t=convert_uptime(time)
    compare(t,time)
   
col=""
with open(sys.argv[1],'r') as file:
    for line in file:
        if max_uptime_str in line:
            col=line[37:55]
            break
print(f"\nThe ip and port :{col} has the maximum uptime: {max_uptime_str}")

