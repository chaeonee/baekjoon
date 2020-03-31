if __name__ == '__main__':
	S1 = input()
	S2 = input()
	
	dp = [[0]*(len(S1)+1) for _ in range(len(S2)+1)] # LCS의 길이를 구하기 위한 dp 배열(각 문자열의 길이 + 1을 행 열로 하는 2차원 배열)
	
	for i in range(1,len(S2)+1):
		for j in range(1,len(S1)+1):
			if S2[i-1] == S1[j-1]: # 같은 문자라면
				dp[i][j] = dp[i-1][j-1] + 1 # 대각선 위의 값 + 1
			else: # 다른 문자라면
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]) # 배열의 위, 왼쪽 값 중 큰 값 가져오기
	
	print(dp[len(S2)][len(S1)]) # dp 배열의 가장 오른쪽 아래 값이 최종 LCS의 길이
