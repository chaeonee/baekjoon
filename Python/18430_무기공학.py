import sys

def makeBoomerang(s, N, M, material, visit, cur, max_strength):
	if s >= N*M:
		max_strength = max(cur, max_strength)
		return max_strength
		
	max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
	
	i  = s // M
	j = s % M
	
	if visit[i][j]:
		return max_strength
	
	cur += 2*material[i][j]
	visit[i][j] = True
	
	if i+1 < N and j-1 >= 0 and not visit[i+1][j] and not visit[i][j-1]:
		visit[i+1][j] = True
		visit[i][j-1] = True
		cur += material[i+1][j] + material[i][j-1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i+1][j] = False
		visit[i][j-1] = False
		cur -= material[i+1][j] + material[i][j-1]
		
	if i-1 >= 0 and j-1 >= 0 and not visit[i-1][j] and not visit[i][j-1]:
		visit[i-1][j] = True
		visit[i][j-1] = True
		cur += material[i-1][j] + material[i][j-1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i-1][j] = False
		visit[i][j-1] = False
		cur -= material[i-1][j] + material[i][j-1]
		
	if i-1 >= 0 and j+1 < M and not visit[i-1][j] and not visit[i][j+1]:
		visit[i-1][j] = True
		visit[i][j+1] = True
		cur += material[i-1][j] + material[i][j+1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i-1][j] = False
		visit[i][j+1] = False
		cur -= material[i-1][j] + material[i][j+1]
		
	if i+1 < N and j+1 < M and not visit[i+1][j] and not visit[i][j+1]:
		visit[i+1][j] = True
		visit[i][j+1] = True
		cur += material[i+1][j] + material[i][j+1]
		max_strength = makeBoomerang(s+1,N,M,material,visit,cur,max_strength)
		visit[i+1][j] = False
		visit[i][j+1] = False
		cur -= material[i+1][j] + material[i][j+1]
		
	cur -= 2*material[i][j]
	visit[i][j] = False
			
	return max_strength

N, M = list(map(int,sys.stdin.readline().split()))

material = []
for _ in range(N):
	material.append(list(map(int,sys.stdin.readline().split())))
	
print(makeBoomerang(0,N,M,material,[[False]*M for _ in range(N)],0,0))
