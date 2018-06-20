primes = [2]
checking = 3
for x in range(int(raw_input())):

	m, n = raw_input().split()
	m = int(m)
	n = int(n)
	while checking <= n:
		prime = True
		for num in primes:
			if checking % num == 0:
				prime = False
		if prime == True:
			primes.append(checking)
		checking += 1
	
'''
index = 0
while primes[index] < m:
	index += 1

while primes[index] <= n:
	print primes[index]
	index += 1
'''
