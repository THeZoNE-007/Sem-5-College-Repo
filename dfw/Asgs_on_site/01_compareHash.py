import sys
import subprocess

def hashFile(path):
	result = subprocess.run([sys.argv[1],path], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	return result
	
def findHash (path1, path2):
	result1 = hashFile(path1)
	result2 = hashFile(path2)
	
	if result1 == result2:
		print("Same Hash")
	else:
		print("Different Hash")

path1 = sys.argv[2]
path2 = sys.argv[3]

findHash(path1, path2)
