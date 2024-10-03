import sys
import os
import subprocess

def Foremost():
	res = subprocess.run(["sudo","foremost","-i",f"{sys.argv[2]}","-o",f"{sys.argv[3]}","-c",f"{sys.argv[4]}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

def Scalpel():
	res = subprocess.run(["sudo","scalpel","-i",f"{sys.argv[2]}","-o",f"{sys.argv[3]}","-c",f"{sys.argv[4]}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

if sys.argv[1] == "foremost":
	Foremost()
elif sys.argv[1] == "scalpel":
	Scalpel()
else:
	print("Enter valid tool name - either foremost or scalpel")
