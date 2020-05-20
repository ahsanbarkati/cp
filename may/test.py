import numpy as np
import os

t = 10
s = str(t) + '\n'
for tt in range(t):
	n = np.random.randint(1,10)
	m = np.random.randint(0,n+1)
	if(n == 1):
		m = 0
	s+=str(n) + '\n'
	s+= str(m) + '\n'
	mm = []
	p = np.random.permutation(n) + 1
	for i in p:
	    s+= str(i) + ' '
	s+= '\n'
	print("generating m")
	for i in range(m):
		x = np.random.randint(1,n+1)
		y = np.random.randint(1,n+1)
		while(y == x):
			y = np.random.randint(1,n+1)
		mm.append([x,y])
		s+= str(x) + ' ' + str(y) + '\n'
f = open('input','w+')
f.write(s)
f.close()

#print("executin")
os.system('./a.out < input > out')
f1 = open('out')

os.system('./nam < input > outnam')

f2 = open('./outnam')

#print(s)
o1 = f1.read()
o2 = f2.read()
#print(o1)
#print(o2)
if(o1 != o2):
	print(s)
	print(o1)
	print(o2)
	print("not equal")
