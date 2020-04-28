if __name__ == '__main__':
	N, M, T = list(map(int,input().split()))
	board = [list(map(int,input().split())) for _ in range(N)] # 원판
	
	b_sum = sum([sum(x) for x in board]) # 원판 숫자의 합
	n_board = N*M # 원판에 존재하는 숫자의 개수
	
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	for _ in range(T):
		x, d, k = list(map(int,input().split()))
		for i in range(x-1, N, x): # x의 배수 위치의 원판 회전(0부터 시작했으므로 1씩 빼서 생각)
			if d == 0: # 시계방향
				for j in range(k):
					n = board[i].pop()
					board[i].insert(0,n)
			else: # 반시계 방향
				for j in range(k):
					n = board[i].pop(0)
					board[i].append(n)
					
		visit = [[False]*M for _ in range(N)] # 방문 여부 체크
		flag = False # 제거된 숫자 있는지 여부
		for i in range(N):
			for j in range(M):
				if visit[i][j] == False and board[i][j] != -1: # 방문한 적 없고 숫자가 존재한다면
					num = board[i][j] # 현재 숫자 값 저장
					
					q = [[i,j]]
					visit[i][j] = True
					r = [] # 현재 좌표와 인접한 좌표 리스트(값이 같아야하고 이 리스트에는 현재 좌표도 포함)
					while q: # bfs 진행
						n = q.pop(0)
						r.append(n)
						
						for d in dir: # 상하좌우 확인
							x = n[0]+d[0]
							y = n[1]+d[1]
							
							if y < 0: # 원판이므로 y좌표가 음수(-1)일 경우에는 맨 끝 값을 의미
								y = M-1
							y %= M # 원판이므로 빙글빙글~~(이것을 %M을 이용하여 처리)
							if x >= 0 and x < N: # y좌표는 모두 처리했으므로 x좌표만 범위 내에 존재하는지 확인
								if visit[x][y] == False and board[x][y] == num: # 방문한 적이 없고 원판의 수가 같다면
									q.append([x,y]) # q에 추가
									visit[x][y] = True # 방문 체크
									
					if len(r) > 1: # 인접한 것이 존재한다면
						flag = True # 제거된 숫자가 존재하는 것이므로 true
						while r: # 제거
							n = r.pop()
							b_sum -= board[n[0]][n[1]]
							n_board -= 1
							board[n[0]][n[1]] = -1
		
    if n_board == 0: # 원판에 숫자가 더이상 존재하지 않으면 더 진행할 필요 없음
			break
		
		if flag == False: # 만약 없어진 숫자가 없으면
			avg = b_sum/n_board # 남은 숫자들의 평균 구해서
			for i in range(N):
				for j in range(M):
					if board[i][j] == -1:
						continue
					if board[i][j] > avg: # 평균보다 크면
						board[i][j] -= 1 # 1 빼주기
						b_sum -= 1 # 전체 합도 1 작아질 것
					elif board[i][j] < avg: # 평균보다 작으면
						board[i][j] += 1 # 1 더해주기
						b_sum += 1 # 전체 합도 1 커질 것
	print(b_sum)
