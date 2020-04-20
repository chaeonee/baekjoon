if __name__ == '__main__':
	N, M = list(map(int,input().split()))
	
	singer = [[0,[]] for _ in range(N)] # 가수들의 정보, index 0: indegree의 수(바로 이전에 꼭 출연해야하는 가수들의 수), index 1: 바로 다음에 출연할 수 있는 가수들 리스트
	for _ in range(M):
		tmp = list(map(int,input().split()))
		for i in range(2,tmp[0]+1):
			singer[tmp[i-1]-1][1].append(tmp[i]-1)
			singer[tmp[i]-1][0] += 1
	
	result = [] # 출연 순서대로 담을 배열
	while True:
		flag = False # 출연 가능한 가수 존재하는지 여부
		for n in range(N):
			if singer[n][0] == 0: # indegree가 0이면 바로 이전에 꼭 출연해야 하는 가수들이 없기 때문에 출연 가능
				flag = True # 출연 가능한 가수 존재로 바꾸고
				singer[n][0] -= 1 # 방문 표시를 위함(indegree를 -1로 바꿔줌으로써)
				result.append(n+1) # 출연 리스트에 추가
				
				for s in singer[n][1]: # 현재 가수가 출연했으므로, 바로 다음에 출연할 수 있는 가수들의 indegree를 1씩 감소시켜 줌
					singer[s][0] -= 1
				break
		if flag == False: # 더이상 출연할 수 있는 가수 없으면 break
			break
	
	if len(result) == N: # 출연 가수들의 수가 전체 가수들의 수와 일치하면
		for r in result: # 출연 리스트 출력
			print(r)
	else: # 모두가 출연할 수 없다면
		print(0) # 0 출력
