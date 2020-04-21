def Move(board,puyo):
	p_len = len(puyo)
	tmp = [] # 이동된 뿌요의 좌표 입력할 배열
	for _ in range(p_len):
		px, py = puyo.pop() #아래서부터 이동하기 위해서는 맨 뒤에서부터 pop
		if board[px][py] == '.': # 비어있지 않은 뿌요에 대해서만 수행(비어있는 뿌요는 Boom에서 터진 뿌요임)
			continue
		tmp_x = px+1 # 뿌요는 열은 고정한 채 행만 이동할 것(아래로만 이동할 것이기 때문에)
		while tmp_x < 12 and board[tmp_x][py] == '.': # 어디까지 비어있는지 찾는 작업, 좌표를 넘어가지 않고 비어있지 않을 때까지 while문 돌기
			tmp_x += 1
		
		if tmp_x != px+1: # tmp_x와 px+1이 같다면 하나도 못움직인 것이므로 그대로 놔두고, 아니라면
			board[tmp_x-1][py] = board[px][py] # 원래 좌표의 값이 해당 좌표의 값으로 이동하고
			board[px][py] = '.' # 원래의 좌표는 공백이 됨
			px = tmp_x-1 # px의 값도 이동된 x좌표로 바꿔줌
			
		tmp.append([px,py]) # 이동된 뿌요의 좌표 추가

	tmp = sorted(tmp,key=lambda x: x[0]) # 아래서부터 이동해야 하기 때문에 뿌요 정렬 필요

	return board, tmp
	
def Boom(board,boom): # 4개 이상 모여있는 뿌요 터뜨리기
	for x, y in boom: # 터뜨리면 그 자리의 뿌요는 사라져야 하므로 '.'로 바꿔줌
		board[x][y] = '.'
		
	return board

def puyopuyo(board,puyo,cnt):
	while True:
		flag = False # 터진 뿌요가 있는지 여부 확인(없으면 변화가 없을 것이기 때문에 멈춰도 됨)
		visit = [[False]*6 for _ in range(12)] # 방문 여부를 표시할 배열
		for x, y in puyo: # 현재 존재하는 뿌요들에 대해서만 진행
			if visit[x][y] == True: # 이미 방문한 뿌요면 볼 필요 없음(이미 확인되었기 때문)
				continue
			
			q = [] # bfs 진행하기 위한 큐
			q.append([x,y])
			visit[x][y] = True
			color = board[x][y] # 현재 뿌요의 색깔
			
			
			boom = [] # 터뜨릴 뿌요를 저장해 놓는 배열
			dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
			while q:
				x,y = q.pop(0)
				
				boom.append([x,y])
				for dx, dy in dir: # 상하좌우 이동하면서 확인
					nx = x+dx
					ny = y+dy
					if nx >= 0 and nx < 12 and ny >= 0 and ny < 6: # 범위 내에 존재
						if visit[nx][ny] == False and board[nx][ny] == color: # 방문한 적 없고 기준이 되는 뿌요와 같은 색이면
							q.append([nx,ny]) # 큐에 추가
							visit[nx][ny] = True
							
			if len(boom) >= 4: # 연결된 뿌요가 4개 이상이면
				flag = True # 터진 뿌요가 존재함을 표시
				board = Boom(board,boom) # 뿌요 터뜨리기
		
		if flag == False: # 뿌요가 한 번도 터진 적 없다면
			break # 종료
		
		board,puyo = Move(board,puyo) # 아니라면 뿌요 빈칸으로 이동시키고
		cnt += 1 # 연속으로 몇 번 터졌는지 세는 변수 1 증가
	
	return cnt
	

if __name__ == '__main__':
	board = []
	for _ in range(12):
		board.append(list(input()))
	
	puyo = [] # 뿌요가 있는 좌표 담을 
	for i in range(12):
		for j in range(6):
			if(board[i][j] != '.'):
				puyo.append([i,j])
				
	print(puyopuyo(board,puyo,0))
