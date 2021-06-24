import sys
import heapq

V, E = list(map(int,sys.stdin.readline().split()))

visit = [[float('inf'),False] for _ in range(V)]
edge = {}
for _ in range(E):
	a, b, w = list(map(int,sys.stdin.readline().split()))
	
	if a-1 not in edge.keys():
		edge[a-1] = {}
	if b-1 not in edge.keys():
		edge[b-1] = {}
	
	if b-1 not in edge[a-1].keys():
		edge[a-1][b-1] = float('inf')
	if a-1 not in edge[b-1].keys():
		edge[b-1][a-1] = float('inf')
		
	edge[a-1][b-1] = edge[b-1][a-1] = min(edge[a-1][b-1], w)

pq = []
heapq.heappush(pq, [0,0])

weight = 0
while pq:
	w, n = heapq.heappop(pq)
	
	if visit[n][1]:
		continue
	visit[n][1] = True
	
	weight += w
	for k, v in edge[n].items():
		if visit[k][1]:
			continue
		heapq.heappush(pq, [v,k])
		
print(weight)
