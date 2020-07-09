import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	if N % 2 == 1: # 홀수일 때
		print(0) # 0 출력
	else: # 짝수일 때
		N = int(N/2) # 홀수의 경우 무시하기 위해 N/2개만 확인(0포함 N/2+1)
		
		dp = [0]*(N+1)
		dp[0] = 1 # dp[0] 1로 초기화(계산의 편의를 위해)
		for i in range(1,N+1):
			dp[i] = dp[i-1] * 3 # 이전 경우의 수 * 3(N이 2일 때, 경우의 수)
			
			for j in range(0,i-1): # 짝수 길이일 때로 나눌 수 없이 가운데를 가로지르는 경우(왼쪽에 존재하는 경우는 이전 dp에 포함되어 있지만 오른쪽에 포함되어 있는 경우는 계산해주어야 함)
				dp[i] += dp[j]*2 # 이전 경우의 수 * 2(가운데를 가로지르는 경우의 수)
			
		print(dp[N])
