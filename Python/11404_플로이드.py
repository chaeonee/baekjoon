if __name__ == '__main__':
	n = int(input())
	m = int(input())
	
	cost = [[0]*n for _ in range(n)]
	for _ in range(m):
		tmp = list(map(int,input().split()))
		x = tmp[0] - 1
		y = tmp[1] - 1
		if cost[x][y] != 0 and cost[x][y] <= tmp[2]: # 경로가 여러 개이므로 더 큰 비용은 필요 없음
			continue
		cost[x][y] = tmp[2]

	# C++코드와 동일
	for k in range(n): # 거쳐갈 곳
		for i in range(n): # 시작점
			for j in range(n): # 도착점
				if i == j or i == k or j == k: # 출발점과 도착점이 같은 경우 없음(문제 조건)
					continue
				if cost[i][j] == 0: # 바로 가는 경로 없을 때
					if cost[i][k] != 0 and cost[k][j] != 0: # 거쳐갈 수 있다면 거쳐가기
						cost[i][j] = cost[i][k] + cost[k][j]
				else: # 바로 가는 경로 있을 때(아니면 이미 거쳐가는 경우도 앞쪽에서 계산됐으 때)
					if cost[i][k] != 0 and cost[k][j] != 0: # 다른 비용 적은 경로가 있는지 비교하기
						cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j])
						
	for i in range(n):
		for j in range(n):
			print(cost[i][j], end=' ')
		print()