import sys
from collections import deque

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	
	connected = [[False]*N for _ in range(N)] # connected[i][j]: i와 j가 연결되었는지 나타냄
	dist = [[0]*N for _ in range(N)] # dist[i][j]: i와 j간의 최단 경로

	for _ in range(M):
		p1, p2 = list(map(int,sys.stdin.readline().split()))
		connected[p1-1][p2-1] = True
		connected[p2-1][p1-1] = True # 방향이 없는 그래프임으로 쌍방 연결 표시
		
	for i in range(N): # 시작점 1~N
		q = deque() # BFS를 위한 queue
		q.append([i,0]) # 도착점과 해당 도착점까지의 최단 경로 길이
		
		visit = [False]*N # 방문 체크
		visit[i] = True
		while q: # BFS 시작
			num, step = q.popleft()
			
			for j in range(N):
				if not visit[j] and connected[num][j]: # 방문한적 없고 연결되어있으면
					visit[j] = True # 방문 표시
					q.append([j,step+1]) # 다음 탐색을 위해 queue에 추가
					dist[i][j] = step+1
					dist[j][i] = step+1 # 최단 경로
	
	num = 0
	min_dist = 10000
	for i in range(N): # 케빈 베이컨의 수가 가장 작은 사람을 출력을 위함
		tmp = sum(dist[i])
		if(tmp < min_dist): # 최소 케빈 베이컨의 수 갱신 및 그 때 해당하는 사람(같을 경우에는 수가 번호가 작아야 하므로 갱신하지 않음)
			min_dist = tmp
			num = i
			
	print(num+1) # 인덱스가 0부터 시작함 -> 1 증가하여 출력
