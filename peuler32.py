#check 1 * 4 = 4
#check 2 * 3 = 4

pandigital = []
nums = set(["1","2","3","4","5","6","7","8","9"])


def check(num, used):
	for let in str(num):
		if let in used:
			return False
		elif let == '0':
			return False
		else:
			used.append(let)
	return used

for n in range(1,10):
	for y in range(1000,10000):
		used = [str(n)]

		tmp = check(y, used)
		if tmp == False:
			continue
		else:
			used = tmp
				
		product = n * y
		if product > 9999:
			break
		
		tmp = check(product, used)
		if tmp == False:
			continue
		else:
			if set(tmp) == nums:
				pandigital.append((n,y, product))



for n in range(10,100):
	if str(n)[0] == str(n)[1]:
		continue

	for y in range(100,1000):
		used = [str(n)[0], str(n)[1]]

		tmp = check(y, used)
		if tmp == False:
			continue
		else:
			used = tmp
				
		product = n * y
		if product > 9999:
			break
		
		tmp = check(product, used)
		if tmp == False:
			continue
		else:
			if set(tmp) == nums:
				pandigital.append((n,y, product))
		
print pandigital
products = []

s = 0
for tup in pandigital:
	products.append(tup[2])

print set(products)
for num in set(products):
	s += num

print s
