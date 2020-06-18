import sys
from collections import deque
input = sys.stdin.readline

if __name__ == '__main__':
	N, K, R = list(map(int,input().split()))
	
	cow = [[False]*N for _ in range(N)] # 해당 위치에 소가 있는지 여부
	v_cow = [[False]*N for _ in range(N)] # 해당 위치의 소를 이동시켜 봤는지 여부
	road = [[[False]*4 for _ in range(N)] for _ in range(N)] # 해당 위치 상하좌우에 길이 있는지 여부
	for _ in range(R):
		r1, c1, r2, c2 = list(map(int,input().split()))
		
		if r1-r2 == 1: # (r1,c1)과 (r2,c2) 사이에 길이 있고, (r1,c1)이 (r2,c2)의 아래에 위치할 경우
			road[r1-1][c1-1][0] = True # (r1,c1) 위에 길 존재
			road[r2-1][c2-1][1] = True # (r2,c2) 아래에 길 존재
		elif r1-r2 == -1: # (r1,c1)과 (r2,c2) 사이에 길이 있고, (r1,c1)이 (r2,c2)의 위에 위치할 경우
			road[r1-1][c1-1][1] = True # (r1,c1) 아래에 길 존재
			road[r2-1][c2-1][0] = True # (r2,c2) 위에 길 존재
		elif c1-c2 == 1: # (r1,c1)과 (r2,c2) 사이에 길이 있고, (r1,c1)이 (r2,c2)의 오른쪽에 위치할 경우
			road[r1-1][c1-1][2] = True # (r1,c1) 왼쪽에 길 존재
			road[r2-1][c2-1][3] = True  # (r2,c2) 오른쪽에 길 존재
		elif c1-c2 == -1: # (r1,c1)과 (r2,c2) 사이에 길이 있고, (r1,c1)이 (r2,c2)의 왼쪽에 위치할 경우
			road[r1-1][c1-1][3] = True # (r1,c1) 오른쪽에 길 존재
			road[r2-1][c2-1][2] = True # (r2,c2) 왼쪽에 길 존재
		
	pos_cow = [] # 소의 위치 담을 배열
	for _ in range(K):
		r, c = list(map(int,input().split()))
		cow[r-1][c-1] = True # 해당 위치에 소가 존재함을 표시
		pos_cow.append([r-1,c-1]) # 탐색을 위해 소의 위치 저장
	
	result = int((K*(K-1))/2) # 초기 값: 모든 쌍의 수가 만나는 경우의 수(KC2)
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	for k in range(K): # 모든 소를 이동시켜보기
		r,c = pos_cow[k] # 소의 위치
		v_cow[r][c] = True # 해당 소를 이동시켜봤음을 표시
		
		q = deque()
		q.append([r,c])
		
		visit = [[False]*N for _ in range(N)] # 해당 소의 방문 표시
		visit[r][c] = True
		
		while q: # bfs
			x, y = q.popleft()
			
			if cow[x][y] and not v_cow[x][y]: # 다른 소를 만났는데 그 소를 이동시켜본 적 없다면
				result -= 1 # 결과 값 1 감소(길을 건너지 않고 다른 소를 만난 경우 빼야하니까)
				
			for d in range(4): # 상하좌우
				dx = x+dir[d][0]
				dy = y+dir[d][1] # 이동 좌표 계산
				
				if road[x][y][d]: # 해당 방향에 길이 존재한다면 이동하지 않고 건너 뛰기
					continue
				
				if 0 <= dx < N and 0 <= dy < N and not visit[dx][dy]: # 범위 체크 및 방문 체크
					visit[dx][dy] = True # 방문 체크
					q.append([dx,dy])
					
	print(result)
