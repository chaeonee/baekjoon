if __name__ == '__main__':
	T = int(input())
	
	for _ in range(T):
		n = int(input())
		sticker = []
		for __ in range(2):
			sticker.append(list(map(int,input().split())))
		
          # 0은 현재 값으로 초기화, 1은 대각선 합 또는 현재 값으로 초기화
		score = [[0]*n for __ in range(2)]
		score[0][0] = sticker[0][0]
		score[1][0] = sticker[1][0]
		score[0][1] = max(sticker[1][0]+sticker[0][1],sticker[0][1])
		score[1][1] = max(sticker[0][0]+sticker[1][1],sticker[1][1])
		
          # 대각선 한 칸 위, 대각선 두 칸 위 중 최댓값 더해주기 (나머지 가능한 이전 값들은 이미 계산되어진 것)
		for i in range(2,n):
			score[0][i] = sticker[0][i] + max(score[1][i-1],score[1][i-2])
			score[1][i] = sticker[1][i] + max(score[0][i-1],score[0][i-2])
			
		print(max(score[0][n-1],score[1][n-1]))