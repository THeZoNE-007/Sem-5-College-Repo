import subprocess
import re

def network_device_scan(network, ports_to_scan=[80, 443, 22]):
    try:
        # Join the list of ports into a comma-separated string for nmap command
        ports = ",".join(map(str, ports_to_scan))

        # Execute nmap to scan the provided network range
        scan_output = subprocess.run(
            ["sudo", "nmap", "-p", ports, network],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        if scan_output.returncode != 0:
            print("Error while running nmap:", scan_output.stderr)
            return []

        # Regex patterns to capture IPs, MAC addresses, and port statuses
        ip_pattern = r"Nmap scan report for ([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)"
        mac_pattern = r"MAC Address: ([0-9A-Fa-f:]+)"
        port_pattern = r"(\d+)/tcp\s+(\w+)\s+(\w+)"

        found_devices = []
        current_ip = None
        current_mac = None
        port_details = {str(port): "Not Detected" for port in ports_to_scan}  # Initialize with default value

        # Process each line of nmap scan result
        for line in scan_output.stdout.splitlines():
            ip_match = re.search(ip_pattern, line)
            mac_match = re.search(mac_pattern, line)
            port_match = re.search(port_pattern, line)

            if ip_match:
                current_ip = ip_match.group(1)
                # Reset port details for the new device
                port_details = {str(port): "Not Detected" for port in ports_to_scan}

            if mac_match:
                current_mac = mac_match.group(1)

            if port_match:
                port_number = port_match.group(1)
                port_status = port_match.group(2)
                port_service = port_match.group(3)

                if port_number in port_details:
                    # Update port status for the specific port
                    port_details[port_number] = f"{port_status} ({port_service})"

                    # Create device information dictionary
                    device_info = {
                        "IP": current_ip,
                        "MAC": current_mac if current_mac else "Unknown",
                        **port_details,
                    }

                    # Avoid duplicates by checking if the device is already in the list
                    if not any(device["IP"] == device_info["IP"] for device in found_devices):
                        found_devices.append(device_info)

        return found_devices

    except Exception as e:
        print("An error occurred while scanning:", str(e))
        return []

# Main function to interact with the user and handle the device scanning
if __name__ == "__main__":
    network_input = input("Please enter the network range (e.g., 192.168.1.0/24): ")
    ports_input = []  # List to store selected ports

    # Collect ports from the user input
    while True:
        try:
            port_number = int(input("Enter a port number to scan (enter -1 to stop): "))
            if port_number == -1:
                break
            else:
                ports_input.append(port_number)
        except ValueError:
            print("Please enter a valid port number.")

    # Call the function to scan the network
    scanned_devices = network_device_scan(network_input, ports_input)

    # Output the scan results to a CSV file
    with open("device_scan_results.csv", "a") as file:
        for device in scanned_devices:
            file.write(f"{str(device)}\n")

    # Display the devices found in the scan
    if scanned_devices:
        print("Devices discovered with specified ports:")
        for device in scanned_devices:
            print(device)
    else:
        print("No devices found with the given criteria.")

