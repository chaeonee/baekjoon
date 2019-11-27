def getDgree(n, x, y, matrix, visit, d, r):
	visit[x] = True
	
	vector = []
	for i in range(n):
		if matrix[x][i] == True and visit[i] == False: #만약 부모 관계이고 방문한 적 없다면
			if i == y: # 만약 원하는 y값(목적지)에 도달했으면 깊이를 return하고 끝
				r = d+1
				return r
			else: # 벡터에 추가
				vector.append(i)
				
	while vector: #bfs로 구현해도 되지만 현재의 깊이 계속적으로 반영 위해 재귀로 구현
		tmp = vector.pop()
		r = getDgree(n, tmp, y, matrix, visit, d+1, r)
	
	return r #목적지에 도달하지 않으면 -1이 계속 return될 것(만약 도달한 것이 있다면, 도달한 깊이 값 계속 return될 것)
	
if __name__ == "__main__":
	n = int(input())
	
	p = input().split()
	p = [int(i)-1 for i in p]
	
	m = int(input())
	
	matrix = [[False]*n for i in range(n)]
	for i in range(m):
		xy = input().split()
		xy = [int(i)-1 for i in xy]
		matrix[xy[0]][xy[1]] = True
		matrix[xy[1]][xy[0]] = True
	
	visit = [False]*n
	print(getDgree(n, p[0], p[1], matrix, visit, 0, -1))