import sys
import heapq as h

if __name__ == '__main__':
	n = int(sys.stdin.readline())
	bamboo = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
	day = [[1]*n for _ in range(n)] # 해당 좌표에서 살 수 있는 일수(현재 좌표의 대나무만 먹을 수 있는 경우인 1로 초기화)
	q = [] # priority queue를 위한 배열
	for i in range(n):
		for j in range(n):
			h.heappush(q, (-bamboo[i][j],[i,j])) # 대나무의 수가 큰 것부터 내림차순으로 좌표를 정렬하기 위해 대나무의수*-1로 정렬 값 설정(heapq를 사용하면 오름차순으로 정렬하기 때문)
	
	K = 0 # 판다가 최대한 살 수 있는 일수
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	while q:
		x, y = h.heappop(q)[1] # 대나무의 수가 많은 좌표부터 pop하여 탐색
		
		for dx, dy in dir: # 상하좌우
			dx += x
			dy += y # 좌표 값 계산
			if 0 <= dx < n and 0 <= dy < n: # 범위 체크
				if bamboo[x][y] < bamboo[dx][dy]: # 이동할 좌표가 현재 좌표보다 더 많은 대나무를 가지고 있을 경우
					day[x][y] = max(day[x][y], day[dx][dy]+1) # 이동할 좌표의 수명 + 1과 현재 좌표의 수명을 비교하여 더 큰 값 저장
		K = max(K, day[x][y]) # 판다가 최대한 살 수 있는 일수 저장을 위한 비교
		
	print(K)
