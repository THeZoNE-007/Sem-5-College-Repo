import os
import sys
import subprocess as sp

file_names=os.listdir(sys.argv[1])

fileName=[]

for file in file_names:
    if os.path.isfile(os.path.join(sys.argv[1],file)):
        fileName.append(file)

if not fileName:
    print("The provided directory is empty or contains no files.")
    sys.exit()

def createDD():
    for i in range(0,len(fileName)):
       generate=sp.run(["dd",f"if={sys.argv[1]}/{fileName[i]}",f"of=./{fileName[i]}.dd"],stdout=sp.PIPE,stderr=sp.PIPE,text=True)
    print("Image files created in the directory!!")
    
createDD()
