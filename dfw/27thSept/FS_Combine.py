import sys
import os
import subprocess

def Foremost():
	res = subprocess.run(["sudo","foremost","-i",f"{ip}","-o",f"{op}","-c",f"{conf}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)


def Scalpel():
	res = subprocess.run(["sudo","scalpel","-i",f"{ip}","-o",f"{op}","-c",f"{conf}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

tool = sys.argv[1]
ip = sys.argv[2]
op = sys.argv[3]
conf = sys.argv[4]

if tool == "foremost":
	Foremost()
elif tool == "scalpel":
	Scalpel()
else:
	print("Enter valid tool name - either foremost or scaple")
