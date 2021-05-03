import sys
from collections import deque

def move(N, sea):
	move_dir = [[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1],[0,-1],[-1,-1]]
	
	move_sea = [[deque() for _ in range(N)] for _ in range(N)]
	for i in range(N):
		for j in range(N):
			if sea[i][j]:
				while sea[i][j]:
					x, y = i, j
					m, s, d = sea[i][j].popleft()
					x += move_dir[d][0]*s + N
					y += move_dir[d][1]*s + N
					x %= N
					y %= N
					
					move_sea[x][y].append([m,s,d])
					
	
	return move_sea
	
def calFireBall(N, sea):
	for i in range(N):
		for j in range(N):
			if len(sea[i][j]) > 1:
				cnt, weight, speed, n_odd, n_even = 0, 0, 0, 0, 0
				while sea[i][j]:
					m, s, d = sea[i][j].popleft()
					
					cnt += 1
					weight += m
					speed += s
					if d%2:
						n_odd += 1
					else:
						n_even += 1
				
				weight //= 5
				speed //= cnt
				if weight > 0:
					if n_odd == 0 or n_even == 0:
						for k in [0,2,4,6]:
							sea[i][j].append([weight,speed,k])
					else:
						for k in [1,3,5,7]:
							sea[i][j].append([weight,speed,k])
						
	return sea

N, M, K = list(map(int,sys.stdin.readline().split()))

sea = [[deque() for _ in range(N)] for _ in range(N)]
for _ in range(M):
	r, c, m, s, d = list(map(int,sys.stdin.readline().split()))
	sea[r-1][c-1].append([m,s,d])
	
while K:
	K -= 1
	sea = move(N, sea)
	sea = calFireBall(N, sea)
	
m_sum = 0
for i in range(N):
	for j in range(N):
		if sea[i][j]:
			while sea[i][j]:
				m, s, d = sea[i][j].popleft()
				m_sum += m
				
print(m_sum)
