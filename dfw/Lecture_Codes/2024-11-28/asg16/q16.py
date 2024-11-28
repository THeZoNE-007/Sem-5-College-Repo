import re
import sys
# Input and output file paths
input_file = sys.argv[1] #"pre_process.csv"
output_file = sys.argv[2] #"asg16_malicious.txt"
malicious_mac = []

# Open the input file for reading and the output file for writing
with open(input_file, "r") as infile, open(output_file, "w") as outfile:
    for line in infile:
        # Check if the line has HP or Dell
        if "HP" not in line and "Dell" not in line:
            outfile.write(line.split(" ")[1]) # Prints the Mac address
            outfile.write(" -> ")
            outfile.write(line.split(" ")[4]) # Prints the respective Vendor

print(f"Malicious MACs saved to {output_file}") # Stores in the o/p file
