def isPossible(K, N, arr, mid): # N개 이상의 랜선이 만들어지는지 확인하기 위한 함수
	tmp = 0
	for a in arr:
		tmp += int(a/mid) # mid: 현재 랜선의 길이 / 현재 랜선 길이로 설정되었다면 몇 개의 랜선이 만들어지는지 count
	
	if tmp >= N: # N개 이상의 랜선이 만들어졌다면, true를 return
		return True
	
	return False # N개보다 적은 랜선이 만들어졌다면, false를 return
	

if __name__ == '__main__':
	K, N = list(map(int,input().split()))
	
	arr = [int(input()) for _ in range(K)]
	
	left = 1
	right = max(arr)
	
	result = 0
	while left <= right: # 이분 탐색 시작
		mid = int((left+right)/2) # mid 값이 랜선의 최대 길이를 의미
		if isPossible(K,N,arr,mid): # N개 이상의 랜선이 만들어졌다면
			left = mid + 1 # 현재 랜선의 길이보다 긴 랜선의 범위 탐색(이분 탐색 재진행)
			result = mid # N개 이상의 랜선이 만들어졌다면, 이전 mid 값보다 작은 mid값일 수가 없음, 따라서 result 계속 갱신해주기
		else: # N개의 랜선이 만들어지지 않았다면
			right = mid - 1 # 현재 랜선의 길이보다 작은 랜선의 범위 탐색
			
	print(result)
