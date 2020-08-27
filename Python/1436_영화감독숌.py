if __name__ == '__main__':
	N = int(input())
	
	cnt = 0 # 시리즈의 순서
	num = 665 # 영화 제목에 들어갈 수
	while True: # 수 1씩 증가시키면서 영화 제목에 들어갈 수 인지 확인
		num += 1
		
		if '666' in str(num): # 해당 숫자에 '666'이 들어간다면
			cnt += 1 # 시리즈의 순서 1 증가(다음 시리즈의 순서 구하거나 멈추거나 할 수 있도록)
		
		if cnt == N: # 구하고자 하는 시리즈의 순서 번호라면
			break # 루프 탈출
		
	print(num)
