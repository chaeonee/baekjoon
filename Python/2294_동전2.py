if __name__ == '__main__':
	n,k = list(map(int,input().split()))
	
	coin = [] # 동전 종류를 담을 배열
	for _ in range(n):
		coin.append(input())
		
	coin = list(map(int, coin))
	
	dp = [float('inf')]*(k+1) # 사용할 동전의 최솟값을 담을 dp 배열 (무한대로 세팅해놓기), dp[i]는 가치 i를 만들 때 사용되는 최소 동전의 개수를 의미
	dp[0] = 0 # dp[0]은 0으로 초기화
	for c in coin:
		for i in range(c,k+1): # 동전의 가치보다 커야 동전을 사용할 수 있음
			dp[i] = min(dp[i],1+dp[i-c]) # 현재 동전을 1개 사용할 수 있고, 현재 가치에서 현재 동전 가치를 뺀만큼을 추가로 사용해야 함
               # 예를 들어 현재 만들고자 하는 가치가 8이고, 현재 동전의 가치가 5라면, 현재 동전 1개를 사용하고 8-5, 즉, 3만큼을 추가로 만들어야 함(이는 dp[3]의 값을 가져오면 됨)
				
	if dp[k] == float('inf'): # 배열 값이 무한대라면, 만들 수 없음을 의미
		print(-1) # -1 출력
	else: # 만들 수 있다면
		print(dp[k]) # dp[k]를 출력