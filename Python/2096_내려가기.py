import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	pre_score = [[0]*2 for _ in range(3)] # 이전까지의 최대 최소 score 담겨 있음
	score = [[0]*2 for _ in range(3)] # 현재까지의 최대 최소 score 담겨 있음
	
	arr = list(map(int,sys.stdin.readline().split()))
	for i in range(3):
		score[i] = [arr[i], arr[i]]
	pre_score = [[x1, x2] for x1, x2 in score] # 초기화
	
	for _ in range(1,N):
		arr = list(map(int,sys.stdin.readline().split()))
		for i in range(3):
			if i-1 >=0:
				if i+1 < 3: # 2열: 이전 scroe 1,2,3 열 중 최대, 최솟값 이용하여 계산
					score[i][0] = min(pre_score[i][0], pre_score[i+1][0], pre_score[i-1][0]) + arr[i]
					score[i][1] = max(pre_score[i][1], pre_score[i+1][1], pre_score[i-1][1]) + arr[i]
				else: # 3열: 이전 scroe 2,3 열 중 최대, 최솟값 이용하여 계산
					score[i][0] = min(pre_score[i][0], pre_score[i-1][0]) + arr[i]
					score[i][1] = max(pre_score[i][1], pre_score[i-1][1]) + arr[i]
					
			else:
				if i+1 < 3: # 1열: 이전 scroe 1,2 열 중 최대, 최솟값 이용하여 계산
					score[i][0] = min(pre_score[i][0], pre_score[i+1][0]) + arr[i]
					score[i][1] = max(pre_score[i][1], pre_score[i+1][1]) + arr[i]
		pre_score = [[x1, x2] for x1, x2 in score] # 다음 계산을 위해 pre_score 갱신
	
	s_min = float('inf')
	s_max = 0
	for i in range(3): # 구한 최대 최솟값들 중 최대 최소 구하기
		s_min = min(s_min,score[i][0])
		s_max = max(s_max,score[i][1])
		
	print("%d %d" %(s_max, s_min))
