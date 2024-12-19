
import subprocess
import re

def scan_ip_mac_and_ports_status(network_range, ports=[80, 443, 22]):
    try:
        # Convert ports list to a comma-separated string
        ports_str = ",".join(map(str, ports))

        # Run the nmap command to scan IP, MAC, and port statuses
        result = subprocess.run(
            ["sudo", "nmap", "-p", ports_str, network_range],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        if result.returncode != 0:
            print("Error running nmap:", result.stderr)
            return []

        # Debug: Print the raw output for verification (remove or comment out in production)
        #print("Nmap Output:\n", result.stdout)

        # Regex patterns
        ip_regex = r"Nmap scan report for ([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)"
        mac_regex = r"MAC Address: ([0-9A-Fa-f:]+)"
        port_status_regex = r"(\d+)/tcp\s+(\w+)\s+(\w+)"

        devices = []
        ip_address = None
        mac_address = None
        port_status = {str(port): "" for port in ports}  # Initialize with "not found"
      
        # Parse the nmap output
        for line in result.stdout.splitlines():
            ip_match = re.search(ip_regex, line)
            mac_match = re.search(mac_regex, line)
            port_status_match = re.search(port_status_regex, line)

            if ip_match:
                # Save current device directly as each IP is unique
                ip_address = ip_match.group(1)

                # Reset MAC and port status for next IP
                #mac_address = None
                #port_status = {str(port): "not found" for port in ports}

            if mac_match:
                mac_address = mac_match.group(1)

            if port_status_match:
                port = port_status_match.group(1)
                status = port_status_match.group(2)
                service=port_status_match.group(3)
                if port in port_status:  # Only consider specified ports
                    port_status[port] = f"{status} service={service}"
                    dict1={
                    "IP": ip_address,
                    "MAC": mac_address if mac_address else "Unknown",
                    **port_status,
                    }
                    found=False
                    for dev in devices:
                        if dev["IP"]==dict1.get("IP"):
                            found=True
                    if not found:
                        devices.append(dict1)

        ip_address = None
        mac_address = None
        port_status=[]
        return devices

    except Exception as e:
        print("An error occurred:", str(e))
        return []

# Example usage
network = input("Enter a ip address/cidr: ") # Replace with your network range
ports=[]  # List of ports to scan
while True:
    portNo=int(input("Enter a port no.: press -1 to break:"))
    if(portNo==-1):
        break
    else:
        ports.append(portNo)    
devices = scan_ip_mac_and_ports_status(network, ports)
with open("./output.csv","a") as file:
    for dev in devices:
        s=str(dev)
        file.writelines([s])
    file.close()    
if devices:
    print("Discovered devices with port 80 and 443 status:")
    for device in devices:
        print(device)
else:
    print("No devices found.")

