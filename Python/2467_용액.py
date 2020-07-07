import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	sol = list(map(int,sys.stdin.readline().split()))
	
	p1 = 0 # 왼쪽 포인터
	p2 = N-1 # 오른쪽 포인터 (두 포인터가 양 끝을 가리키도록)
	result = [] # 두 용액의 특성값이 0과 가장 가까운 조합을 저장
	val = float('inf') # 특성값이 0과 가까우려면 절대값이 작은 값을 구해야 하므로 매우 큰 값으로 초기화
	while p1 < p2: # 왼쪽 포인터가 오른쪽 포인터보다 더 왼쪽에 있어야 수행
		s1 = sol[p1]
		s2 = sol[p2]
		if abs(s1 + s2) < val: # 두 용액을 섞었을 때 특성 값의 절대 값이 기존의 조합들보다 작으면
			val = abs(s1 + s2) # 특성값 기준 갱신
			result = [s1,s2] # result 갱신
			
		if s1 + s2 > 0: # 특성값의 합이 양수라면 -> 더 큰 값을 작은 쪽으로 이동시켜줘야 함
			p2 -= 1 # 오른쪽 포인터 1 감소
		elif s1 + s2 < 0: # 특성값의 합이 음라면 -> 더 작은 값을 큰 쪽으로 이동시켜줘야 함
			p1 += 1 # 왼쪽 포인터 1 증가
		else: # 0인 경우
			break # 더 이상 볼 필요 없음
		
	print(str(result[0])+" "+str(result[1]), end = '')
