if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		I = int(input())
		visit = [[False]*I for _ in range(I)] # 나이트의 방문 표시를 위한 배열
		
		cur = list(map(int,input().split()))
		goal = list(map(int,input().split()))
		
		dir = [[-2,-1],[-2,1],[-1,-2],[-1,2],[2,-1],[2,1],[1,-2],[1,2]] # 나이트의 이동 방향
		
		flag = False # 최종 위치에 도착했는지 여부
		if cur[0] == goal[0] and cur[1] == goal[1]: # 입력받은 현재 위치와 최종 위치가 동일할 때
			flag = True
			
		time = 0 # 이동 횟수
		q = [cur+[0]] # queue는 현재 좌표 + 걸린 시간의 쌍을 가지고 있음
		while q and flag == False: # BFS 시작
			cur = q.pop(0)
			
			for d in dir: # 방향 이동
				x = cur[0]+d[0]
				y = cur[1]+d[1]
				if x >= 0 and x < I and y >= 0 and y < I and visit[x][y] == False:
					if x == goal[0] and y == goal[1]: # 이동 위치가 목적지와 동일할 때
						time = cur[2]+1 # 현재 좌표까지의 이동 횟수는 이전 이동 횟수 +1 따라서 최종 걸린 시간에 대입
						flag = True # 목적지에 도달했으므로, flag는 True로 바꿔주고 break(더 이상 탐색하지 않도록)
						break
					visit[x][y] = True
					q.append([x,y,cur[2]+1]) # 목적지가 아닐 경우에는 방문 여부 True로 변경 후 queue에 이동좌표,시간 삽입
					
		print(time)
