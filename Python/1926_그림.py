if __name__ == '__main__':
	n, m = list(map(int,input().split()))
	
	canvas = []
	for _ in range(n):
		canvas.append(list(map(int,input().split())))
		
	visit = [[0]*m for _ in range(n)] # 방문 여부 표시
	
	cnt = 0 # 그림 영역의 수
	max_size = 0 # 그림 영역의 최대 크기
	queue = []
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	for i in range(n):
		for j in range(m):
			if visit[i][j] == 0 and canvas[i][j] == 1: # 방문한 적 없고 그림이 그려져 있다면
				visit[i][j] = 1 # 방문 여부 변경
				queue.append([i,j])
				cnt += 1
				
				tmp = 0 # 현재 영역의 크기
				while queue:
					p = queue.pop(0)
					tmp += 1
					
					for d in dir:
						x = p[0]+d[0]
						y = p[1]+d[1]
						
						if x >= 0 and x < n and y >= 0 and y < m: # 인덱스가 범위 내에 존재하고
							if visit[x][y] == 0 and canvas[x][y] == 1: # 방문한 적 없고 그림이 그려져 있다면
								visit[x][y] = 1
								queue.append([x,y])
								
				if tmp > max_size: # 현재 영역과 지금까지 계산된 최대 영역과 비교하여 최대 영역 갱신
					max_size = tmp
          
	print(cnt)
	print(max_size)
