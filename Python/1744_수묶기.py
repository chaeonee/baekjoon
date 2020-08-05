import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline().rstrip())
	
	pos = [int(sys.stdin.readline().rstrip()) for _ in range(N)]
	pos.sort() # 입력 받은 수 오름차순으로 정렬
	
	idx = 0 # 양수와 음수 나누기 위한 인덱스(가장 작은 양수를 가리킬 것)
	for i in range(N):
		if pos[i] > 0:
			idx = i
			break
	neg = pos[:idx] # 0을 포함한 음수 담은 배열(오름 차순 정렬)
	pos = pos[idx:] # 양수 담은 배열(오름 차순 정렬)
	
	sum = 0 # 합의 최대값
	while neg: # 음수 배열이 빌 때까지
		tmp = neg.pop(0) # 절대값이 가장 큰(실제로는 가장 작은) 수부터 pop
		if neg: # 비어 있지 않다면
			tmp *= neg.pop(0) # 하나 더 pop해서 곱해준 후
		sum += tmp # 합에 더해 주기
	
	while pos: # 양수 배열이 빌 때까지
		tmp = pos.pop() # 절대값이 가장 큰(실제로도 가장 큰) 수부터 pop
		if tmp == 1: # pop한 수가 1이라면
			sum += 1 # 묶지 않고 바로 sum에 더해주고
			continue # 다음 수 pop하러
		
		if pos: # 비어 있지 않다면
			if pos[-1] == 1: # pop할 예정인 수가 1이라면
				tmp += pos.pop() # 묶지 않고 더해주기
			else: # 아니라면
				tmp *= pos.pop() # 묶어서 곱한 후
		sum += tmp # 합에 더해주기

	print(sum) # 최종 최대 합 출력
