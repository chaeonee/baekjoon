if __name__ == '__main__':
	num = list(map(int,input().split()))
	
	for i in range(3):
		for j in range(i+1,3): # 현재 수와 뒤쪽에 존재하는 수들 비교
			if num[i] > num[j]:
				num[i], num[j] = num[j], num[i] # 큰 수가 더 앞에 있는 경우 자리 바꿈
				
	for n in num:
		print(n, end=' ')
