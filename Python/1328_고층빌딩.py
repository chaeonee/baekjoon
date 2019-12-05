if __name__ == '__main__':
	I = list(map(int,input().split()))
	N = I[0]
	L = I[1]
	R = I[2]
	
	dp = [[[0]*(N+1) for _ in range(N+1)] for __ in range(N+1)] #index 1부터 시작하기 위함
	dp[1][1][1] = 1 # 초기 값 설정
	
	"""
	n-1개의 건물이 있을 때, 높이 1인 건물을 추가한다고 생각해보기(1~n-1 건물 배열과 2~n 건물 배열 같음, 크기가 1씩 커진 것 빼고는)
	: 추가할 수 있는 경우의 수는 n
	1) 맨 앞에 추가: 왼쪽에서 봤을 때의 높이 1증가 (1개)
	2) 맨 뒤에 추가: 오른쪽에서 봤을 때의 높이 1증가 (1개)
	3) 나머지: 변화 없음 (n-2개)
	"""
     
	flag = False # 구하고자 하는 값을 계산했는지 여부를 체크하는 flag
	for n in range(2,N+1):
		if flag == True: # 구하고자 하는 값을 구했으면 더 이상 계산할 필요가 없기 때문에 for문에서 탈출
			break
		for l in range(1,n+1):
			for r in range(1,n+1):
				# 3),1),2) 순서로 계산되어 있음
				dp[n][l][r] = (dp[n-1][l][r]*(n-2) + dp[n-1][l-1][r] + dp[n-1][l][r-1])%1000000007
				if(n == N and l == L and r == R):
					flag = True
					
	print(dp[N][L][R]%1000000007)