import subprocess as sp
import sys

# Initialize file location
input_file = sys.argv[1]

# Read commands from the specified file
command_list = []
output_results = []

with open(input_file, 'r') as cmd_file:
    command_list = cmd_file.readlines()

# Function to execute commands
def run_command(command):
    process_result = sp.run(["sudo", "python3", "./vol.py", "-f", "./0zapftis.vmem", command], text=True, stdout=sp.PIPE, stderr=sp.PIPE)
    output_results.append(process_result.stdout)

# Execute each command from the list
for cmd in command_list:
    run_command(cmd.strip())

# Write results to a log file
with open("./asg14_output.log", 'w+') as log_file:
    log_file.writelines(f"{output}\n" for output in output_results)

print("Log file created !!")
