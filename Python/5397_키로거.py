if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		S = input();
		
		first = [] # 커서 앞쪽에 있는 문자를 저장하기 위한 앞쪽 list(data 방향: 앞->뒤)
		second = [] # 커서 뒤쪽에 있는 문자를 저장하기 위한 뒤쪽 list(data 방향: 뒤->앞, pop 및 append를 용이하게 하기 위함)
		for s in S:
			if s == '<': # 커서 왼쪽 이동
				if first: # 커서가 맨 앞에 있을 때는 이동할 수 없음
					c = first.pop() # 앞쪽 list의 마지막 값을 뒤쪽 list의 첫 번째 값으로 넣기(뒤쪽 list의 첫 번째 값은 맨 뒤에 존재하므로 뒤쪽으로 append)
					second.append(c)
			elif s == '>': # 커서 오른쪽 이동
				if second: # 커서가 맨 뒤에 있을 때는 이동할 수 없음
					c = second.pop() # 뒤쪽 list의 첫 번째 값을 앞쪽 list의 마지막 값으로 넣기(뒤쪽 list의 첫 번째 값은 맨 뒤에 존재하므로 마지막 값 pop)
					first.append(c)
			elif s == '-': # 커서 왼쪽 문자 삭제
				if first: # 커서 왼쪽에 문자가 없을 때, 즉, 커서가 맨 앞쪽에 존재할 때는 삭제 불가
					first.pop() # 커서 앞쪽의 문자를 삭제하려면 앞쪽 list의 마지막 값을 삭제해야 함
			else: # 문자 삽입
				first.append(s) # 커서 앞쪽으로 문자를 삽입해야 하므로 앞쪽 list의 가장 뒤에 문자 삽입
				
          # 두 배열 순서대로 출력, 뒤쪽 list의 data의 방향은 뒤->앞 이므로 뒤부터 출력
		for i in range(len(first)):
			print(first[i], end='')
		for i in range(len(second),0,-1):
			print(second[i-1], end='')
		print()