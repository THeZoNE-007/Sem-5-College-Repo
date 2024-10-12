import sys
import subprocess as sp

path1 = sys.argv[1]
path2 = sys.argv[2]
mode = sys.argv[3]

result1 = sp.run([mode, path1], stdout = sp.PIPE, stderr = sp.PIPE, text = True)
result2 = sp.run([mode, path2], stdout = sp.PIPE, stderr = sp.PIPE, text = True)

hash1 = result1.stdout.split()[0]
hash2 = result2.stdout.split()[0]

print(hash1)
print(hash2)

if hash1 == hash2:
	print("Same Hash")
else:
	print("Different Hash")
