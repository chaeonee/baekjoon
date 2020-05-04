if __name__ == '__main__':
	T = 0 # 몇 번째 루프인지 세기 위함
	while True:
		S = input()
		if S[0] == '-': # 만약 '-'가 1개 이상 입력되는 경우
			break # 루프 탈출(종료)
		
    		T += 1
    
		cnt = 0 # 안정적인 문자열을 만들기 위한 연산 수
		stack = [] # 여는 괄호 '{'를 담기 위한 stack
		for s in S:
			if s == '{': # 여는 괄호일 때
				stack.append('{') # stack에 추가
			else: # 닫는 괄호이고
				if len(stack) == 0: # stack이 비어있을 때 -> 짝이 되는 여는 괄호 없다는 뜻이므로 닫는 괄호를 여는 괄호로 바꿔주기
					stack.append('{') # 여는 괄호로 바꿨으므로 stack에 추가하고
					cnt += 1 # 연산 1증가
				else: # stack이 비어있지 않다면
					stack.pop() # stack안의 여는 괄호 하나 제거
		
		if len(stack) != 0: # 문자열 모두 탐색했을 때, 안정적인 문자열이라면 stack에 남는 문자열 없어야 함 남아있는 경우는 여는 괄호가 더 많다는 것
			cnt += int(len(stack)/2) # 주어진 괄호는 짝수이므로 남아있는(짝을 이루지 못한) 괄호 역시 짝수일 것 이들끼리 짝을 이루게 하려면 남아있는 여는 괄호의 절반을 닫는 괄호로 바꿔주어야 함 -> stack에 남아있는 괄호의 수 절반만큼 연산 수행
			
		print(str(T)+'. '+str(cnt))
