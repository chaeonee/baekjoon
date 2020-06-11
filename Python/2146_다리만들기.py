import sys
from collections import deque

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	sea = [list(map(int,sys.stdin.readline().split())) for _ in range(N)] # 바다와 섬 정보가 담긴 배열
	
	dir = [[-1,0], [1,0], [0,-1], [0,1]] # 상하좌우
	
	bridge = float('inf') # 섬을 연결하기 위한 다리 길이의 최솟값을 담을 변수(큰 값으로 초기화)
	for i in range(N):
		for j in range(N):
			if sea[i][j] != 0: # 바다가 아니라 육지여야 함
				flag = False # 섬의 가장자리 여부 체크하기 위한 flag(섬의 가장자리에 다리를 놔야 하기 때문에)
				for di, dj in dir:
					di += i
					dj += j
					if 0 <= di < N and 0 <= dj < N:
						if sea[di][dj] == 0: # 상하좌우 중 한 군데라도 바다가 접해있으면 가장자리
							flag = True
							
				if not flag: # 가장자리가 아니라면 continue
					continue
                    
				visit = [[False]*N for _ in range(N)] # 방문 체크
				visit[i][j] = True
				
				q = deque()
				q.append([i,j]) # 섬의 x,y좌표로 초기화

				while q: # 같은 섬 미리 방문 체크하기 위한 bfs
					x,y = q.popleft()
					for dx, dy in dir: # 상하좌우
						dx += x
						dy += y
						if 0 <= dx < N and 0 <= dy < N: # 범위 체크
							if not visit[dx][dy] and sea[dx][dy] != 0: # 방문한 적 없고 인접한 육지라면
								q.append([dx,dy]) # 큐에 삽입
								visit[dx][dy] = True # 방문 여부 체크
								
				q.append([i,j,0]) # 섬의 x,y좌표와 최초의 위치부터 다리를 놨을 때 다리의 길이로 초기화
				while q: # bfs
					x, y, len = q.popleft()
					if (x != i or y != j) and sea[x][y] != 0: # 처음 위치가 아닌 육지 발견했을 때
						bridge = min(bridge, len-1) # 다리의 최솟값 구하기(1 빼는 이유는 도착점 좌표까지 다리의 길이에 포함되어 있기 때문)
						break
					
					for dx, dy in dir: # 상하좌우
						dx += x
						dy += y
						if 0 <= dx < N and 0 <= dy < N and not visit[dx][dy]: # 범위체크 및 방문체크
							q.append([dx,dy,len+1]) # 큐에 삽입
							visit[dx][dy] = True # 방문 여부 체크
				
	print(bridge)
