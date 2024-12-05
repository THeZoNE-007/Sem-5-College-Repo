import subprocess
import re

def scan_ip_mac_and_port_status(network_range, port80=80):
    try:
        # Run nmap command to scan IP, MAC, and port 80 status
        result = subprocess.run(
            ["sudo", "nmap", "-p", str(port80), network_range],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        if result.returncode != 0:
            print("Error running nmap:", result.stderr)
            return []

        # Regex to match IP, MAC, and port status
        ip_regex = r"Nmap scan report for ([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)"
        mac_regex = r"MAC Address: ([0-9A-Fa-f:]+)"
        port_status_regex = rf"{port80}/tcp\s+(\w+)"

        devices = []
        ip_address = None
        mac_address = None

        # Parse the nmap output
        for line in result.stdout.splitlines():
            ip_match = re.search(ip_regex, line)
            mac_match = re.search(mac_regex, line)
            port_status_match = re.search(port_status_regex, line)

            if ip_match:
                ip_address = ip_match.group(1)

            if mac_match:
                mac_address = mac_match.group(1)

            if port_status_match and ip_address:
                port_status = port_status_match.group(1)
                devices.append({
                    "IP": ip_address,
                    "MAC": mac_address if mac_address else "Unknown",
                    f"Port {port80}": port_status
                })
                ip_address = None
                mac_address = None  # Reset for the next host

        return devices

    except Exception as e:
        print("An error occurred:", str(e))
        return []

# Example usage
network = "172.17.156.63/24"  # Replace with your network range
devices = scan_ip_mac_and_port_status(network)

if devices:
    print("Discovered devices with port 80 status:")
    for device in devices:
        print(device)
else:
    print("No devices found.")
