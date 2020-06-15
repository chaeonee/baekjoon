import sys
input = sys.stdin.readline

def doAvoid(N, school, teacher): # 선생님의 감시를 피할 수 있는지 확인하기 위한 함수
	for x, y in teacher: # 각 선생님들 위치에서 감시할 수 있는 학생이 있는지 확인
		flag = True # 감시를 피할 수 있는지 여부
		
		i = 1
		while x+i < N and flag == True: # 아래 확인
			if school[x+i][y] == 'O': # 벽을 만나면 더 아래쪽은 볼 수 없음
				break
			elif school[x+i][y] == 'S': # 학생을 발견했다면
				flag = False # 감시 피하기 실패
				break
			
			i+= 1
			
		i = 1
		while x-i >= 0 and flag == True: # 위 확인
			if school[x-i][y] == 'O': # 벽을 만나면 더 윗쪽은 볼 수 없음
				break
			elif school[x-i][y] == 'S': # 학생을 발견했다면
				flag = False # 감시 피하기 실패
				break
			
			i+= 1
			
		i = 1
		while y+i < N and flag == True: # 오른쪽 확인
			if school[x][y+i] == 'O': # 벽을 만나면 그 이상은 볼 수 없음
				break
			elif school[x][y+i] == 'S': # 학생을 발견했다면
				flag = False # 감시 피하기 실패
				break
			
			i+= 1
			
		i = 1
		while y-i >= 0 and flag == True: # 왼쪽 확인
			if school[x][y-i] == 'O': # 벽을 만나면 그 이상은 볼 수 없음
				break
			elif school[x][y-i] == 'S': # 학생을 발견했다면
				flag = False # 감시 피하기 실패
				break
			
			i+= 1
		
		if not flag: # 감시를 피할 수 없는 경우 존재한다면 바로 반복문 탈출 후 함수 종료
			break
		
	return flag
	
def chooseWall(N, n_wall, school, teacher, flag): # 3개의 장애물의 위치를 선택하기 위한 함수
	if n_wall == 3: # 장애물의 위치 3개 모두 선택 했고
		if doAvoid(N, school, teacher): # 현재 위치에 장애물이 있을 때 선생님의 감시를 피할 수 있다면
			return True # True return
		return False # 아니라면 False return
	
	for i in range(N):
		for j in range(N):
			if school[i][j] == 'X': # 아무 것도 없는 곳에만 장애물 놓을 수 있기 때문에 아무 것도 없는 곳인지 확인
				school[i][j] = 'O' # 장애물 설치
				flag = chooseWall(N, n_wall+1, school, teacher, flag) # 장애물 수 하나 증가시킨 후 재귀
				school[i][j] = 'X' # 백트래킹(장애물 제거)
				
			if flag: # 선생님의 감시 피할 수 있는 경우 발견했다면
				return flag # flag return 하며 함수 종료
				
	return flag

if __name__ == '__main__':
	N = int(input())
	school = [input().split() for _ in range(N)]
	
	teacher = []
	for i in range(N):
		for j in range(N):
			if school[i][j] == 'T':
				teacher.append([i,j]) # 선생님의 위치 좌표 저장
				
	flag = chooseWall(N,0,school,teacher,False)
	
	if flag: # 선생님의 감시를 피할 수 있다면
		print("YES") # YES 출력
	else: # 아니라면
		print("NO") # NO 출력
