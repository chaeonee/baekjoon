import sys
import collections

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	grid = [list(sys.stdin.readline().rstrip('\n')) for _ in range(N)] # 그림 색깔
	
	area = 0 # 구역의 수
	visit = [[False]*N for _ in range(N)] # 방문 여부 체크 위한 배열
	
	dir = [[-1,0], [1,0], [0,-1], [0,1]] # 상하좌우
	for i in range(N):
		for j in range(N): # 적록색약이 아닌 경우
			if not visit[i][j]: # 방문한 적 없다면
				area += 1 # 구역 1증가 후 이 점을 기준으로 bfs 진행
				visit[i][j] = True
				
				q = collections.deque()
				q.append([i,j])
				
				while q: # bfs 진행
					x, y = q.pop()
					
					for dx, dy in dir: # 상하좌우 이동
						dx += x
						dy += y # 이동 좌표 계산
						if dx >= 0 and dx < N and dy >= 0 and dy < N: # 범위 체크
							if not visit[dx][dy] and grid[i][j] == grid[dx][dy]: # 방문한 적 없고 현재 탐색하는 색과 같은 색인지 체크
								visit[dx][dy] = True
								q.append([dx,dy])
			
			if grid[i][j] == 'G': # 적록색약은 빨강=초록 이므로 초록색을 모두 빨강으로 교체
				grid[i][j] = 'R'
	
	print(area, end = ' ') # 적록색약이 아닌 사람이 봤을 때의 구역의 수
	
	area = 0 # 구역의 수 초기화(적록색약인 사람의 경우 탐색 위해)
	visit = [[False]*N for _ in range(N)] # 방문 배열 초기화(적록색약인 사람의 경우 탐색 위해)
	
	for i in range(N):
		for j in range(N): # 적록색약인 사람의 경우 탐색
			if not visit[i][j]: # 방문한 적 
				area += 1 # 구역 1증가 후 이 점을 기준으로 bfs 진행
				visit[i][j] = True
				
				q = collections.deque()
				q.append([i,j])
				
				while q: # bfs 진행
					x, y = q.pop()
					
					for dx, dy in dir: # 상하좌우 이동
						dx += x
						dy += y # 이동 좌표 계산
						if dx >= 0 and dx < N and dy >= 0 and dy < N: # 범위 체크
							if not visit[dx][dy] and grid[i][j] == grid[dx][dy]: # 방문한 적 없고 현재 탐색하는 색과 같은 색인지 체크(초록을 빨강과 동일하게 해놓았으므로 기존과 동일하게 탐색하면 됨)
								visit[dx][dy] = True
								q.append([dx,dy])
								
	print(area) # 적록색약인 사람이 봤을 때의 구역의 수
