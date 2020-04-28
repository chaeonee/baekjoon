def getDist(s1,s2):
	return abs(s1[0]-s2[0]) + abs(s1[1]-s2[1]) # 좌표 간의 맨해튼 거리

if __name__ == '__main__':
	T = int(input())
	
	for _ in range(T):
		n_conv = int(input())
		
		house = list(map(int,input().split()))
		conv = [list(map(int,input().split())) for i in range(n_conv)]
		festival = list(map(int,input().split()))
		
		spot = [house]+conv+[festival] # 집, 편의점, 페스티벌의 좌표를 담음(첫번째: 집, 마지막: 페스티벌)
		
		visit = [False]*(n_conv+2) # 각 spot을 방문했는지 여부
		dist = [[0]*(n_conv+2) for i in range(n_conv+2)] # 각 spot의 맨해튼 거리를 담을 배열
		for i in range(n_conv+2):
			for j in range(n_conv+2):
				if i == j:
					dist[i][j] = 200000 # 같은 spot끼리의 거리는 매우 큰 값으로 설정
					continue
				dist[i][j] = getDist(spot[i],spot[j])
		
		result = 'sad'
		q = [0]
		visit[0] = True # 집부터 시작하여 bfs
		while q:
			n = q.pop(0)
			
			if n == n_conv+1: # 페스티벌에 도착했을 경우
				result = 'happy'
			
			for i in range(n_conv+2):
				if visit[i] == False and dist[n][i] <= 1000: # 방문한 적 없고 거리가 1000이내라면(맥주가 떨어지지 않고 움직일 수 있는 최대 거리가 1000이기 때문)
					q.append(i) # 큐에 삽입
					visit[i] = True # 방문 표시
					
		print(result)
