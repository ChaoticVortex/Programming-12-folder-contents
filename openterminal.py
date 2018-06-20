import threading
import time
import os

os.system("gnome-terminal python openterminal.py")
class myThread (threading.Thread):
	def __init__(self):
		threading.Thread.__init__(self)

	def run(self):
		time.sleep(1)
		os.system("gnome-terminal python openterminal.py")

threadlist = []
while True:
	threadlist.append(myThread())
	threadlist[-1].start()
	threadlist[-1].run()
thread1 = myThread()
thread2 = myThread()

#thread1.start()
#thread2.start()


"""
import os
import time
import thread
import threading
#os.system("gnome-terminal python openterminal.py")

class mythread(threading.Thread):
	def __init__(self, command):
		thread.__init__("name")
		self.command = command
	def woohoo(command):
		os.system(self.command)

thread1 = mythread("gnome-terminal")
thread1.start()
thread1.woohoo()

thread.start_new_thread(woohoo,("gnome-terminal",))# python openterminal",))
print "fuck"
#
"""
