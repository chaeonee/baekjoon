import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	arr = [[0]*11 for _ in range(N)]
	for i in range(1,11):
		arr[0][i] = i # 초기화
		
	for i in range(1,N):
		for j in range(1,11):
			arr[i][j] = (arr[i][j-1] + arr[i-1][10] - arr[i-1][j-1]) % 10007
     			# i자리수의 값이 j일 때, 그 뒤에 올 수 있는 수의 갯수는 i-1자리수가 j~9일때의 합
      			# arr[i-1][j]는 i-1 자리수가 0~j-1일 때의 오르막 수의 개수를 의미 -> j~9일 때의 경우의 수를 계산하려면 arr[i-1][10]-arr[i-1][j-1]을 이전 값에 더해주어야 함
      
	print(arr[N-1][10])
