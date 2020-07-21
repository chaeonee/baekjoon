import sys

def Find(n, parent): # 해당 도시 n의 root를 찾는 함수(어떤 집합에 속하는 지)
	n = parent[n]
	while n != parent[n]: # 해당 노드가 root일 때까지 반복문 수행
		n = parent[n] # 부모노드로 이동
	
	return n # 최종 root return
	
def Union(a, b, parent): # 도시 a와 b를 하나의 집합으로 결합하는 함수
	a = Find(a, parent)
	b = Find(b, parent) # 각 도시의 root를 구함(어떤 집합에 속하는 지)
	
	if a == b:
		return
	
	parent[b] = a # b의 부모를 a로 설정(이로써 두 집합이 결합됨)

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	M = int(sys.stdin.readline())
	
	link = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
	
	parent = [i for i in range(N)]
	for i in range(N):
		for j in range(N):
			if link[i][j] == 0: # 두 도시가 연결되어있지 않으면
				continue # 아무것도 수행하지 않음
		
			# 두 도시가 연결되어 있으면
			Union(i, j, parent) # 두 도시가 속한 집합 결합
			
	travel = list(map(int,sys.stdin.readline().split()))
	
	flag = True # 주어진 여행지를 모두 여행할 수 있는지 나타내는 변수
	p_city = Find(travel[0]-1,parent) # 초기화(첫 번째 여행지가 속한 집합의 root로)
	for t in travel[1:]:
		if p_city != Find(t-1,parent): # 기준 여행지(첫 번째 여행지)와 다른 집합에 속한다면
			flag = False # flag를 False로 바꿔준 후
			break # 더 이상 보지 않고 break
		
	if flag: # 주어진 여행지 모두 여행할 수 있는 경우
		print("YES", end='')
	else: # 주어진 여행지 중 한 곳이라도 여행할 수 없는 경우
		print("NO", end='')
