import sys

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	
	dist = [[1000]*N for _ in range(N)] # dist[i][j]: i와 j간의 최단 경로
	for i in range(N):
		dist[i][i] = 0 # 자기 자신과의 경로 길이는 0으로 설정
		
	for _ in range(M):
		p1, p2 = list(map(int,sys.stdin.readline().split()))
		dist[p1-1][p2-1] = 1
		dist[p2-1][p1-1] = 1 # 방향이 없는 그래프임으로 쌍방 연결 표시
		
	for k in range(N): # 거처가는 사람의 번호
		for i in range(N): # 출발점
			for j in range(i,N): # 도착점
				if i == j or i == k or j == k: # 출발점과 도착점 그리고 경유 지점 중 하나라도 같은 경우는 고려할 필요 없음 
					continue
				
				tmp = min(dist[i][j],dist[i][k]+dist[k][j]) # 출발점에서 도착점으로 가기 위한 지금까지의 최단 경로와 k를 거쳐가는 경우 중 더 짧은 경로 구함
				dist[i][j] = tmp
				dist[j][i] = tmp # 최단 경로 갱신
	
	num = 0
	min_dist = 10000
	for i in range(N): # 케빈 베이컨의 수가 가장 작은 사람을 출력을 위함
		tmp = sum(dist[i])
		if(tmp < min_dist): # 최소 케빈 베이컨의 수 갱신 및 그 때 해당하는 사람(같을 경우에는 수가 번호가 작아야 하므로 갱신하지 않음)
			min_dist = tmp
			num = i
			
	print(num+1) # 인덱스가 0부터 시작함 -> 1 증가하여 출력
