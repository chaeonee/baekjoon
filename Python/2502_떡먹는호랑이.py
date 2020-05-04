if __name__ == '__main__':
	D, K = list(map(int,input().split()))
	
	dp = [[1,0],[0,1]] # index 0: A의 계수, index 1: B의 계수
	d = 2
	while True:
		d += 1
		dp.append([dp[d-3][0]+dp[d-2][0],dp[d-3][1]+dp[d-2][1]]) # A와 B의 계수(피보나치 순열) 계산
		
		if d == D: # 해당 일수와 동일하면 계산 그만하고 루프 탈출
			break
		
	for i in range(1,K): # A를 1부터 증가시키면서 순서대로 대입해보고 조건에 맞는 A와 B 찾기
		if (K-i*dp[-1][0]) % dp[-1][1] == 0: # 해당 A값일 때, B의 값이 자연수인지 확인하기, 자연수라면 조건 만족!
			print(i) # A 출력
			print(int((K-i*dp[-1][0])/dp[-1][1])) # B 출력
			break
