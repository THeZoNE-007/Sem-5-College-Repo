import sys

def extract_pids_from_file(filename, column_no):
    pids = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                columns = line.split()
                if len(columns) >= column_no + 1:
                    pid = columns[column_no]
                    pids.append(pid)
    except FileNotFoundError:
        print(f"Error: The file {filename} was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")
    return pids

def compare_processes(pslist_file, psxview_file):
    pslist_pids = extract_pids_from_file(pslist_file, 0)
    psxview_pids = extract_pids_from_file(psxview_file, 2)
    hidden_processes = []
    
    for pid in psxview_pids:
        if pid not in pslist_pids:
            try:
                if isinstance(int(pid),int):
                    hidden_processes.append(pid)
            except ValueError:
                continue
    
    return hidden_processes

if __name__ == "__main__":

    pslist_output = sys.argv[1]
    psxview_output = sys.argv[2]
    
    hidden_processes = compare_processes(pslist_output, psxview_output)

    if hidden_processes:
        for pid in hidden_processes:
            print(f"PID: {pid}")
    else:
        print("No PIDs found in psxview that are not present in pslist.")

