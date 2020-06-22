import sys
input = sys.stdin.readline

if __name__ == '__main__':
	n, m = list(map(int,input().split()))
	arr = [list(map(int,input().rstrip())) for _ in range(n)]
	
	square = [[0]*m for _ in range(n)] # 좌표 값을 오른쪽 아래로 하는 정사각형의 최대 변의 길이
	
	max_len = 0 # 최대 변의 길이
	for i in range(m): # 초기화
		if arr[0][i]: # arr 값이 1일 때,
			max_len = 1 # 최대 변의 길이도 1로 갱신
			square[0][i] = 1 # 변의 길이 1(현재 좌표만 포함되는 정사각형)
			
			
	for i in range(1,n):
		for j in range(m):
			if not arr[i][j]: # arr 값이 0이라면 정사각형 만들 수 없음
				continue
			
			if not j: # j값이 0일 때,
				square[i][j] = 1 # 현재 좌표만 포함된 정사각형만 만들 수 있음 -> 따라서 최대 변의 길이 1
				continue
			
			# 현재 좌표의 값이 1일 때
			if not arr[i-1][j] or not arr[i][j-1] or not arr[i-1][j-1]: # 현재 좌표의 위, 왼쪽, 대각선 위 중 하나라도 값이 0인 좌표가 존재할 때
				square[i][j] = 1 # 현재 좌표만 포함하는 정사각형만 가능(변의 길이 1)
				
			else: # 아니라면 
				square[i][j] = min(square[i-1][j], square[i][j-1], square[i-1][j-1]) + 1 # 현재 좌표의 위, 왼쪽, 대각선 위의 값 중 최솟값 + 1이 현재 좌표에서 만들 수 있는 정사각형의 최대 변의 길이(정사각형 범위에 포함되는 모든 값이 1이려면, 이들의 최솟값을 취해야 함 -> 큰 값을 취하게 되면 작은 값을 가지는 애들 쪽에는 값이 0인 부분 존재할 것)
				
			max_len = max(max_len, square[i][j]) # 변의 최댓값 갱신
			
	print(max_len**2) # 변의 최댓값 구했기 때문에 넓이의 최댓값 구하기 위해서는 제곱해주어야 함
