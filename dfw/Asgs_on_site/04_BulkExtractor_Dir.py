import sys
import os
import subprocess


ip = sys.argv[1]
op = sys.argv[2]
thread = sys.argv[3]


file_name = []
file_path = os.listdir(ip)
for file in file_path:
	if os.path.isfile( os.path.join(ip, file )):
		file_name.append(file)

def BulkExtractor(img, directory):
	result = subprocess.run(["sudo","bulk_extractor","-o", f"{op}/{directory}", "-j", f"{thread}",f"{ip}/{img}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

for i in range(0,len(file_name)):
	BulkExtractor(file_name[i], f"bulkResult{i+1}")
	





	
