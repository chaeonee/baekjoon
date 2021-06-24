import sys
import heapq

def Find(x, parent): # 어떤 집합에 있는지 찾기 위함 함수(Find)
	while x != parent[x]:
		x = parent[x]
	return x

V, E = list(map(int,sys.stdin.readline().split()))

edge = []
for _ in range(E):
	a, b, w = list(map(int,sys.stdin.readline().split()))
	heapq.heappush(edge,[w,a-1,b-1]) # [간선의 가중치, 연결된 노드1, 연결된 노드2], 간선의 가중치가 작을수록 우선순위가 높음

weight = 0 #
parent = [i for i in range(V)] # 각 노드의 부모를 저장
while edge:
	w, a, b = heapq.heappop(edge)
	
	pa = Find(a,parent)
	pb = Find(b,parent)
	if pa != pb: # 두 노드가 같은 집합에 속하지 않는다면 Union
		weight += w # 선택된 간선은 이미 확정이므로 MST 가중치에 더해줌
		if pb <= pa:
			parent[pa] = pb
		else:
			parent[pb] = pa

print(weight)
