if __name__ == '__main__':
	S = input()
	
	s_open = 0 # 레이저 영향권에 있는 막대기들의 수
	cnt = 0 # 전체 막대기의 수
	flag = False # 레이저인지 막대기인지 구별하기 위한 flag True이면 레이저
	for s in S:
		if s == '(':
			flag = True # 일단 레이저일 가능성 있으니까 True로 바꾸기
			s_open += 1 # 막대기일 가능성 있으니까 영향권에 있는 막대기의 수 1 증가
			cnt += 1 # 막대기일 수 있으니까 막대기의 수도 1 증가
		else: # 닫히는 괄호일 경우
			s_open -= 1 # 막대기라면 막대기가 하나 줄어드는 것이므로 1 줄여야 하고, 레이저라면 1 증가 시켰던 막대기를 줄여야 함으로 1 줄여야 함
			if flag == True: # 레이저
				cnt -= 1 # 증가시켰던 막대기 1 감소시켜야 함(레이저이니까)
				cnt += s_open # 영향권에 있는 막대기만큼 총 막대기의 수 증가됨(레이저가 자르니까)
			flag = False # flag를 False로 바꿔 레이저 아님을 표시
				
	print(cnt)
