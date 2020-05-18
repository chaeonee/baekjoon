import sys

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	candy = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
	
	dp = [[0]*(M+1) for _ in range(N+1)] # (1,1)부터 시작하는 dp 배열 만들기(범위 체크 할 필요 없도록 하려고)
	for i in range(1,N+1):
		for j in range(1,M+1): # 위, 왼쪽, 왼쪽 대각선 위 중 최댓값 구하여 현재 위치에 존재하는 사탕의 수와 더해 줌
			dp[i][j] = max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + candy[i-1][j-1] # 사탕의 수는 (0,0)부터 시작하기 때문에 1씩 빠진 index에서 값을 가져와야 함
			
	print(dp[N][M])
