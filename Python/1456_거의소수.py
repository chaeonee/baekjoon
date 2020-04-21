import math

if __name__ == '__main__':
	s, e = list(map(int,input().split()))
	sqrt_e = int(math.sqrt(e)) # 범위의 끝 값이 루트값보다 크면 제곱했을 때 끝 값을 넘어감, 따라서 그 이상의 수는 확인할 필요 없음
	
	cnt = 0 # 거의 소수를 세기 위한 변수
	arr = [False]*(sqrt_e+1) # 1부터 시작하기 위해서
	for i in range(2,sqrt_e+1):
		if arr[i] == False: # True가 아니면 소수
			arr[i] = True
			
			tmp_e = int(sqrt_e/i)
			for j in range(1,tmp_e+1): # 소수의 배수는 모두 소수가 아니므로 arr을 true로 표시해 줌
				arr[i*j] = True
				
			prime = i*i # 거의 소수 구하는 작업
			while prime <= e:
				if prime >= s: # 거의 소수가 범위 내에 존재하면
					cnt += 1 # 거의 소수의 수 1 증가
				prime *= i
	print(cnt)
