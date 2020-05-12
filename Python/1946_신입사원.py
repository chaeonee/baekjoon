import sys
input = sys.stdin.readline # @@@ input()보다 sys.stdin.readline()이 더 빠름 @@@

if __name__ == '__main__':
	T = int(input())
	for _ in range(T):
		N = int(input())
		
		test = [list(map(int,input().split())) for i in range(N)]
		test.sort() # 입력받은 등수 정렬
		
		pick = 1 # 필기 1등은 무조건 포함되기 때문에 1로 초기화
		i_min = test[0][1]
		for i in range(1,N):
			if test[i][1] < i_min: # 현재까지의 등수의 최솟값보다 더 작은 값이 나오면
				i_min = test[i][1] # 최솟값 갱신 후
				pick += 1 # 뽑을 인원 1명 증가

		print(pick)
