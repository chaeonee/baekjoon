if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		S = input()
		
		bracket = [] # 괄호를 담을 배열(stack으로 사용될 것임)
		for s in S:
			if s == '(': # '('라면 배열에 추가
				bracket.append('(')
			else: # ')'인데
				if len(bracket) == 0: # 짝이 되어줄 '('가 없다면, 배열에 ')'를 추가하고 break
					bracket.append(')')
					break
				bracket.pop() # 아니라면 배열에 있는 '(' pop
		
		if len(bracket) == 0: # bracket의 크기가 0이어야 모든 짝이 맞는 것
			print("YES")
		else: # 아닌 경우: 1) ')'와 짝이 될 '('가 없어서 '('가 하나 들어가 있는 상황, 2) '('가 남은 상황
			print("NO")
