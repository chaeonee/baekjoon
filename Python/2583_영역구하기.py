import sys
import collections

if __name__ == '__main__':
	M, N, K = list(map(int,sys.stdin.readline().split()))
	
	area = [[False]*N for _ in range(M)]
	for _ in range(K):
		x1, y1, x2, y2 = list(map(int,sys.stdin.readline().split()))
		
		for x in range(x1,x2): # 직사각형 범위를 true로 바꿔주어 영역 구할 때 방문하지 못하게
			for y in range(M-y2,M-y1): # y값은 y = M으로 대칭시켜줌(왼쪽 위의 좌표를 (0,0)으로 만들어주기 위함)
				area[y][x] = True
	
	dir = [[-1,0], [1,0], [0,-1], [0,1]] # 상하좌우
	
	a_cnt = [] # 각 영역의 넓이를 담을 배열
	for i in range(M):
		for j in range(N):
			if not area[i][j]: # 직사각형의 범위가 아니거나 방문한 적 없을 때,
				q = collections.deque()
				q.append([i,j])
				area[i][j] = True # bfs 진행을 위해 초기화
				
				cnt = 0 # 현재 영역의 넓이
				while q:
					y, x = q.popleft()
					cnt += 1
					
					for dy, dx in dir:
						dx += x
						dy += y
						
						if dx >= 0 and dx < N and dy >= 0 and dy < M and not area[dy][dx]: # 범위 내에 존재 & 직사각형의 범위 아니고 방문한적도 없음
							q.append([dy,dx])
							area[dy][dx] = True
				
				a_cnt.append(cnt) # 현재 영역의 넓이 push
				
	a_cnt.sort() # 각 영역을 담은 배열 오름차순으로 정렬
	print(len(a_cnt)) # 영역의 수 = 영역을 담은 배열의 길이
	for i in a_cnt: # 정렬된 각 영역의 넓이 출력
		print(i, end = " ")
