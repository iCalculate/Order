import pyautogui
import os
import sys
from ctypes import *
import numpy as np

def get_color(x, y):
	gdi32 = windll.gdi32
	user32 = windll.user32
	hdc = user32.GetDC(None)  # 获取颜色值
	pixel = gdi32.GetPixel(hdc, x, y)  # 提取RGB值
	r = pixel & 0x0000ff
	g = (pixel & 0x00ff00) >> 8
	b = pixel >> 16
	return [[r, g, b]]

Position = [[20,20]]
matrix = [Position] * 1
try:
	while True:
		##print(x,y)
		Key = input("Enter your input: ")
		if (Key == "Add"):
			print("in the if")
			x, y = pyautogui.position()
			New_Postion = [[x,y]]
			Position.extend(New_Postion)
			print("New = " + str(New_Postion))
			print("Tot = " + str(Position))
		elif (Key == "Exit"):
			ColorList = get_color(Position[0][0],Position[0][1])
			for i in range(len(Position)-1) :
				New_ColorList = get_color(Position[i+1][0],Position[i+1][1])
				ColorList.extend(New_ColorList)
			break
except KeyboardInterrupt:
	print('\nExit.')

print("Color = " + str(ColorList) )