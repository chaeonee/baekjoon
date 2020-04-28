def moveWhite(chess,mal,s,e,num): # 흰색으로 이동할 경우
	move = [] # 이동시켜야 하는 말들을 담은 배열
	while True: # 이동시키려는 말 위에 있는 모든 말들을 순서 변화 없이 이동
		tmp = chess[s[0]][s[1]].pop()
		
		move.append(tmp) # 위에 있는 말 move 배열에 추가
		if tmp == num: # 이동시키려는 말을 만날 때까지
			break
	
	while move: # move 배열에 이동시키려는 말이 위->아래로 정렬되어 있으므로 뒤쪽에 있는 말부터 뽑아서 이동시켜주기 
		tmp = move.pop()
		chess[e[0]][e[1]].append(tmp)
		mal[tmp][0] = e[0]
		mal[tmp][1] = e[1] # 이동시킨 말의 위치 바꿔주기
		
	return mal
	
def moveRed(chess,mal,s,e,num): # 빨간색으로 이동할 경우
	while True: # 이동시키려는 말 위에 있는 모든 말들을 이동시키는데 순서 뒤집기(뒤집으려면 위에 있는 말들이 먼저 이동해야 함)
		tmp = chess[s[0]][s[1]].pop()
		
		chess[e[0]][e[1]].append(tmp) # 위쪽 말부터 목적지로 이동시키기
		
		mal[tmp][0] = e[0]
		mal[tmp][1] = e[1] # 이동시킨 말의 위치 바꿔주기
		
		if tmp == num: # 이동시키려는 말을 만날 때까지
			break

	return mal

if __name__ == '__main__':
	N, K = list(map(int,input().split()))
	board = [list(map(int,input().split())) for _ in range(N)] # 체스판의 색깔을 담고 있는 배열

	mal = []
	chess = [] # 체스판 해당 위치에 몇번 말들이 있는지 표시하기 위한 배열
	for i in range(N):
		tmp = []
		for j in range(N):
			tmp.append([])
		chess.append(tmp)
		
	for k in range(K):
		x, y, dir = list(map(int,input().split()))
		x -= 1
		y -= 1
		chess[x][y].append(k)
		mal.append([x,y,dir-1]) # 말의 위치, 방향 담은 배열
	
	dir = [[0,1],[0,-1],[-1,0],[1,0]] # 우, 좌, 상, 하
	r_dir = [1,0,3,2] # 현재 방향을 반대로 뒤집어야 할 때 어떤 방향으로 뒤집어야할 지 기록해 놓은 배열
	turn = 0
	flag = False # 게임이 정상 종료 되었는지 여부
	while True:
		turn += 1
		
		if turn > 1000:
			break
		
		for i in range(K): # 말 순서대로 이동시키기
			p = mal[i]
      dx = p[0] + dir[p[2]][0]
			dy = p[1] + dir[p[2]][1] # 이동해야할 말의 위치
			if dx < 0 or dx >= N or dy < 0 or dy >= N or board[dx][dy] == 2: # 범위를 벗어났거나 파란색 체스판인 경우
				mal[i][2] = r_dir[mal[i][2]] # 방향 바꾸고
        
        p = mal[i]
        dx = p[0] + dir[p[2]][0]
        dy = p[1] + dir[p[2]][1] # 이동해야할 말의 위치 다시 설정
			
			if dx >= 0 and dx < N and dy >= 0 and dy < N: # 범위 내에 존재하고
				if board[dx][dy] == 0: # 이동하려는 체스판이 흰색일 경우
					mal = moveWhite(chess,mal,[p[0],p[1]],[dx,dy],i)
				elif board[dx][dy] == 1: # 이동하려는 체스판이 빨간색일 경우
					mal = moveRed(chess,mal,[p[0],p[1]],[dx,dy],i)
        # 이동하려는 체스판이 파란색이거나 범위 밖일 경우에는 아무것도 수행하지 않음(만약 방향을 바꿔야하는 경우였다면 위쪽 조건문에서 이미 실행됐을 것임)
					
				if len(chess[dx][dy]) >= 4: # 4개 이상의 말이 한 위치에 쌓여있다면
					flag = True # 정상 종료
					break
		if flag:
			break
		
	if flag: # 정상 종료라면
		print(turn) # 해당 턴 출력
	else: 비정상 종료라면
		print(-1) # -1 출력
