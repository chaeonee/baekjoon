import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	flower = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
	flower = sorted(flower, key = lambda x: (x[0], x[1])) # 시작 날짜로 sorting
	
	cnt = 0 # 선택한 꽃의 수
	idx = 0
	s_month, s_day = 3, 1 # 기준 날짜 3월 1일
	while idx < N and (s_month < 11 or (s_month == 11 and s_day <= 30)): # 꽃이 지는 날짜가 11월 30일 이후 or 모든 꽃 확인하면 while문 탈출
		m, d = 0, 0 # 기준 날짜보다 먼저 피는데 가장 늦게 지는 애들 찾아서 월, 일 담을 것(m,d에)
		flag = False # 기준 날짜보다 먼저 피는 꽃이 있는지 여부
		for i in range(idx, N): # 현재 index부터 확인(이전 인덱스는 이미 핀 꽃 -> 이미 확인 했음, 확인할 필요 없음)
			if flower[i][0] > s_month or (flower[i][0] == s_month and flower[i][1] > s_day): # 현재 기준보다 늦게 피는 꽃들을 만나면 break(이 이후에 있는 꽃들도 현재 기준보다 늦게 개화할테니까)
				break
				
			if flower[i][2] > m or (flower[i][2] == m and flower[i][3] > d): # 현재 기준보다 먼저 개화하는 꽃들 중 가장 늦게 지는 애들 고를 것
				flag = True # 기준 날짜보다 먼저 피는 꽃이 있으므로 true
				
				idx = i+1 # 현재 인덱스까지 확인했음, 다음 인덱스부터 보면 됨(이전 인덱스들은 현재 인덱스의 꽃보다 일찍 진다는 뜻이니까)
				m = flower[i][2]
				d = flower[i][3] # 가장 늦게 지는지 확인하는 기준 갱신
		if flag: # 기준 날짜보다 먼저 피는 꽃이 있으면
			cnt += 1 # 꽃 하나 선택한 것이므로 꽃 숫자 1증가
			s_month = m
			s_day = d # 기준 날짜 갱신
		
		else: # 기준 날짜보다 먼저 피는 꽃 없다는 것은 중간에 꽃이 피어있지 않은 날이 존재하게 된다는 뜻
			break # 조건 만족하지 않으므로 더이상 볼 필요 없음
			
	if s_month > 11 or (s_month == 11 and s_day > 30): # 꽃이 11월 30일 이후까지 피어있다면
		print(cnt) # 선택한 꽃의 수 출력
	else: # 아니라면
		print(0) # 0 출력
