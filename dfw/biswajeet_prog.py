import os
import sys
import subprocess as sp

print("--------------------------------------------------------------------------------------")
print("|     RUN THIS PROGRAM FROM THE DIRECTORY WHOSE FILE/IMAGES YOU WANT TO CREATE       |")
print("--------------------------------------------------------------------------------------")


def FetchData():
    file_names=os.listdir("./")
    fileName=[]
    onlyName=[]
    
    for file in file_names:
        if os.path.isfile(os.path.join("./", file)):
            fileName.append(file)
            dotPosn = file.rfind(".")
            if dotPosn != -1:
                onlyName.append(file[:dotPosn])
            else:
                onlyName.append(file)  
        else:
            print(f"{file} is not a file in the directory.")    
    Menu(fileName,onlyName)
        
def Menu(fileName,onlyName):
   print("-----------------------PLEASE SELECT------------------------------------")
   print("1-CREATE IMAGE USING DC3DD\n2-CREATE IMAGE USING DD\n3-GZIP A IMAGE/FILE")
   print("------------------------------------------------------------------------")
   print()
   ch=int(input("Enter your choice: "))
   
   if ch==1:
       createImage("dc3dd",fileName,onlyName)
   elif ch==2:
       createImage("dd",fileName,onlyName)
   elif ch==3:
       createZip(fileName)     
   else:
       print("Invalid choice!!")       


		
def createImage(Method,fileName,onlyName):
    print()
    print("FILES PRESENT IN THE CURRENT DIRECTORY")
    print()
    for i in range(0,len(fileName)):
        print(f"{i+1}--{fileName[i]}")
    ch=int(input(f"Enter the file you want to create a image using {Method}: "))
    ch=ch-1

    print("- - - - - - - - - - - - - -  Creating Images- - - - - - - - - - - - - - - - -")
    generate=sp.run([Method,f"if=./{fileName[ch]}",f"of=./{onlyName[ch]}.dd"],stdout=sp.PIPE,stderr=sp.PIPE)
        
    print()
    print(f"Images have been created using {Method}")
    print()
    print("- - - - - - - - - - - - - - -Terminating Process - - - - - - - - - - - - - - - ")
    print()



def createZip(fileName):
    print()
    print("FILES PRESENT IN THE CURRENT DIRECTORY")
    print()
    for i in range(0,len(fileName)):
        print(f"{i+1}--{fileName[i]}")
    ch=int(input(f"Enter the file you want to create a zip using GZIP: "))
    ch=ch-1
    print("- - - - - - - - - - - - - - - - Zipping Files - - - - - - - - - - - - - - - - - -")
   
    result=sp.run(["gzip","-k",f"./{fileName[ch]}"],stdout=sp.PIPE,stderr=sp.PIPE)
    print()
    print(f"{fileName[ch]} have been zipped using GZIP")
    print()
    print("- - - - - - - - - - - - - - -Terminating Process - - - - - - - - - - - - - - - ")
    print()

if __name__=="__main__":
    ansr="y"
    while ansr=="y":
        FetchData()
        ansr=input("DO YOU WANT TO CONTINUE [y/n]: ")
        
        
