#  RamdomPointImport  #
#coding=utf-8
import numpy as np
import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation


Disp = 0.1
Den = 10
x=range(1,10)
y=[2*v for v in x]
location = []
Ex_local = []

plt.plot(x, y)
location=plt.ginput(20)
Dist = len(x) * Disp
plt.show()

for i in range(len(location)):
	if location[i][0] == None:
		continue
	for k in range(1,Den):
			Ex_local.extend([[location[i][0]+random.uniform(-Dist,Dist), \
							location[i][1]+random.uniform(-Dist,Dist)]])

location = np.array(location)
Ex_local = np.array(Ex_local)

Out = plt.figure()
plt.scatter(location[:,0],location[:,1],s=30)
plt.scatter(Ex_local[:,0],Ex_local[:,1],s=10)
plt.show()
