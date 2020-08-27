import sys

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	board = [list(sys.stdin.readline().rstrip()) for _ in range(N)]
	
	num = float('inf') # 다시 칠할 체스판 칸의 수 중 최솟값을 저장
	for x in range(N-7):
		for y in range(M-7): # x와 y는 체스판 왼쪽 위의 좌표(8*8 크기의 체스판을 만들어야 하기 때문에 시작점 뒤에 최소 7칸은 존재해야 함)
			tmp = 0 # 현재 좌표를 기준으로 했을 때, 다시 칠할 체스판 칸의 수
			for i in range(x,x+8):
				if i % 2 == 0: # 짝수 행이라면
					col = 'W' # 흰색으로 시작
				else: # 홀수 행이라면
					col = 'B' # 검정색으로 시작
					
				for j in range(y,y+8):
					if board[i][j] != col: # 체스판의 현재 칸의 색이 원래 칠해져야 하는 색과 다른 색이면
						tmp += 1 # 다시 칠하기
						
					# 색을 번갈아가면서 써야하기 때문에
					if col == 'W': # 해당 칸의 색이 흰색이면
						col = 'B' # 다음 칸은 검정색으로 바꿔줘야 함
					else: # 해당 칸의 색이 검정색이면
						col = 'W' # 다음 칸은 흰색으로 바꿔줘야 함
			num = min(num,tmp) # 다시 칠해야 하는 체스판 칸의 수의 최솟값 갱신
						
			tmp = 0 # 현재 좌표를 기준으로 했을 때, 다시 칠할 체스판 칸의 수
			for i in range(x,x+8):
				if i % 2 == 0: # 짝수 행이라면
					col = 'B' # 검정색으로 시작
				else: # 홀수 행이라면
					col = 'W' # 흰색으로 시작
					
				for j in range(y,y+8):
					if board[i][j] != col: # 체스판의 현재 칸의 색이 원래 칠해져야 하는 색과 다른 색이면
						tmp += 1 # 다시 칠하기
						
					# 색을 번갈아가면서 써야하기 때문에
					if col == 'W': # 해당 칸의 색이 흰색이면
						col = 'B' # 다음 칸은 검정색으로 바꿔줘야 함
					else: # 해당 칸의 색이 검정색이면
						col = 'W' # 다음 칸은 흰색으로 바꿔줘야 함
			num = min(num,tmp) # 다시 칠해야 하는 체스판 칸의 수의 최솟값 갱신
	
	print(num)
