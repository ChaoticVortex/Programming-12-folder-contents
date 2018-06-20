s = 0
for x in range(1,5):
	for y in range(1,x+1):
		if x % y == 0:
			s += 1
print s
