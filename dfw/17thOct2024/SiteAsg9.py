import sys

# Function to read nth column separated by given separator
def read_nth_column(file_path, n, separator):
    column_data = []
    with open(file_path, 'r') as file:
        for line in file:
            # Split the line into columns based on the specified separator
            columns = line.split(separator)
            if len(columns) > n:  # Check if the nth column exists
                column_data.append(columns[n].strip())
    return column_data

# Function to read unique entries only
def find_unique_entries(array):
    return list(set(array))

# Function to count occurrences of items in a list
def count_occurrences(array):
    counts = {}
    for item in array:
        if item in counts:
            counts[item] += 1
        else:
            counts[item] = 1
    return counts

file_path = sys.argv[1]

client = read_nth_column(file_path, 1, "|")  # Array storing raw client ip/port
cIP = []  # Array storing raw client ip only
cPort = []  # Array storing client ports only
for i in client:    
    pattern = "/"
    client_ip = i.split(pattern)[0]
    port = i.split(pattern)[-1] 
    cIP.append(client_ip)
    cPort.append(port)

server = read_nth_column(file_path, 2, "|")  # Array storing raw server ip/port
sIP = []  # Array storing raw server ip only
sPort = []  # Array storing server ports only
for i in server:
    pattern = "/"
    server_ip = i.split(pattern)[0]
    port = i.split(pattern)[-1] 
    sIP.append(server_ip)
    sPort.append(port)

print("Q9 - (i)\n")
print("No. of Unique Client(s) :", len(find_unique_entries(cIP)))
print("No. of Unique Server(s) :", len(find_unique_entries(sIP)))

print("\nQ9 - (ii)\n")
c_s_comm = [f"{a}<->{b}" for a, b in zip(cIP, sIP)]  # Client-Server merger array
# Unique c_s_comms
print("Unique Client-Server communications :", len(find_unique_entries(c_s_comm)))

print("\nQ9 - (iii)\n")
print("Unique Client Ports :", len(find_unique_entries(cPort)))
print("Unique Server Ports :", len(find_unique_entries(sPort)))

# Q9 - (iv): Identify the most popular and least used port numbers
all_ports = cPort + sPort  # Combine both client and server ports
port_counts = count_occurrences(all_ports)

most_common_port = max(port_counts.items(), key=lambda x: x[1])
least_common_port = min(port_counts.items(), key=lambda x: x[1])

print("\nQ9 - (iv)\n")
print(f"Most popular port: {most_common_port[0]} (used {most_common_port[1]} times)")
print(f"Least used port: {least_common_port[0]} (used {least_common_port[1]} time)")

# Q9 - (v): Find the timestamps of the latest and oldest packets.
timestamps = read_nth_column(file_path, 3, "|")  # Assuming timestamp is in the third column
timestamps = [float(ts) for ts in timestamps]  # Convert to float for comparison

oldest_timestamp = min(timestamps)
latest_timestamp = max(timestamps)

print("\nQ9 - (v)\n")
print(f"Oldest packet timestamp: {oldest_timestamp}")
print(f"Latest packet timestamp: {latest_timestamp}")

# Q9 - (vi): List the detected operating systems.
os_list = read_nth_column(file_path, 4, "|")  # Assuming OS info is in the fourth column
unique_os_list = find_unique_entries(os_list)

print("\nQ9 - (vi)\n")
print("Detected Operating Systems:")
for os in unique_os_list:
    print(os)

# Q9 - (vii): Identify the client IP address and port that has remained active for the longest time.
client_activity_duration = {}  # Dictionary to store client activity duration
for i in range(len(cIP)):
    key = f"{cIP[i]}:{cPort[i]}"
    if key not in client_activity_duration:
        client_activity_duration[key] = 1  # Initialize with count of occurrences
    else:
        client_activity_duration[key] += 1

longest_active_client = max(client_activity_duration.items(), key=lambda x: x[1])

print("\nQ9 - (vii)\n")
print(f"Client with longest activity: {longest_active_client[0]} with {longest_active_client[1]} connections")

