def calNum(N,A,s,oper,now,r_max,r_min):
	if s == N: # 최대값 최소값 갱신
		r_max = max(now,r_max)
		r_min = min(now,r_min)
		
		return r_max, r_min
		
	for i in range(4):
		if oper[i] > 0: # 사용가능한 연산자 1개일 때
			oper[i] -= 1 # 현재 사용할 연산자의 수 1감소
			if i == 0: # 덧셈
				r_max, r_min = calNum(N,A,s+1,oper,now+A[s],r_max,r_min)
			elif i == 1: # 뺄셈
				r_max, r_min = calNum(N,A,s+1,oper,now-A[s],r_max,r_min)
			elif i == 2: # 곱셈
				r_max, r_min = calNum(N,A,s+1,oper,now*A[s],r_max,r_min)
			else: # 나눗셈
				r_max, r_min = calNum(N,A,s+1,oper,int(now/A[s]),r_max,r_min)
			oper[i] += 1 # 백트래킹 위해 원상복구
			
	return r_max, r_min

if __name__ == '__main__':
	N = int(input())
	A = list(map(int,input().split()))
	oper = list(map(int,input().split()))
	
	r_max, r_min = calNum(N,A,1,oper,A[0],float('-inf'),float('inf'))
	
	print(r_max)
	print(r_min)
	
