import sys
lines = []
for line in sys.stdin:
	lines.append(line[:-1])
n = int(lines.pop(0))


def checkline(line): #checks if the line is fine, False if not, True if it is
	for num in range(len(line)-1):
		if line[num] > line[num + 1]:
			return False
	return True

def checkflowers(line1, line2): #checks if line is fine, False if not, True if is
	for num in range(len(lines[0])):
		if line1[num] > line2[num]:
			return False
	return True
			
def rotate(matrix):
	rotated = []
	
	for i in range(len(matrix)):
		l = []
		for k in range(len(matrix)):
			num = matrix[(n-1)-k][i]
			l.append(num)
		rotated.append(l)
	return rotated


for num in range(len(lines)):
	lines[num] = lines[num].split()
	for x in range(len(lines[num])):
		lines[num][x] = int(lines[num][x])


while True:
	changed = False
	for num in range(n):
		if checkline(lines[num]) == False:
			lines = rotate(lines)
			changed = True
			break
	if changed == True:
		continue
	for ind1 in range(n):
		for ind2 in range(ind1 + 1, n):
			if checkflowers(lines[ind1], lines[ind2]) == False:
				lines = rotate(lines)
				changed = True
				break
	if changed == False:
		break

for line in lines:
	for num in line:
		print num,
	print

