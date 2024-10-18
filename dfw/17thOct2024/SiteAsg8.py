import sys
import subprocess as sp
#Funtion to read nth column separated by given separator

def read_nth_column(file_path, n, separator):
	column_data = []
	with open(file_path, 'r') as file:
		for line in file:
# Split the line into columns based on the specified separator
			columns = line.split(separator)
			if len(columns) > n: # Check if the nth column exists
				column_data.append(columns[n])
	return column_data


file_path = sys.argv[1]
n = 2
separator = '|'

result = read_nth_column(file_path, n, separator)
print(result)

"""
# Find unique entries of given array

def find_unique_entries(array):
	return list(set(array))

#Merging the two arrays

merged_array = [f"{a}-{b}" for a, b in zip(array1, array2)]

# filter string

s = "ab-qweqw"
pattern = "-"
result1 = s.split(pattern)[0]
result2 = s[3:]
# result1: "ab" result2: "qweqw"
"""

