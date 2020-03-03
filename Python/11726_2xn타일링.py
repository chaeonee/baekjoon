if __name__ == '__main__':
	n = int(input())
	arr = [0] * n
	
  	# dp 또는 재귀로 풀기 f(n) = f(n-1) + f(n-2)
	arr[0] = 1
	if n > 1:
		arr[1] = 2
		
		for i in range(2,n):
			arr[i] = (arr[i-1] + arr[i-2])%10007
	
	print(arr[n-1])
