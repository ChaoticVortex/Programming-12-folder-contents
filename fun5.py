s = 0
a = 5.5
for x in range(2 * int(a)):
	if x % 2 == 0:
		continue
	s += x
	print s,
