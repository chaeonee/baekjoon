def getSeries(N, M, num, s, d, result):
	if d == M:
		for r in result:
			print(r, end=' ')
		print()
		return
	
	pre_num = -1
	for i in range(s,N):
		if num[i] == pre_num:
			continue
		pre_num = num[i]
		
		result.append(num[i])
		getSeries(N,M,num,i+1,d+1,result)
		result.pop()

if __name__ == '__main__':
	N, M = list(map(int,input().split()))
	num = list(map(int,input().split()))
	num.sort()
	
	getSeries(N,M,num,0,0,[])
