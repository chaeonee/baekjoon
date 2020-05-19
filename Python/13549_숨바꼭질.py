import sys

if __name__ == '__main__':
	N, K = list(map(int,sys.stdin.readline().split()))
	
	q = [[N,0]] # bfs를 진행할 큐 ** priority queue를 이용해서 풀어봐야 할 듯...
	visit = [False]*100001 # 방문 여부 확인 배열
	visit[N] = True
	
	result = 0 # 최종적으로 걸린 시간
	while q:
		x, time = q.pop(0)
		
		if x == K: # 수빈이가 동생 위치에 도달하였다면
			result = time # 시간 저장 후 break
			break
		
		if 2*x <= 100000 and visit[2*x] == False: # 순간이동 먼저 넣어주어야 함 -> 시간이 덜 걸리기 때문
			q.append([2*x,time])
			visit[2*x] = True
		if x-1 >= 0 and visit[x-1] == False: # 한 칸 앞으로 전진
			q.append([x-1,time+1])
			visit[x-1] = True
		if x+1 <= 100000 and visit[x+1] == False: # 한 칸 뒤로 후진
			q.append([x+1,time+1])
			visit[x+1] = True
		
	print(result)
