import subprocess as sp
import sys

# Initialize filter condition and file location
is_filter_enabled = False
input_file = sys.argv[1]

# Check for filter arguments
if len(sys.argv) >= 4 and sys.argv[2] == "-r":
    is_filter_enabled = True
    filter_arg1 = sys.argv[3]
    filter_arg2 = sys.argv[4]

# Read commands from the specified file
command_list = []
output_results = []

with open(input_file, 'r') as cmd_file:
    command_list = cmd_file.readlines()

# Function to execute commands
def run_command(command):
    process_result = sp.run(["sudo", "python3", "./vol.py", "-f", "./wcry.raw", command], text=True, stdout=sp.PIPE, stderr=sp.PIPE)
    
    # Process output based on filter condition
    if is_filter_enabled:
        filtered_output = [
            line for line in process_result.stdout.splitlines()
            if filter_arg1 in line and filter_arg2 in line
        ]
        output_results.extend(filtered_output)
    else:
        output_results.append(process_result.stdout)

# Execute each command from the list
for cmd in command_list:
    run_command(cmd.strip())

# Write results to a log file
with open("./asg11_output.log", 'w+') as log_file:
    log_file.writelines(f"{output}\n" for output in output_results)

print("Log file created !!")

