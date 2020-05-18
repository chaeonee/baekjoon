import sys

if __name__ == '__main__':
	N, S, M = list(map(int,sys.stdin.readline().split()))
	V = list(map(int,sys.stdin.readline().split()))
	V = [0]+V # index 1부터 시작하기 위해 뒤로 밀어줌
	
	dp = [[False]*(M+1) for _ in range(N+1)] # 현재 곡에서 가능한 크기의 볼륨이면 true, 아니면 false
	dp[0][S] = True # 시작 값 true로 초기화
	for i in range(1,N+1): # 1부터 시작
		for j in range(M+1): # 0~M
			if dp[i-1][j]: # 이전 곡에서 가능한 볼륨 크기라면, 주어진 볼륨의 차이만큼 더하고 빼봐야 함
				if j+V[i] <= M: # 더한 것이 범위 내에 존재한다면
					dp[i][j+V[i]] = True # 더한 볼륨의 값 true로 바꿔줌
				if j-V[i] >= 0: # 뺀 것이 범위 내에 존재한다면
					dp[i][j-V[i]] = True # 뺀 볼륨의 값 true로 바꿔 줌
	
	flag = False # 마지막 곡을 연주할 수 있는지 여부
	for i in range(M,-1,-1): # 최대 값 구해야 하므로 큰 볼륨부터 확인(가장 처음 만나는 ture 값의 i가 최대 볼륨이 됨)
		if dp[N][i]: # true를 만나면
			flag = True # 마지막 곡 연주 가능
			print(i) # 최대 볼륨 출력
			break
		
	if not flag: # 마지막 곡 연주 못하는 경우
		print(-1) # -1출력
