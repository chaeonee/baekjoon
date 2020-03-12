from itertools import combinations # 바이러스 위치 조합을 구하기 위해 combination import

def getTime(comb, lab, cnt): # 바이러스가 모두 퍼지는 데 걸리는 시간을 구하기 위한 함수
	N = len(lab)
	visit = [[False]*N for _ in range(N)] # 방문 여부 확인 배열
	
	q = [] # queue처럼 사용할 배열
	for c in comb:
		visit[c[0]][c[1]] = True
		q.append(c+[0])
		
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	time = 0 # 모두 퍼지는데 걸리는 시간
	while q: # bfs 방법으로 탐색 시작
		virus = q.pop(0)
		
		for d in dir:
			x = virus[0]+d[0]
			y = virus[1]+d[1]
			if x >= 0 and x < N and y >= 0 and y < N:
				if visit[x][y] == False and lab[x][y] != 1: # 방문한 적 없고 벽이 아니라면
					cnt -= 1
					visit[x][y] = True
					time = virus[2]+1
					
					q.append([x,y,time])
					
	if cnt != 0: # cnt가 0이 아니라면 바이러스가 모두 퍼지지 않았다는 뜻
		time = float("inf")
	
	return time
	
if __name__ == '__main__':
	N, M = list(map(int,input().split()))
	lab = [list(map(int,input().split())) for _ in range(N)]
	
	cnt = (N*N)-M
	v = []
	for i in range(N):
		for j in range(N):
			if lab[i][j] == 1:
				cnt -= 1
			elif lab[i][j] == 2:
				v.append([i,j])
	
	time = float('inf')
	comb = list(combinations(v,M))
	for c in comb:
		t = getTime(c, lab, cnt)
		
		if time > t: # 걸리는 시간의 최소값 구하기 위함
			time = t
			
	if time == float('inf'):
		time = -1
		
	print(time)
