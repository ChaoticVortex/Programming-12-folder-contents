import math
from collections import deque


def checkprime(num):
	#no need to check 2 because those are already filtered
	for n in range(3, int(math.sqrt(num))+1):
		if num % n == 0:
			return False
	return True

circprimes = [2,3,5,7,11,13,17,31,37,71,73,79,97]
notallowed = set(['2','4','5','6,','8,','0'])
n = 96

while n < 1000000:
	if n % 10000 == 0:
		print n
	n += 6
	num = n -1
	
	for digit in str(num):
		if digit in notallowed:
			continue

	if num in circprimes:
		continue
	
	d= deque(str(num))
	circ = True
	possible = []
	for i in range(len(str(num))):
		test = ''
		for elem in d:
			test += elem
		if checkprime(int(test)) == False:
			circ = False
			break
		else:
			possible.append(int(test))
	
	if circ == True:
		circprimes = circprimes + possible
	
	
	
			
	
n = 96
while n < 1000000:
	if n % 10000 == 0:
		print n
	n += 6	
	num = n +1
	for digit in str(num):
		if digit in notallowed:
			continue

	if num in circprimes:
		continue
	
	d= deque(str(num))
	circ = True
	possible = []
	for i in range(len(str(num))):
		test = ''
		for elem in d:
			test += elem
		if checkprime(int(test)) == False:
			circ = False
			break
		else:
			possible.append(int(test))
	
	if circ == True:
		circprimes = circprimes + possible

print len(circprimes)
print len(set(circprimes))
			


