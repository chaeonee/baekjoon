def getSum(N,S,s,arr,arr_sum,n_sum):
	for i in range(s,N):
		arr_sum += arr[i]
		if arr_sum == S: # 합이 S와 동일하면
			n_sum += 1 # 경우의 수 1 증가
		n_sum = getSum(N,S,i+1,arr,arr_sum,n_sum) # 방문 표시 하지 않고 다음 index부터 보도록 하면 됨(뒤로만 보게)
		arr_sum -= arr[i]
	
	return n_sum

if __name__ == '__main__':
	N, S = list(map(int,input().split()))
	arr = list(list(map(int,input().split())))
	
	n_sum = getSum(N,S,0,arr,0,0)
	print(n_sum)
