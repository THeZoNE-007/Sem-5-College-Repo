import os
import sys
import subprocess as sp

file_names=os.listdir(sys.argv[1])
op_name=os.listdir(sys.argv[2])
mode=input(sys.argv[3])
compress=input(sys.argv[4])


fileName=[]

for file in file_names:
    if os.path.isfile(os.path.join(sys.argv[1],file)):
        
        fileName.append(file)
    else:
    	print("File not present in the provided directory")


if mode == "dd":
	createDD()
elif mode == "dc3dd":
	createDC3DD()
else:
	print("Please enter an image file name")


def zip():
	for file in range(0,len(fileName)):
		result=sp.run["gzip","k",f"{sys.argv[1]}/{fileName[file]}"], stdout=sp.PIPE, stderr=sp.PIPE

if compress == "gzip":
	zip()
elif compress == "":
	continue
	


def createDD():
    for i in range(0,len(fileName)):
       generate=sp.run(["dd",f"if={sys.argv[1]}/{fileName[i]}",f"of=./{fileName[i]}.dd"],stdout=sp.PIPE,stderr=sp.PIPE,text=True)
    print("Image files created in the directory!!")
    
def createDC3DD():
    for i in range(0,len(fileName)):
       generate=sp.run(["dc3dd",f"if={sys.argv[1]}/{fileName[i]}",f"of=./{fileName[i]}.dd"],stdout=sp.PIPE,stderr=sp.PIPE,text=True)
    print("Image files created in the directory!!")
    
createDD()

# To be continued...
