import sys
import heapq
from math import sqrt

def getDist(star1, star2):
	x1, y1 = star1
	x2, y2 = star2
	return round(sqrt((x2-x1)**2+(y2-y1)**2),2)

def Find(x, parent):
	while x != parent[x]:
		x = parent[x]
	return x

n = int(sys.stdin.readline())

star = []
for _ in range(n):
	x, y = list(map(float,sys.stdin.readline().split()))
	star.append([x,y])

dist = []
for i in range(n):
	for j in range(i+1,n):
		heapq.heappush(dist,[getDist(star[i],star[j]), i, j])

cost = 0
parent = [i for i in range(n)]
while dist:
	d, s1, s2 = heapq.heappop(dist)
	
	ps1, ps2 = Find(s1, parent), Find(s2, parent)
	if ps1 != ps2:
		cost += d
		parent[ps2] = ps1
		
print(cost)
