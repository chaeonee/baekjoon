import sys

if __name__ == '__main__':
	PPAP = input()
	
	stack = []
	for i in PPAP:
		stack.append(i) # 일단 문자열 추가
		
		# PPAP인지 확인해야 하므로, 문자열이 4개 이상일 때부터 확인
		if len(stack) >= 4 and stack[-4:] == ['P', 'P', 'A', 'P']: # 가장 끝에 있는 문자열 4개가 PPAP라면
			for _ in range(3):
				stack.pop() # P 하나 남기고 모두 pop(4개 pop하고 P 한 개 넣는 것과 같음)
		
	print("PPAP" if len(stack) == 1 and stack[0] == 'P' else "NP") # stack에 P 하나만 남아있으면 PPAP 문자열, 아니라면 PPAP 문자열이 아니므로 NP 출력
