def getLCS(s1,s2,dp): # LCS를 구하기 위한 함수
	x = len(s2)
	y = len(s1)
	
	lcs = '' # LCS
	while x != 0 and y != 0: # LCS는 역으로 추적할 것임
		if s2[x-1] == s1[y-1]: # 만약 같은 문자를 만났다면
			lcs += s2[x-1] # LCS에 추가하고
			x -= 1
			y -= 1 # 대각선 위로 이동
		else: # 다른 문자라면 왼쪽 또는 위로 이동(왼쪽에 우선순위를 두었음)
			if dp[x][y] == dp[x][y-1]: # 왼쪽 이동
				y -= 1
			else: # 위로 이동
				x -= 1
	lcs = list(lcs)
	lcs.reverse()
	print(''.join(lcs)) # LCS를 반대로 탐색했기 때문에 뒤집어 주고 출력
	
def lenLCS(s1,s2): # LCS의 길이를 구하기 위한 함수
	len1 = len(s1)
	len2 = len(s2)
	
	dp = [[0]*(len1+1) for _ in range(len2+1)]
	
	for i in range(1,len2+1): # 첫 번째 행, 첫 번째 열은 0으로 고정(초기값) -> 1부터 시작
		for j in range(1,len1+1):
			if s1[j-1] == s2[i-1]: # 같은 문자라면
				dp[i][j] = dp[i-1][j-1] + 1 # 대각선 위의 값 + 1
			else: # 다른 문자라면
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) # 배열의 위 또는 왼쪽 값 중 큰 값 가져옴
	
	print(dp[len2][len1]) # 배열의 가장 오른쪽 아래에 있는 값이 LCS의 길이
	if dp[len2][len1] != 0: # LCS의 길이가 0일 때는 LCS를 출력하지 않아도 됨 -> LCS의 길이가 0이 아닐 때만 LCS 구하기
		getLCS(s1,s2,dp)
	
if __name__ == '__main__':
	s1 = input()
	s2 = input()
	
	lenLCS(s1,s2)
