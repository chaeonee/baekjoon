import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	rank = [1]*N # 나보다 덩치 큰 사람 없으면 내 등수 1위이기 때문에 모두 1등으로 초기화
	dungchi = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
	
	for i in range(N): # 순서대로 모든 조합 다 확인
		for j in range(N):
			if dungchi[i][0] < dungchi[j][0] and dungchi[i][1] < dungchi[j][1]: # 나보다 덩치 큰 사람이 몇 명인지 count
				rank[i] += 1
				
	for i in rank:
		print(i, end=' ')
