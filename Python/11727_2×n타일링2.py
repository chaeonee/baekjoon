import sys

if __name__ == '__main__':
	n = int(sys.stdin.readline())
	
	dp = [0]*n
	dp[0] = 1
	
	if n > 1:
		dp[1] = 3 # n이 1이면 dp[1]에 접근 불가 -> 초기화 에러를 막기 위한 예외 처리
		
	for i in range(2,n): # 타일의 가로 길이 1 또는 2 -> i-1과 i-2를 이용하여 값 계산 / 가로가 i-2인 경우는 2가지 존재(2*1, 2*2)하므로 두 번 더해주어야 함(*2)
		dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007
		
	print(dp[n-1])
