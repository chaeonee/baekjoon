if __name__ == '__main__':
	N = int(input())
	top = list(map(int,input().split()))
	
	stack = [] # stack을 이용한 풀이를 위해 배열을 stack처럼 사용할 것
	for t in range(len(top)):
		while stack and top[t] > top[stack[-1]]: # 현재 탑의 높이보다 낮은 앞쪽 탑들은 모두 pop(현재 탑이 가리기 때문에 더 이상 레이저 신호 받을 수 없음)
			stack.pop()
		
		if stack: # stack이 비어있지 않으면
			print(stack[-1]+1,end=' ') # 맨 뒤에 위치하는 탑(현재 탑보다 높으면서 현재 탑과 가장 가까운 탑)이 현재 레이저 신호를 받을 것
		else: # stack이 비어있으면
			print(0,end=' ') # 내 앞쪽에 나보다 높은 탑 존재하지 않기 때문에, 레이저 신호 받아줄 탑 없음
		
		stack.append(t) # 다음 탑 계산을 위해 현재 탑의 index push
