if __name__ == '__main__':
	N,K = list(map(int,input().split()))
	
	visit = [-1]*100001 # 경로 및 방문 여부 체크
	queue = [N] # bfs를 위한 큐 정의(시작점 N으로 초기화)
	
	flag = False # 반복문 탈출을 위한 flag 사용
	d = -1
	while queue: # bfs 진행하여 최단 거리 구하기
		s = len(queue)
		
		d += 1
		for _ in range(s):
			n = queue.pop(0)
			
			if n == K: # 동생에게 도착하면 끝!
				flag = True
				break
            
               # 범위를 벗어나지 않고 방문한 적이 없으면 현재 위치 visit에 기록하여 나중에 경로 구할 수 있도록 			
			if n-1 >= 0 and visit[n-1] == -1:
				visit[n-1] = n
				queue.append(n-1)
			if n+1 <= 100000 and visit[n+1] == -1:
				visit[n+1] = n
				queue.append(n+1)
			if 2*n <= 100000 and visit[2*n] == -1:
				visit[2*n] = n
				queue.append(2*n)
				
		if flag == True:
			break
	
	result = [K] # 경로 저장을 위한 배열
	n = K
	while n != N: # visit에 저장되어 있는 값 보고 경로를 반대로 추적
		n = visit[n]
		result.append(n)
		
	print(d)
	while result: # 경로가 반대로 저장되어 있기 때문에 뒤에부터 경로 출력해야 함
		print(result.pop(),end=' ')