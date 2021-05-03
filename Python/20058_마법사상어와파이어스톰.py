import sys
from collections import deque
sys.setrecursionlimit(100000)

def checkIce(N, ice):
	new_ice = [[0]*N for _ in range(N)]
	
	c_dir = [[-1,0],[1,0],[0,-1],[0,1]]
	for x in range(N):
		for y in range(N):
			check = 0
			for dx, dy in c_dir:
				dx += x
				dy += y
				if 0 <= dx < N and 0 <= dy < N and ice[dx][dy] > 0:
					check += 1
			
			new_ice[x][y] = ice[x][y]
			if check < 3 and new_ice[x][y] > 0:
				new_ice[x][y] -= 1
			
	return new_ice
	
def rotate(N, m, ice):
	tmp_ice = [[ice[i][j] for j in range(N)] for i in range(N)]
	for sx in range(0,N,m):
		for sy in range(0,N,m):
			for i in range(m):
				for j in range(m):
					ice[sx+j][sy+(m-1-i)] = tmp_ice[sx+i][sy+j]
	return checkIce(N,ice)
 
N, Q = list(map(int,sys.stdin.readline().split()))
N = 2**N

ice = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
magic = list(map(int,sys.stdin.readline().split()))
for m in magic:
	m = 2**m
	ice = rotate(N,m,ice)
	
ice_size, total_ice = 0, 0
c_dir = [[-1,0],[1,0],[0,-1],[0,1]]
for i in range(N):
	for j in range(N):
		if not ice[i][j]:
			continue
		
		s = 1
		total_ice += ice[i][j]
		
		ice[i][j] = 0
		q = deque([[i,j]])
		while q:
			x, y = q.popleft()
			
			for dx, dy in c_dir:
				dx += x
				dy += y
				if 0 <= dx < N and 0 <= dy < N and ice[dx][dy]:
					s += 1
					total_ice += ice[dx][dy]
					
					q.append([dx,dy])
					ice[dx][dy] = 0
			
		ice_size = max(s, ice_size)
			
print(total_ice)
print(ice_size)
