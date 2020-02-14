if __name__ == '__main__':
	num = list(map(int,input().split()))
	num.sort()
	
	for n in num:
		print(n, end=' ')