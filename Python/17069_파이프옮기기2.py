import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	house = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
	
	dp = [[[0]*(N) for _ in range(N)] for i in range(3)] # 각 좌표 값이 가로 세로 대각선의 상태일 때의 이동 가능 경로의 수 (각각) 저장
	
	dir = [[0,1],[1,0],[1,1]] # 가로, 세로, 대각선 이동
	idx_dir = [[0],[1],[0,1]] # 가로, 세로, 대각선일 때, 이동할 수 있는 방향의 index(0:가로, 1: 세로 / 모든 경우에 대각선 이동이 가능하므로 제외)
	
	dp[0][0][1] = 1 # 초기 값 설정
	for x in range(N): # x좌표
		for y in range(N): # y좌표
			for d in range(3): # 이동 전 방향
				for i in idx_dir[d]: # 해당 방향(d)일 때 가능한 방향 index
					dx, dy = x+dir[i][0], y+dir[i][1] # 이동할 좌표 계산
					if dx < N and dy < N and house[dx][dy] == 0: # 좌표가 범위 내에 존재하고, 새로운 벽지가 아닐 경우
						dp[i][dx][dy] += dp[d][x][y] # 이전 경로의 값(이동 전 방향)을 현재 경로(이동 후 방향)에 추가(방향 고려해야 함)
						
				if x+1 < N and y+1 < N: # 대각선 이동 고려, 범위 체크
					if house[x+1][y] == 1 or house[x][y+1] == 1 or house[x+1][y+1] == 1: # 주변의 값 중 새로운 벽지가 존재한다면(문제의 정의)
						continue # 아무 것도 수행하지 않고 건너 뜀
				dx, dy = x+dir[2][0], y+dir[2][1] # 이동할 좌표 계산(위의 조건문에 걸리지 않았다면)
				if dx < N and dy < N: # 범위 체크
					dp[2][dx][dy] += dp[d][x][y] # 이전 경로의 값(이동 전 방향)을 현재 경로(대각선 방향)에 추가(방향 고려해야 함)

	print(dp[0][N-1][N-1]+dp[1][N-1][N-1]+dp[2][N-1][N-1]) # 맨 오른쪽 아래의 좌표가 최종 목적지 이들이 가로, 세로, 대각선 상태일 때 가능한 경로의 값을 모두 더해주어야 가능한 모든 경로의 값이 됨
