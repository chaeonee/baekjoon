import sys
from bisect import bisect_left

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	A = list(map(int,sys.stdin.readline().split()))
	
	LIS = [A[0]] # 길이 1짜리 부분수열을 첫 번째 수로 초기화
	for a in A[1:]:
		if LIS[-1] < a: # 가장 마지막 수열의 lower bound가 현재 수보다 작다면
			LIS.append(a) # 배열에 현재 수 추가(길이 1 추가된 부분 수열이 만들어지는 것)
			continue
		
		# 아니라면
		j = bisect_left(LIS,a) # 이분 탐색 이용하여 기준 값이 들어갈 자리 return(j를 기준으로 왼쪽은 현재보다 작은 값, 오른쪽은 현재보다 크거나 같은 값)
		LIS[j] = a # lower bound 갱신
		
	print(len(LIS))
