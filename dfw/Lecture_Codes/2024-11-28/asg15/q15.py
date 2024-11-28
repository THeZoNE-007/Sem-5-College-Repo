import re

# Input and output file paths
input_file = "filter_asg15_log.csv"
output_file = "pre_process.csv"

# Regular expression to check if a line starts with a number
starts_with_number = re.compile(r'^\d')

# Open the input file for reading and the output file for writing
with open(input_file, "r") as infile, open(output_file, "w") as outfile:
    for line in infile:
        # Check if the line starts with a number
        if starts_with_number.match(line):
            outfile.write(line)

print(f"Filtered content saved to {output_file}")

# Manually copy the last packet reading chunk
