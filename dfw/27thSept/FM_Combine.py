import sys
import os
import subprocess

def Foremost():
	res = subprocess.run(["sudo","foremost","-i",f"{ip}","-o",f"{op}","-c",f"{conf}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

def MagicRescue():
	res = subprocess.run(["sudo","magicrescue","-r",f"{recipe}","-d",f"{ip}",f"{op}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

tool = sys.argv[1]
recipe = sys.argv[2]
ip = sys.argv[3]
op = sys.argv[4]
conf = sys.argv[5]

if tool == "foremost":
	Foremost()
elif tool == "scalpel":
	MagicRescue()
else:
	print("Enter valid tool name - either foremost or magicrescue")
