import sys
import subprocess as sp

def hashFile(path):
	result = sp.run(["md5sum",path], stdout=sp.PIPE, stderr=sp.PIPE, text=True)
	return result.stdout.split()[0]

def FindHash (path1,path2):
	result1 = hashFile(path1)
	result2 = hashFile(path2)
	
	if result1 == result2:
		print("Same")
	else:
		print("Different")
		
path1 = input("Enter path 1: ")
path2 = input("Enter path 2: ")

FindHash(path1,path2)
