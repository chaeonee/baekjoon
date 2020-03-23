if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		N = int(input())
		
		arr = [0]*(N+1)
		arr[0] = 1 # 초기값 1로 설정
		for i in range(1,4): # +1부터 +3으로 이루어진 합의 수 구할 것
			for n in range(i,N+1): # i부터 채우는 이유는 i보다 적은 값은 숫자 i로 구성할 수 없기 때문
				tmp = 0
				for j in range(1,i+1): # 현재 값은 이전 i개의 배열 값 더해준 값
					tmp += arr[n-j]
				arr[n] = tmp
				
		print(arr[N])
