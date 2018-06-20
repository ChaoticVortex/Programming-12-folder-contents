'''
def insort(l):
	#sort using 2 lists
	sort = [l.pop()]
	index = 1
	while len(l) > 0:
		x = l.pop()
		for num in range(len(sort)-1, -1, -1):
			if x > sort[num]:
				sort.insert(num + 1, x)
				break
			elif num == 0:
				sort.insert(0,x)
	return sort
'''
def insort(l):
	#stable in-place sort
	index = 1
	while len(l) - index > 0:
		x = l.pop()
		for num in range(index -1, -1, -1):
			if x > l[num]:
				l.insert(num + 1, x)
				break
			elif num == 0:
				l.insert(0,x)
		index += 1
	return l
	

def quicksort(l):
	if len(l) == 1:
		return l
	if len(l) == 2:
		return [min(l), max(l)]
	pivots = [0, len(l)//2, -1]
	
	
	
	
	return quicksort(l[:pivot]) + pivot + quicksort(l[pivot +  1:])


l = [5,7,6,9,27,4,16,1,2]
print insort(l)
print quicksort(x)
