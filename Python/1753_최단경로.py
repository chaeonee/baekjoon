import sys
import heapq
input = sys.stdin.readline

if __name__ == '__main__':
	V, E = list(map(int,input().split()))
	K = int(input())
	
	weight = [[] for _ in range(V)] # 해당 정점과 연결된 정점 및 경로 길이 저장하기 위한 배열
	for _ in range(E):
		u, v, w = list(map(int,input().split()))
		weight[u-1].append([v-1, w])
			
	pq = [] # priority queue
	heapq.heappush(pq, (0,K-1)) # heapq 이용하여 시작점 넣기 / (경로의 길이, 정점)순으로 저장되며 경로의 길이가 작을수록 우선순위 높음
	
	cost = [float('inf')]*V # 매우 큰 값으로 경로의 길이 배열 초기화 (시작점으로부터의 최단 경로 저장할 것)
	cost[K-1] = 0 # 시작점은 경로의 길이 0으로 초기화
	while pq:
		w, v = heapq.heappop(pq)
			
		for dest, edge_w in weight[v]:
			if cost[dest] > w+edge_w: # 기존에 저장된 최단 경로가 새로 계산된 최단 경로보다 작으면
				heapq.heappush(pq, (w+edge_w,dest)) # 우선순위 큐에 넣기
				cost[dest] = w+edge_w # 최단 경로 갱신
		
	for c in cost: # 최단 경로 출력, 무한대일 경우 이동할 수 없는 경우이기 때문에 "INF" 출력
		print(c if c != float('inf') else "INF")
