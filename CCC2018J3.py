import sys
for line in sys.stdin:
	nums = line.split()
for x in range(len(nums)):
	nums[x] = int(nums[x])

distances = []


def shortest(i,k):
	if i == k:
		return 0
	return nums[k-1] + shortest(i, k-1)

for i in range(5):
	l = []
	for k in range(5):
		l.append(999)
	distances.append(l)

for i in range(5):
	for k in range(i,5):
		if i == k:
			distances[i][k] = 0
		else:
			distances[i][k] = shortest(i,k)

for i in range(5):
	for k in range(5):
		if distances[i][k] == 999:
			distances[i][k] = distances[k][i]

for line in distances:
	for num in line:
		print num,
	print
