if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		S = input()
		
		cnt = 0 # cnt = 0 이어야 짝이 맞는 것
		for s in S:
			if cnt < 0: # cnt가 음수라면 ')'와 짝이 맞는 '('가 없는 상황이므로 break
				break
			
			if s == '(': # '('일때는 1 증가
				cnt += 1
			else: # ')' 일때는 1 감소
				cnt -= 1
		
		if cnt == 0:
			print("YES")
		else:
			print("NO")
