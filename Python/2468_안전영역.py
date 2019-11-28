if __name__ == "__main__":
	N = int(input())
	
	area = []
	for i in range(N):
		area.append(list(map(int,input().split())))
		
	safe_area = 1 #아무 것도 안잠겼을 때는 안전영역의 수 1
	
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	
	H = list(set(sum(area,[]))) # 지역 높이의 set(1이상 100이하를 모두 해볼 수는 없으니까)
	for h in H: # 높이만큼 돌면서 진행
		visit = [[False]*N for i in range(N)]
		tmp_area = 0
		for i in range(N): 
			for j in range(N): # 배열 돌면서 시작점 설정
				if area[i][j] > h and visit[i][j] == False:
					tmp_area += 1 # 구역 1 증가
					
					queue = []
					queue.append([i,j])
					visit[i][j] = True
					while queue: # 시작 지점과 연결된 지점들은 bfs로 방문하기
						n = queue.pop(0)
						
						for d in dir:
							x = n[0]+d[0]
							y = n[1]+d[1]
							if x >= 0 and x < N and y >= 0 and y < N and visit[x][y] == False and area[x][y] > h:
								queue.append([x,y])
								visit[x][y] = True
				
				elif area[i][j] <= h and visit[i][j] == False: #h보다 작거나 같으면 침수된 지역이기 때문에 방문했다고 생각하기
					visit[i][j] = True
		
		if tmp_area > safe_area: # 최댓값 구하기 위함
			safe_area = tmp_area
			
			
	print(safe_area)