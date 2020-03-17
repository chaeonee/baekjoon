if __name__ == '__main__':
	N = int(input())
	
  # 이친수는 피보나치 수열
	dp = [0]*N # dp를 이용하여 계산한 값을 저장할 배열
	for n in range(N):
		if n == 0 or n == 1: # 초기화
			dp[n] = 1
		else: # 피보나치 계산
			dp[n] = dp[n-1] + dp[n-2]
			
	print(dp[N-1])
