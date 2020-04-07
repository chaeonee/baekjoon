p = 0
def moveRobot(N,s,x,y,cur,p_dir,visit):
	if s == N: # N번 모두 이동했다면
		global p 
		p += cur // 현재 확률 전체 확률에 더해줌
		return
    
	dir = [[0,1],[0,-1],[1,0],[-1,0]] # 동서남북
	for i in range(4):
		dx = x + dir[i][0]
		dy = y + dir[i][1] # 이동할 위치
		if dx >= 0 and dx <= 2*N and dy >= 0 and dy <= 2*N: # 범위 내의 위치이고
			if visit[dx][dy] == False: # 방문한 적 없는 위치라면
				visit[dx][dy] = True # 방문 표시
				moveRobot(N,s+1,dx,dy,cur*p_dir[i],p_dir,visit) # 재귀로 다음 step
				visit[dx][dy] = False # 다음 경우의 수 생각하기 위해 방문 표시 제거(현재 dx, dy를 방문한 경우의 수는 모두 확인했음)

if __name__ == '__main__':
	p_dir = list(map(int,input().split()))
	N = p_dir[0]
	p_dir = [x/100 for x in p_dir[1:]]
	
	visit = [[False]*(2*N+1) for _ in range(2*N+1)]
	visit[N][N] = True # 방문 표시(시작 위치)

	moveRobot(N,0,N,N,1,p_dir,visit)
	
	print(p)
