import sys
from collections import deque

def getClose(N, M, x, y, area):
	dirs = [[0,-1],[-1,-1],[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1]]
	
	visit = [[False]*M for _ in range(N)]
	visit[x][y] = True
	
	dist, q = 0, deque([[x,y,0]])
	while q:
		i, j, d = q.popleft()
		
		if area[i][j]:
			dist = d
			break
		
		for di, dj in dirs:
			di += i
			dj += j
			if 0 <= di < N and 0 <= dj < M and not visit[di][dj]:
				visit[di][dj] = True
				q.append([di,dj,d+1])
				
	return dist

N, M = list(map(int,sys.stdin.readline().split()))

area = []
for _ in range(N):
	area.append(list(map(int,sys.stdin.readline().split())))

safe_dist = 0
for i in range(N):
	for j in range(M):
		safe_dist = max(safe_dist,getClose(N,M,i,j,area))
		
print(safe_dist)
