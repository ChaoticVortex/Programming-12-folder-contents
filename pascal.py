def fact(n):
	if n == 0 or n == 1:
		return 1
	return n * fact(n-1)


def get_row(n):
	n-= 1
	row = []
	for num in range(n+1):
		row.append(fact(n) / (fact(n - num) * fact(num)))
	return row
	
y = 200
for x in range(1,y):
	esum = 0.0
	osum = 0.0
	row = get_row(x)
	for num in row:
		if num % 2 == 0:
			esum += num
		else:
			osum += num
	ratio = 0.0
	if esum > 0.0:
		ratio = osum / esum
	print ratio
	
