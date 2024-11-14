import subprocess as sp
import sys
filterCondition=False
fileloc=sys.argv[1]
if len(sys.argv)>=3:
    if sys.argv[2]=="-r" and sys.argv[3]:
        filterCondition=True
commands=[]
results=[]
with open(fileloc,'r') as file:
    commands=file.readlines()
    file.close()
def executeCommands(commandName):
    res=sp.run(["sudo","python3","./vol.py","-f","./wcry.raw",f"{commandName}"],text=True,stdout=sp.PIPE,stderr=sp.PIPE)
    if filterCondition:
        output_lines=res.stdout.splitlines()
        filtered_lines = [line for line in output_lines if sys.argv[3] in line and sys.argv[4] in line]
        for lines in filtered_lines:
            results.append(lines)
    else:
        results.append(res.stdout)
for cmds in commands:
    executeCommands(cmds.split("\n")[0])
with open("./asg11_output.log",'w+') as file:
    for outputs in results:
        file.writelines(f"{outputs}\n")
    print("Log file generated in the current directory")
    file.close()
