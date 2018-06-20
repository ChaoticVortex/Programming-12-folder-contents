import sys
lines = []
for line in sys.stdin:
	lines.append(line[:-1])
	
count = 0

for x in range(int(lines[0])):
	if lines[1][x] == lines[2][x]:
		if lines[1][x] == 'C':
			count +=1

print count
