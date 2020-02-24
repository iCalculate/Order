#!/etc/bin/python
#coding=utf-8
import numpy as np
import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from PIL import Image

def on_press(event):
    print(event.xdata, event.ydata)
    plt.scatter(event.xdata, event.ydata,s=30)
    fig.canvas.draw()
    location.extend([[event.xdata, event.ydata]])

Disp = 0.1

Den = 10
location = []
Ex_local = []
fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1)
img = Image.open('0.jpg')
plt.imshow(img, animated= True)


Dist = img.size[0] * Disp
fig.canvas.mpl_connect('button_press_event', on_press)
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


filename = 'write_data.txt'
with open(filename,'w') as f:
	for j in range(len(Ex_local)) :
		f.write(str(Ex_local[j][0])+" "+ \
				str(Ex_local[j][1])+"\n")
