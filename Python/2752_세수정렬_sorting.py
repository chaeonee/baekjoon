if __name__ == '__main__':
	num = list(map(int,input().split()))
	num.sort() # sort 함수를 이용하여 배열을 오름차순으로 정렬
	
	for n in num:
		print(n, end=' ')
