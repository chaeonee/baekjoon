if __name__ == '__main__':
	N = int(input())
	
	A = list(map(int,input().split()))
	B = list(map(int,input().split()))
	
  # 곱의 합이 최소가 되기 위해서는 (큰 수 * 작은 수)의 조합이 필요하므로 정렬 진행 -> 조합을 위해 두 배열 반대로 정렬
  # 둘 중 하나는 오름차순 정렬, 나머지 하나는 내림차순 정렬
	A.sort()
	B.sort(reverse=True)
	
	S = 0
	for i in range(N):
		S += A[i] * B[i]
	
	print(S)
