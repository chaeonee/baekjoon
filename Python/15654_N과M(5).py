from itertools import permutations

if __name__ == '__main__':
	M, N = list(map(int,input().split()))
	num = list(map(int,input().split()))
	
	num.sort() # 사전 순으로 출력하기 위해 sorting
	result = list(permutations(num,N)) # 순열을 구하는 내장 함수 이용
	
	for r in result: # 결과 순서대로 출력
		for r2 in r:
			print(r2,end=' ')
		print()
