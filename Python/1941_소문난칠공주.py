import sys
from collections import deque
from itertools import combinations

def isConnected(comb, students): # 선택한 학생들이 칠공주가 될 수 있는지 확인
	check = [[False]*5 for _ in range(5)]
	for i in list(comb): # 선택된 학생들의 위치 True로 바꿔주기(학생들의 위치 확인 및 visit 역할할 것)
		check[int(i/5)][i%5] = True
	
	q = deque()
	q.append([int(comb[0]/5),comb[0]%5]) # 맨 처음 학생의 위치 queue에 삽입
	check[int(comb[0]/5)][comb[0]%5] = False # 방문했으므로 다시 방문할 필요 없음(없는 사람처럼 False로 바꿔주기)
	
	n = 0 # 연결된 학생들의 수(첫 번째 위치 기준)
	n_dasom = 0 # 선택된 이다솜파의 수
	dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상하좌우
	while q:
		x, y = q.pop()
		
		n += 1 # 연결된 학생 수 1 증가
		if students[x][y] == 'S': # 해당 학생이 이다솜파라면
			n_dasom += 1 # 선택된 이다솜파의 수 1 증가
			
		for dx, dy in dir: # 상하좌우 이동
			dx += x
			dy += y # 이동 좌표 계산
			if 0 <= dx < 5 and 0 <= dy < 5: # 범위 체크
				if check[dx][dy]: # 만약 선택된 학생이고 방문한 적(연결을 확인한 적)이 없다면
					check[dx][dy] = False # 방문 표시 후
					q.append([dx,dy]) # queue에 추가
		
	if n != 7 or n_dasom < 4: # 7명 중 한 명이라도 연결이 안 되어 있거나, 이다솜파가 4명 미만일 때
		return False # '소문난 칠공주' 결성 불가
		
	# 7명 모두 연결되어 있고 이다솜파가 4명 이상 구성되어 있다면 '소문난 칠공주' 결성 가능
	return True

if __name__ == '__main__':
	students = [list(sys.stdin.readline().rstrip()) for _ in range(5)]
	
	num = 0 # '소문난 칠공주'를 결성할 수 있는 모든 경우의 수
	n_student = [i for i in range(25)] # 학생들의 번호
	for x in list(combinations(n_student,7)): # 25명의 학생 중 7명을 뽑음
		if isConnected(x,students): # 뽑힌 학생들이 '소문난 칠공주'가 될 수 있는 조건을 만족한다면
			num += 1 # 경우의 수 1 증가
			
	print(num)
