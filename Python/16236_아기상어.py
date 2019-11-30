if __name__ == '__main__':
	N = int(input())

	sea = []
	for _ in range(N):
		sea.append(list(map(int,input().split())))

	queue = [] # 물고기 이동 경로 bfs
	fish = [0]*7 # 크기 별 물고기 수
	visit = [[False]*N for _ in range(N)] # 방문 여부 확인(한 번 잡아먹으면 갱신 해야 함)

	result = 0
	for i in range(N):
		for j in range(N):
			if sea[i][j] == 9:
				queue.append([i,j,2,0]) #x좌표, y좌표, 크기, 이동횟수
				sea[i][j] = 0
				visit[i][j] = True
			elif sea[i][j] > 0 and sea[i][j] != 9:
				fish[sea[i][j]] += 1 # 크기 별 물고기 수 세기

	dir = [[-1,0],[1,0],[0,-1],[0,1]] #상하좌우

	eat_num = 0 # 먹은 물고기 수
	fish_num = fish[1] # 먹을 수 있는 물고기 수
	while fish_num > 0 and queue:
		iter_size = len(queue)
		fish_tmp = [] # 다음 이동 위치 물고기들 넣기(존재하면)
		for _ in range(iter_size):
			f = queue.pop(0)
			visit[f[0]][f[1]] = True

			for d in dir:
				x = f[0]+d[0] # 이동할 x좌표
				y = f[1]+d[1] # 이동할 y좌표
				s = f[2] # 상어 크기
				move = f[3] # 이동 횟수
				if x >= 0 and x < N and y >= 0 and y < N and visit[x][y] == False:
					visit[x][y] = True
					if sea[x][y] == 0 or sea[x][y] == s:
						queue.append([x,y,s,move+1])
					elif sea[x][y] != 0 and sea[x][y] < s:
						fish_tmp.append([x,y,s,move+1])

		if len(fish_tmp) != 0: # 잡힌 물고기 있을 때
			fish_tmp.sort(key=lambda x:x[1])
			fish_tmp.sort(key=lambda x:x[0]) # 위 -> 왼쪽에 있는 물고기를 먼저 잡아 먹기 위해 sorting

			eat_num += 1 # 먹은 물고기 수 세기
			fish_num -= 1 # 잡아먹을 수 있는 물고기 한 마리 감소
			sea[fish_tmp[0][0]][fish_tmp[0][1]] = 0 # 물고기 잡아먹었으니까
			queue = []
			queue.append(fish_tmp[0])#잡아 먹은 물고기부터 다시 시작해야 하니까
			result = fish_tmp[0][3]

			visit = [[False]*N for _ in range(N)] # 방문 배열 다시 초기화
			visit[queue[0][0]][queue[0][1]] = True

			if eat_num == queue[0][2] and queue[0][2] < 7: # 자신의 크기만큼 잡아 먹었을 때(물고기 7이상이면 다 잡아 먹을 수 있고 더이상 잡아먹을 추가 물고기 없음)
				fish_num += fish[queue[0][2]] # 크기 증가하면 증가하기 전 크기만큼의 물고기 더 잡아먹을 수 있게 됨
				queue[0][2] += 1 # 물고기 크기 증가
				eat_num = 0 # 잡아먹은 물고기 수 초기화

	print(result)
