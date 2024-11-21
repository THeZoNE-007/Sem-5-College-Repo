import argparse
import os
import subprocess
import threading
import time

""" Work done with argparse module to create the cmd line arguments """

parser = argparse.ArgumentParser(description = "Command rules Checker Q1")

parser.add_argument("input_dir", type=str, help= "Enter input directory path")
parser.add_argument("output_dir", type=str, help= "Enter output directory path")
parser.add_argument("file_type", type=str, help= "Enter the extension of file you want specifically")

args = parser.parse_args()

"""END OF Q1"""


""" Work done with os module - took the file names from input given directories and extracted their names, put them into an array"""

threadArray = [] #
file_name = []
file_path = os.listdir(args.input_dir)
for file in file_path:
	if os.path.isfile( os.path.join(args.input_directory, file )):
		file_name.append(file)

"""END OF Q2"""


""" Work done with subprocess module - to do the foremost on the extracted names in the array previously done """

def FM(args.input_dir, args.output_dir, ImgFile, args.file_type, newDir):

"""Note : In the above function, the foremost argumment will automatically create a directory named - newDir"""
	
	result = subprocess.run(["sudo","foremost","-i", f"{args.input_dir}/{ImgFile}", "-o", f"{args.output_dir}/{newDir}", "-T", f"{file_type}"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

for i in range(1,len(file_name)+1):
	#Foremost(args.input_dir, args.output_dir, file, args.file_type, f"recovery{i}")
	

	thread=threading.Thread(target=FM, args=(args.input_dir, args.output_dir, file, args.file_type, f"recovery{i}"))
	threadaArray.append(thread)

for thread in threadArray:
	thread.start()
	thread.join()
	print("Thread finished, main thread ends.")





	
