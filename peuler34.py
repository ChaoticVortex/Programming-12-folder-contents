def fact(n):
	if n < 2:
		return 1
	else:
		return n * fact(n-1)

cache = {}
for x in range(0,10):
	cache[str(x)] = fact(x)


nums = []
for n in xrange(3, fact(9) * 7):
	s = 0
	for let in str(n):
		s += cache[let]
	
	if s == n:
		nums.append(n)

print sum(nums)
