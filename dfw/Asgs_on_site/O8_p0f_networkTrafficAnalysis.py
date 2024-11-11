import sys


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
print("Unique Client-Server communications :", find_unique_entries(c_s_comm))


print("\nQ8 - (iii)\n")
print("Unique Client Ports :",len(find_unique_entries(cPort)))
print("Unique Server Ports :",len(find_unique_entries(sPort)))


print("\nQ8 - (iv & v)\n")
recent = oldest = 0
with open(sys.argv[1], 'r') as file:
	l = file.readlines()
	for i in l:
		if i[1:20] >= l[recent][1:20]:
			recent = l.index(i)
		else:
			oldest = l.index(i)
	print(f"Recent packet :\n{l[recent]}\n")
	print(f"Oldest packet :\n{l[oldest]}\n")
