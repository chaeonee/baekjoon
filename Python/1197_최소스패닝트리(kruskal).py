import sys
import heapq

def Find(x, parent):
	while x != parent[x]:
		x = parent[x]
	return x

V, E = list(map(int,sys.stdin.readline().split()))

edge = []
for _ in range(E):
	a, b, w = list(map(int,sys.stdin.readline().split()))
	heapq.heappush(edge,[w,a-1,b-1])

weight = 0
parent = [i for i in range(V)]
while edge:
	w, a, b = heapq.heappop(edge)
	
	pa = Find(a,parent)
	pb = Find(b,parent)
	if pa != pb: # Union
		weight += w
		if pb <= pa:
			parent[pa] = pb
		else:
			parent[pb] = pa

print(weight)
