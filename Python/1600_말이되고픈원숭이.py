import sys
import collections

if __name__ == '__main__':
	K = int(sys.stdin.readline())
	W, H = list(map(int,sys.stdin.readline().split()))
	board = [list(map(int,sys.stdin.readline().split())) for _ in range(H)]
	
	visit = [[[False]*W for i in range(H)] for j in range(K+1)] # 0~K까지 일 때 방문 여부를 나타낼 배열
	visit[K][0][0] = True
	
	dir = [[-1,0],[1,0],[0,-1],[0,1],[-2,-1],[-1,-2],[1,-2],[2,-1],[-2,1],[-1,2],[1,2],[2,1]] # 상하좌우 + 말 이동
	
	result = -1
	q = collections.deque() # list를 사용했더니 시간초과가 남... 그래서 collections.deqeue()를 사용(겨우 통과..^^)
	q.append([0,0,0,K])
	while q:
		x, y, num, k = q.popleft()
		
		if x == H-1 and y == W-1: # 목적지 도착하였다면 num을 result에 저장 / 목적지에 도착하지 못하는 경우 result에 num을 저장하지 못하기 때문에 -1이 저장되어 있을 겄임
			result = num
			break
		
		for dx, dy in dir[:4]: # 상하좌우 이동
			mx = x + dx
			my = y + dy
			if mx >= 0 and mx < H and my >= 0 and my < W:
				if visit[k][mx][my] == False and board[mx][my] == 0: # 말처럼 이동할 수 있는 횟수 그대로
					q.append([mx,my,num+1,k])
					visit[k][mx][my] = True
		if k > 0: # k가 0보다 크다는 것은 말처럼 이동할 수 있다는 뜻 -> 말처럼 이동
			for dx, dy in dir[4:12]:
				mx = x + dx
				my = y + dy
				if mx >= 0 and mx < H and my >= 0 and my < W:
					if visit[k-1][mx][my] == False and board[mx][my] == 0: # 말처럼 이동할 수 있는 횟수 1감소 -> 방문 표시도 k-1에 해야하고 queue에도 k-1 넣어주어야 함
						q.append([mx,my,num+1,k-1])
						visit[k-1][mx][my] = True
					
	print(result)
