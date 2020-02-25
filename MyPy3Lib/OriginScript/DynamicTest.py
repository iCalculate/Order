#  RamdomPointImport  #
#coding=utf-8
import numpy as np
import random

Disp = 0.1
Den = 10
location = [[x for x in range(10)]for x in range(2)]
location = np.transpose(location)
Ex_local = []
Dist = 10 * Disp

for i in range(len(location)):
	if location[i][0] == None:
		continue
	for k in range(1,Den):
			Ex_local.extend([[location[i][0]+random.uniform(-Dist,Dist), \
							location[i][1]+random.uniform(-Dist,Dist)]])

location = np.array(location)
Ex_local = np.array(Ex_local)
Ex_local = np.transpose(Ex_local)

print(Ex_local)
