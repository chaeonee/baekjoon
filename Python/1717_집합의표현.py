import sys

def Find(n, parent): # 해당 원소가 어떤 집합에 속하는지 찾는 함수
	n = parent[n][0]
	while parent[n][0] != n: # 부모 노드와 원소의 값이 같으면 root이므로, 반복문 종료
		n = parent[n][0] # 부모 노드로 이동
	
	return n # 루트 노드 값 return
	
def Union(a, b, parent):
	a = Find(a, parent) # a 원소가 어떤 집합에 속하는지 찾기(a 원소의 root 찾기)
	b = Find(b, parent) # b 원소가 어떤 집합에 속하는지 찾기(b 원소의 root 찾기)
	
	if a == b: # a와 b가 같은 집합에 속한다면,
		return # 두 원소 결합할 필요 없음
	
	# 아니라면, 두 집합의 높이 비교
	if parent[a][1] < parent[b][1]: # b의 높이가 더 높다면
		parent[a][0] = b # a의 부모를 b로 설정
	else: # a의 높이가 같거나 더 높다면
		parent[b][0] = a # b의 부모를 a로 설정
		if parent[a][1] == parent[b][1]: # 높이가 같다면
			parent[a][1] += 1 # 높이가 1증가 됨

if __name__ == '__main__':
	n, m = list(map(int,sys.stdin.readline().split()))
	
	parent = [[i, 1] for i in range(n+1)] # 부모 노드의 값과 해당 노드부터 leaf까지의 높이 담은 배열
	
	for _ in range(m):
		order, a, b = list(map(int,sys.stdin.readline().split()))
		
		if order == 0: # 0은 합집합을 구하는 연산
			Union(a, b, parent)
		else: # 1은 두 원소가 같은 집합에 존재하는지 구하는 연산
			a = Find(a, parent)
			b = Find(b, parent) # 각 원소의 root 구하기
			
			if a == b: # 만약 root가 같다면
				print("YES") # 같은 집합에 속함
			else: # 아니라면
				print("NO") # 다른 집합에 속함
