import sys
from collections import deque

if __name__ == '__main__':
	num = 0 # test case의 번호
	dir = [[-1,0], [1,0], [0,-1], [0,1]] # 상하좌우
	while True:
		N = int(sys.stdin.readline())
		if N == 0:
			break # N이 0이면 루프 탈출
		
		num += 1 # test case의 번호 1증가
		
		rupee = [list(map(int,sys.stdin.readline().split())) for _ in range(N)] # 도둑루피의 크기
		cost = [[float('inf')]*N for _ in range(N)] # cost를 담을 배열
		cost[0][0] = rupee[0][0] # (0,0)에서 시작하기 때문에 (0,0)초기화
		
		q = deque()
		q.append([0,0]) # 시작점으로 queue 초기화
		while q:
			x, y = q.popleft()
			
			for dx, dy in dir: #상하좌우
				dx += x
				dy += y # 이동후 좌표 계산
				if 0 <= dx < N and 0 <= dy < N: # 범우 체크
					if cost[dx][dy] > cost[x][y] + rupee[dx][dy]: # 방문 체크 대신 cost 체크, 기존의 cost가 새로 계산된 cost보다 크다면
						cost[dx][dy] = cost[x][y] + rupee[dx][dy] # cost 갱신(최소 cost를 찾아야 하므로)
						q.append([dx,dy]) # queue에 추가하여 탐색 진행하도록(새로운 cost가 들어왔으므로 다시 계산해야 함)
						
		print("Problem %d: %d" %(num, cost[N-1][N-1])) # 최종 목적지가 (N-1, N-1)이므로 (N-1, N-1)의 cost 출력
