if __name__ == '__main__':
	N = int(input())
	A = list(map(int,input().split()))
	
	dp = [1]*N # 현재 위치에서 가장 긴 감소하는 부분수열의 최대 길이 저장(자신의 길이는 항상 포함이므로 1로 초기화)
	for a in range(1,N):
		dp_max = 0 # 앞쪽 수들 중 가장 긴 부분수열의 길이 저장
		for i in range(a):
			if A[a] < A[i] and dp_max < dp[i]: # 감소하는 부분수열을 찾아야 하기 때문에 앞쪽 배열의 수가 현재 수보다 큰 것들 중 가장 긴 부분수열의 길이를 가지고 있는 수 찾기
				dp_max = dp[i]
		dp[a] += dp_max
	
	print(max(dp))
