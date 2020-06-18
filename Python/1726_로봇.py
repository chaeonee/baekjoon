import sys
from collections import deque
input = sys.stdin.readline

def Go(k,x,y,dir): # 현재 향하고 있는 방향으로 k만큼 이동했을 때의 좌표를 구하기 위한 함수
	if dir == 0: # 동쪽으로 k만큼 이동
		return x, y+k # 열 증가
	elif dir == 1: # 서쪽으로 k만큼 이동
		return x, y-k # 열 감소
	elif dir == 2: # 남쪽으로 k만큼 이동
		return x+k, y # 행 증가
	elif dir == 3: # 북쪽으로 k만큼 이동
		return x-k, y # 행 감소
	
def Turn(dir,cur): # 현재 방향을 기준으로 오른쪽 또는 왼쪽으로 90° 회전했을 때의 방향을 구하기 위한 함수
	if dir == 'left': # 왼쪽으로 회전
		c_dir = [3,2,0,1] # [동,서,남,북] -> [북,남,동,서]
	else: # 오른쪽으로 회전
		c_dir = [2,3,1,0] # [동,서,남,북] -> [남,북,서,동]
	
	return c_dir[cur]
		
	

if __name__ == '__main__':
	M, N = list(map(int,input().split()))
	plant = [list(map(int,input().split())) for _ in range(M)]
	order = [[[float('inf')]*N for _ in range(M)] for _ in range(4)] # 각 위치의 명령 횟수 매우 큰 값으로 초기화
	
	x_start, y_start, dir_start = [i-1 for i in list(map(int,input().split()))] # 시작 좌표(1부터 시작하는 문제와 달리 0부터 시작하도록 구현하였으므로 1씩 빼줌)
	x_end, y_end, dir_end = [i-1 for i in list(map(int,input().split()))] # 도착 좌표(1부터 시작하는 문제와 달리 0부터 시작하도록 구현하였으므로 1씩 빼줌)
	
	q = deque()
	q.append([x_start, y_start, dir_start]) # bfs를 위한 queue 세팅
	order[dir_start][x_start][y_start] = 0 # 시작점 명령 횟수 0
	while q:
		x, y, dir = q.popleft()
		
		if x == x_end and y == y_end and dir == dir_end: # 도착점 도착
			print(order[dir][x][y]) # 도착점의 명령 횟수 출력 후
			break # 루프 탈출
		
		for i in ['left','right']: # Turn 명령
			ddir = Turn(i,dir)
			if order[ddir][x][y] > order[dir][x][y]+1: # 이동할 위치의 명령 횟수보다 (현재 위치의 명령횟수 +1)이 작다면(+1은 현재 turn 명령)
				q.append([x,y,ddir]) # queue에 삽입 후 탐색 진행할 수 있도록
				order[ddir][x][y] = order[dir][x][y]+1 # 명령 횟수 갱신
				
		for k in range(1,4): # Go 명령
			dx, dy = Go(k,x,y,dir)
			if dx < 0 or dx >= M or dy < 0 or dy >= N or plant[dx][dy] == 1: # 범위 밖으로 벗어났거나 벽을 만났다면
				break # 더 이상 이동 불가
			
			if order[dir][dx][dy] > order[dir][x][y]+1: # 이동할 위치의 명령 횟수보다 (현재 위치의 명령횟수 +1)이 작다면(+1은 현재 go 명령)
				q.append([dx,dy,dir]) # queue에 삽입 후 탐색 진행할 수 있도록
				order[dir][dx][dy] = order[dir][x][y]+1 # 명령 횟수 갱신
