if __name__ == '__main__':
	num = list(map(int,input().split()))
	
	for i in range(3):
		for j in range(i+1,3):
			if num[i] > num[j]:
				num[i], num[j] = num[j], num[i]
				
	for n in num:
		print(n, end=' ')