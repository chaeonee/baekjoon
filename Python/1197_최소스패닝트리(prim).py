import sys
import heapq

V, E = list(map(int,sys.stdin.readline().split()))

visit = [False]*V # 가중치가 확정되었는지 여부
edge = {}
for _ in range(E): # 노드와 연결된 edge를 dictionary에 저장
	a, b, w = list(map(int,sys.stdin.readline().split()))
	
	if a-1 not in edge.keys():
		edge[a-1] = {}
	if b-1 not in edge.keys():
		edge[b-1] = {}
	
	if b-1 not in edge[a-1].keys():
		edge[a-1][b-1] = float('inf')
	if a-1 not in edge[b-1].keys():
		edge[b-1][a-1] = float('inf')
		
	edge[a-1][b-1] = edge[b-1][a-1] = min(edge[a-1][b-1], w)

pq = []
heapq.heappush(pq, [0,0]) # [노드의 가중치, 노드 번호], 노드의 가중치를 우선순위로 함(작을수록 우선순위 높음)

weight = 0 # MST의 전체 가중치
while pq:
	w, n = heapq.heappop(pq)
	
	if visit[n]: # 이미 가중치 확정된 경우
		continue
	visit[n] = True
	
	weight += w # MST의 간선 가중치 추가
	for k, v in edge[n].items(): # 해당 노드와 연결된 간선 중
		if visit[k]: # 이미 가중치 확정된 애들
			continue # 제외
		heapq.heappush(pq, [v,k]) # 아닌 애들 추가해주기
		
print(weight)
