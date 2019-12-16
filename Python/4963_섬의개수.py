if __name__ == '__main__':
	dir = [[1,0],[-1,0],[0,1],[0,-1],[1,1],[1,-1],[-1,1],[-1,-1]] # 방향을 담는 배열(상,하,좌,우 대각선 4방)
	
	while True:
		w, h = list(map(int,input().split()))
		
		if w == 0 and h == 0: # 종료 조건
			break
		
		area = [] # 지도를 담은 배열
		for i in range(h):
			tmp = list(map(int,input().split()))
			area.append(tmp)
		
		num = 0
		for i in range(h):
			for j in range(w):
				if area[i][j] != 0: # 바다가 아닌 육지인 곳만 탐색(queue를 이용한 bfs)
					queue = []
					queue.append([i,j])
					area[i][j] = 0 # visit 배열 없이 방문 완료한 곳은 0으로 바꿔줌
					
					num += 1 # 하나의 root에 의해 탐색된 그래프는 하나의 영역이므로 영역 1개만 증가
					while queue: # bfs
						n = queue.pop(0)
						
						for d in dir:
							tmp_h = n[0]+d[0] 
							tmp_w = n[1]+d[1]
							if tmp_h >= 0 and tmp_h < h and tmp_w >= 0 and tmp_w < w: # 범위를 벗어나지 않고
								if area[tmp_h][tmp_w] != 0: # 바다가 아니라 육지일 때
									area[tmp_h][tmp_w] = 0 # 0으로 바꿔주고(여러 번 탐색하지 않도록)
									queue.append([tmp_h,tmp_w]) # 탐색을 위해 queue에 추가
									
		print(num)