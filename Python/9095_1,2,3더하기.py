def getSum(n, cnt):
	if n == 0: # n이 0이되면 1,2,3으로 이루어진 합 완성된 것이므로 cnt 1증가 후 return
		return cnt+1
		
	for i in range(1,4):
		if n-i >= 0: # n-i가 0보다 작으면 모두 더했을 때 n보다 커지기 때문에 조건 추가
			cnt = getSum(n-i,cnt)
			
	return cnt
	
if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		n = int(input())
		
		print(getSum(n,0))
