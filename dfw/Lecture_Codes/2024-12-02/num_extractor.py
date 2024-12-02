import re
import sys

def extract_ip_addresses(file_path):
    # Regular expression pattern for matching IPv4 addresses with leading pipe and whitespace
    ip_pattern = re.compile(r'^\s*\|\s*(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)', re.MULTILINE)

    # Read the Nmap scan results from the specified file
    with open(file_path, 'r') as file:
        content = file.read()

    # Find all IP addresses in the content
    ip_addresses = ip_pattern.findall(content)

    # Clean up the IP addresses by stripping leading pipe and whitespace
    cleaned_ips = [ip.strip('| ').strip() for ip in ip_addresses]

    return cleaned_ips

def write_ips_to_file(ip_list, output_file):
    # Write each IP address to a new line in the specified output file
    with open(output_file, 'w') as f:
        for ip in ip_list:
            f.write(ip + '\n')

# Example usage
if __name__ == "__main__":
    input_file_path = sys.argv[1]  # Input file path from command line argument
    output_file_path = sys.argv[2]  # Output file to store IP addresses

    ips = extract_ip_addresses(input_file_path)
    
    # Write the extracted IP addresses to a file
    write_ips_to_file(ips, output_file_path)

    print(f"Extracted IP Addresses written to {output_file_path}")
