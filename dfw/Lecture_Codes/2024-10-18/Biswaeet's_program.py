import argparse as ap
import re
from datetime import timedelta
parser=ap.ArgumentParser(description="sample argument")
parser.add_argument("filePath",type=str,help="input file required!!")
args=parser.parse_args()

def read_nth_column(file_path, n, separator):
   column_data = []
   with open(file_path, 'r') as file:
       for line in file:
 # Split the line into columns based on the specified separator
           columns = line.split(separator)
           if len(columns) > n: # Check if the nth column exists
               column_data.append(columns[n])
   file.close()
   return column_data
def packetCapture():
    time1=""
    time2=""
    last_line=None
    print("\nOldest packet captured:")
    with open(args.filePath,'r') as file:
        for line in file:
            print(line,"\n")
            time1=line[1:20]
            print(f"\ntimestamp of oldest packet: {time1} ")
            break
        for line in file:
            last_line=line
    time2=last_line[1:20]        
    file.close()
    print("\nMost recent Packet:")
    print(last_line)
    print(f"\ntimestamp of recent packet: {time2} ")            
                    
clients = read_nth_column(args.filePath,1,"|")
clients_ipOnly=[]
clients_ports=[]
clients_all_port=[]
for ip in clients:
    newIp=ip[4:17].replace("/","")
    port=ip[18:]
    if port not in clients_ports:
        clients_ports.append(port)
    clients_all_port.append(port)    
    
    if newIp not in clients_ipOnly:
        clients_ipOnly.append(newIp)
        
print(f"Unique clients: {len(clients_ipOnly)}")
print(f"Unique clients ports: {len(clients_ports)}")

server_ipOnly=[]
server_ports=[]
servers = read_nth_column(args.filePath,2,"|")
server_all_port=[]
for ip in servers:
    port=ip[18:].replace("/","")
    if port not in server_ports:
        server_ports.append(port)
    server_all_port.append(port)

    newIp=ip[4:17]
    if newIp not in server_ipOnly:
        server_ipOnly.append(newIp.replace("/",""))
        
print(f"Unique servers: {len(server_ipOnly)}")
print(f"Unique server ports: {len(server_ports)}")
#-----------------------------------

#unique_client_server=[]
#for serverIp in server_ipOnly:
#    elem=f"client:{clients_ipOnly[0]}-->server:{serverIp}";
#    unique_client_server.append(elem)
#print("Unique client server communications are: \n")
#print(unique_client_server)
#--------------------------------
packetCapture()
#--------------------------------
data=read_nth_column(args.filePath,4,"|")
detected_os=[]
for os in data:
    if "os=" in os:
        if "???" in os:
            continue
        else:
            if os[3:] not in detected_os:
                detected_os.append(os[3:])
print("All the detected OS:",f"\n{detected_os}")
#------------------------
ports={}
for port in clients_all_port:
    if port in ports:
        ports[port]+=1
    else:
        ports[port]=1    

for port in server_all_port:
    if port in ports:
        ports[port]+=1
    else:
        ports[port]=1   
most_used_port=max(zip(ports.values(), ports.keys()))[1] 
least_used_port=min(zip(ports.values(), ports.keys()))[1]
least_used_port=least_used_port.replace("/","")
print(f"Max used port: {most_used_port} least used port: {least_used_port}") 
#------------------
unique_clsv=[]
with open(args.filePath,'r') as file:
    for line in file:
        #pattern = r'cli=([^|]+)\|srv=([^|]S+)'
        pattern=r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'
        ip_addresses = re.findall(pattern, line)
        elem=f"client: {ip_addresses[0]}-->server:{ip_addresses[1]}"
        if elem not in unique_clsv:
            unique_clsv.append(elem)
print(f"\nTotal unique client server communication: {len(unique_clsv)}")
#------------------------
uptime=read_nth_column(args.filePath,4,"|")
detected_up=[]
for up in uptime:
    if "uptime=" in up:
        if up[7:] not in detected_up:
            detected_up.append(up[7:])

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
    
for time in detected_up:
    t=convert_uptime(time)
    compare(t,time)


with open(args.filePath,'r') as file:
    global packet1
    for line in file:
        if max_uptime_str in line:
            packet1=line
            break
file.close()
rows=packet1.split("|")
clientIP=rows[1]
print(f"the client having ip: {clientIP[4:17]} and port no: {clientIP[18:]} has the most active uptime of {max_uptime_str[:21]}")
        



        

