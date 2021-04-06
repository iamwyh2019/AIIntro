import math
import random

n = 0
pts = []

def dis(x,y):
	global n,pts
	total = 0
	for x0,y0 in pts:
		total += math.sqrt((x-x0)**2 + (y-y0)**2)
	return total

def gradient(x,y):
	global n,pts
	gx,gy = 0,0
	for x0,y0 in pts:
		dist = math.sqrt((x-x0)**2 + (y-y0)**2)
		if abs(dist) < 1e-6:
			continue
		gx += (x-x0) / dist
		gy += (y-y0) / dist
	return gx,gy

def main():
	global n,pts
	n = int(input())
	x,y = 0,0
	for i in range(n):
		px,py = map(int,input().split())
		x += px
		y += py
		pts.append((px,py))
	
	x /= n
	y /= n
	ans = 1e7
	rate = 100
	for t in range(10000):
		nans = dis(x,y)
		ans = min(ans, nans)
		gx,gy = gradient(x,y)
		x -= gx * rate
		y -= gy * rate
		#if rate > 0.01:
		#	rate *= 0.99
		rate *= 0.99
	
	print(round(ans))

if __name__ == "__main__":
	main()