if __name__ == '__main__':
	F, S, G, U, D = list(map(int,input().split()))
	
	floor = [False]*F # 건물 층에 방문했는지 여부
	
	cur = S-1 # 현재 층의 위치
	floor[cur] = True # 현재 층 위치 방문 표시
	
	cnt = 0 # 버튼을 몇 번 눌렀는지
	flag = True # 목적지에 도착할 수 있는지 없는지 여부를 나타낸 변수
	while(True):
		if cur == G-1: # 목적지에 도착하면 루프 탈출
			break
		
		if cur < G-1: # 목적지가 현재 위치보다 더 위에 있다면
			if cur+U < F and floor[cur+U] == False: # 먼저 위로 이동할 수 있는 지 확인
				cur = cur+U # 현재 위치 변경
				floor[cur] = True # 방문 표시
				cnt += 1 # 버튼 누른 횟수 1증가
			elif cur-D >= 0 and floor[cur-D] == False: # 위로 올라갈 수 없다면 아래로 갈 수 있는지 확인
				cur = cur-D # 현재 위치 변경
				floor[cur] = True # 방문 표시
				cnt += 1 # 버튼 누른 횟수 1 증가
			else: # 위, 아래 모두 이동할 수 없다면
				flag = False # 목적지에 갈 수 없음 표시 후 반복문 탈출
				break
		
		else: # 목적지가 현재 위치보다 더 아래에 있다면
			if cur-D >= 0 and floor[cur-D] == False: # 먼저 아래로 이동할 수 있는 지 확인
				cur = cur-D # 현재 위치 변경
				floor[cur] = True # 방문 표시
				cnt += 1 # 버튼 누른 횟수 1증가
			elif cur+U < F and floor[cur+U] == False: # 아래로 내려갈 수 없다면 위로 갈 수 있는지 확인
				cur = cur+U # 현재 위치 변경
				floor[cur] = True # 방문 표시
				cnt += 1 # 버튼 누른 횟수 1증가
			else: # 위, 아래 모두 이동할 수 없다면
				flag = False # 목적지에 갈 수 없음 표시 후 반복문 탈출
				break
			
	if flag == False: # 목적지에 갈 수 없다면
		print("use the stairs")
	else: # 목적지에 도착했다면
		print(cnt) # 버튼 누른 횟수 출력
