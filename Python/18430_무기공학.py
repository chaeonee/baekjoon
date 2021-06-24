import sys

def makeBoomerang(s, N, M, material, visit, cur, max_strength):
	if s >= N*M:
		max_strength = max(cur, max_strength)
		return max_strength
		
	max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength) # 현재칸을 중심으로 선택하지 않는 경우(case1)
	
	i, j = s // M, s % M # 행, 열의 값을 칸의 번호르 체크해놓았기 때문에, 다시 행과 열의 값으로 바꿔주는 과정
	
	if visit[i][j]: # 이미 선택된 칸 (날개로)
		return max_strength
	
	cur += 2*material[i][j] # 현재칸이 중심으로 선택되었기 때문에 강도의 2배 더해 줌
	visit[i][j] = True # 해당 칸 선택되었음을 표시
	
	if i+1 < N and j-1 >= 0 and not visit[i+1][j] and not visit[i][j-1]: # 날개가 왼쪽 아래쪽(case2)
		visit[i+1][j] = True
		visit[i][j-1] = True
		cur += material[i+1][j] + material[i][j-1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i+1][j] = False
		visit[i][j-1] = False
		cur -= material[i+1][j] + material[i][j-1]
		
	if i-1 >= 0 and j-1 >= 0 and not visit[i-1][j] and not visit[i][j-1]: # 날개가 왼쪽 위쪽(case3)
		visit[i-1][j] = True
		visit[i][j-1] = True
		cur += material[i-1][j] + material[i][j-1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i-1][j] = False
		visit[i][j-1] = False
		cur -= material[i-1][j] + material[i][j-1]
		
	if i-1 >= 0 and j+1 < M and not visit[i-1][j] and not visit[i][j+1]: # 날개가 오른쪽 위쪽(case4)
		visit[i-1][j] = True
		visit[i][j+1] = True
		cur += material[i-1][j] + material[i][j+1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i-1][j] = False
		visit[i][j+1] = False
		cur -= material[i-1][j] + material[i][j+1]
		
	if i+1 < N and j+1 < M and not visit[i+1][j] and not visit[i][j+1]: # 날개가 오른쪽 아래쪽(case5)
		visit[i+1][j] = True
		visit[i][j+1] = True
		cur += material[i+1][j] + material[i][j+1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i+1][j] = False
		visit[i][j+1] = False
		cur -= material[i+1][j] + material[i][j+1]
	
	# 백트래킹	
	cur -= 2*material[i][j] # 중심칸의 강도만큼 다시 빼줌
	visit[i][j] = False # 방문 표시 제거
			
	return max_strength

N, M = list(map(int,sys.stdin.readline().split()))

material = []
for _ in range(N):
	material.append(list(map(int,sys.stdin.readline().split())))
	
print(makeBoomerang(0,N,M,material,[[False]*M for _ in range(N)],0,0))
