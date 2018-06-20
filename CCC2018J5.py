import sys

class Page(object):
	
	def __init__(self, number):
		self.number = number
		self.parents = []
		self.children = []
		self.end = False
		self.checked = False
		self.rooted = False
		self.dist = -99
	
	def root(self):
		self.checked = True
		self.rooted = True
		for child in self.children:
			if pages[child].checked == False:
				pages[child].root()
		


	def make_distances(self):
		if self.number == 1:
			self.dist = 1
			
		for child in self.children:
			if pages[child].dist == -99 or pages[child].dist > self.dist + 1:
				pages[child].dist = self.dist + 1
				pages[child].make_distances()
		


distcache = {}

lines = []
for line in sys.stdin:
	lines.append(line[:-1].split())
num = int(lines[0][0])

for line in lines:
	for x in range(len(line)):
		line[x] = int(line[x])

pages = [Page(0)]
pages[0].checked = True
pages[0].rooted = True
for linenum in range(1, num + 1):
	pages.append(Page(linenum))

for linenum in range(1,len(lines)):
	if lines[linenum][0] == 0:
		pages[linenum].end = True
	for x in range(lines[linenum][0]):
		childindex = lines[linenum][x+1]
		pages[linenum].children.append(childindex)
		pages[childindex].parents.append(linenum)

pages[1].root()
pages[1].make_distances()

root = True
pagedistances = []

for page in pages:
	if page.end == True:
		if page.rooted == True:
			pagedistances.append(page.dist)

'''
for page in pages:
	if page.number != 0:
		print "number: ", page.number
		print "parents: ", page.parents
		print "children: ",page.children
		print "end: ",page.end
		print "rooted: ",page.rooted
		print "dist: ",page.dist
		print
		print
		
'''

for page in pages:
	if page.rooted == False:
		root = False
if root == True:
	print 'Y'
else:
	print 'N'
print int(min(pagedistances))


