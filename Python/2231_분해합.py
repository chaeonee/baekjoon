import sys
from itertools import product

def getDigit(N): # 주어진 수가 몇 자릿수를 가지는지 구하는 함수
	digit = 0
	while N > 0:
		digit += 1
		N = int(N/10)
		
	return digit # 주어진 수의 자릿수

def getConstructor(N, digit):
	con = 0 # N의 가장 작은 생성자
	
	start = max(1,10**(digit-2)) # 확인하기 시작할 수(한 자리수 수가 주어졌을 때는 한 자리 작은 수를 확인할 수 없음)
	for num in range(start,N):
		tmp = 0
		for i in str(num): # 분해합 구하는 과정(해당 수 + 각 자리수의 수)
			tmp += int(i)
		if (tmp + num) == N: # 해당 생성자의 분해합이 주어진 수라면
			con = num # 생성자 저장 후 return할 것
			break

	return con
	

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	digit = getDigit(N)
	print(getConstructor(N, digit))
