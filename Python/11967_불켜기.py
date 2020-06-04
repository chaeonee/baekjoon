import sys
from collections import deque

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	
	room = [[[False, []] for _ in range(N)] for _ in range(N)] # [불 켜졌는지 여부,[현재 위치에서 켤 수 있는 불의 위치]]
	room[0][0][0] = True # 시작점은 불이 켜져 있음
	for _ in range(M):
		x1, y1, x2, y2 = list(map(int,sys.stdin.readline().split()))
		room[x1-1][y1-1][1].append([x2-1,y2-1]) # 문제의 범위 1~N, 하지만 인덱스의 범위 0~N-1이므로 1씩 빼줘야 함
	
	dir = [[-1,0], [1,0], [0,-1], [0,1]] # 상하좌우
	
	q = deque()
	q.append([0,0]) # bfs를 위한 queue
	visit = [[False]*N for _ in range(N)] # 방문 여부 표시
	visit[0][0] = True
	
	cnt = 1 # 시작점의 불은 켜져 있으므로 1로 시작
	while q:
		x, y = q.popleft()
		
		flag = False # 현재 위치에서 불 켰는지 여부를 나타내는 flag
		for dx, dy in room[x][y][1]:
			if not room[dx][dy][0]: # 현재 위치에서 불을 켤 수 있고, 불이 꺼져 있는 경우 불 켜야 함
				cnt += 1 # 불 켜진 방 1 추가
				flag = True # 현재 위치에서 불 켰으므로 flag true
				room[dx][dy][0] = True # 불켜기
				
		if flag: # 불을 켰다면 새로운 경로 추가된 것이므로 visit 초기화해서 재 탐색
			visit = [[False]*N for _ in range(N)]
			
		for dx, dy in dir: # 상하좌우 이동
			dx += x
			dy += y
			if 0 <= dx < N and 0 <= dy < N: # 범위 체크
				if room[dx][dy][0] and not visit[dx][dy]: # 불이 켜져있고 방문한적 없으면
					q.append([dx,dy])
					visit[dx][dy] = True # bfs 진행 및 방문 체크
					
	print(cnt)
