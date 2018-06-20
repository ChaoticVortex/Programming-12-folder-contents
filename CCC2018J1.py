import sys
l = []
answer = False
'''
for line in sys.stdin:
	print line[:-1]
	l.append(line[:-1])
'''
for x in range(4):
	l.append(int(raw_input()))

if l[0] == 8 or l[0] == 9:
	if l[3] == 8 or l[3] == 9:
		if l[1] == l[2]:
			answer = True

if answer == True:
	print 'ignore'
else:
	print 'answer'
