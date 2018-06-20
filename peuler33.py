def reduced(frac):
	num = frac[0]
	denom = frac[1]
	div = 2
	while div <= num:
		if num % div == 0 and denom % div == 0:
			num = num / div
			denom = denom / div
		else:
			div += 1
	return (num, denom)


fracs = []

for num in range(10,100):
	for denom in range(num + 1, 100):
		
		if num % 10 == 0 and denom % 10 == 0:
			continue

		n = str(num)
		d = str(denom)
		
		if n[0] not in d and n[1] not in d:
			continue

		if n[0] in d:
			if d[0] == d[1]:
				d = d[0]
			else:
				d = d.replace(n[0],"")
			d = int(d)
			n = int(n[1])
		
		elif n[1] in d:
			if d[0] == d[1]:
				d = d[0]
			else:
				d = d.replace(n[1],"")
			d = int(d)
			n = int(n[0])
		
		
		if reduced((num,denom)) == reduced((n,d)):
			fracs.append(reduced((num,denom)))

print fracs
num = 1
denom = 1
for frac in fracs:
	num *= frac[0]
	denom *= frac[1]

print
print denom / num
