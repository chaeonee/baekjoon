if __name__ == '__main__':
	N, K = list(map(int,input().split()))
	
	arr = [n for n in range(1,N+1)] # 현재 존재하는 사람을 담은 배열
	idx = 0
	print('<',end='')
	while(arr):
		idx = (idx+K-1) % len(arr) # 삭제될 index 계산(회전해야 하므로 arr의 길이로 나눈 나머지의 값을 index로 가짐)
		if(len(arr) > 1):
			print(arr[idx], end=', ')
		else: # 마지막 남은 사람일 때
			print(arr[idx], end='>')
		del arr[idx]