if __name__ == '__main__':
	N = list(map(int,input().split()))
	
	num = 0
	for n in N:
		num += n*n
		
	print(num%10)
