def getSeries(N, M, num, d, result):
	if d == M:
		for r in result:
			print(r, end=' ')
		print()
		return
	
	for i in range(N):
		result.append(num[i])
		getSeries(N,M,num,d+1,result)
		result.pop()

if __name__ == '__main__':
	N, M = list(map(int,input().split()))
	num = list(set(list(map(int,input().split()))))
	num.sort()
	
	N = len(num)
	getSeries(N,M,num,0,[])
