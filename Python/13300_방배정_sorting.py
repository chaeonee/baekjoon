import math

if __name__ == '__main__':
	N, K = list(map(int,input().split()))
	
	arr = []
	for _ in range(N):
		arr.append(list(map(int,input().split())))
	
	arr = sorted(arr, key=lambda x:x[1])
	arr = sorted(arr, key=lambda x:x[0]) # 각 그룹끼리 모이도록 성별, 학년으로 sorting 진행
	
	k = 0 # 현재 방에 들어간 학생 수(전체 수x)
	n_room = 1 # 필요한 방의 수
	for i in range(1,len(arr)):
		k += 1 # k는 현재 방에 들어간 학생들의 수를 의미
		if arr[i] != arr[i-1] or k == K: # 현재 학생이 다른 그룹이거나, 현재 방이 꽉 찼을 때
			n_room += 1
			k = 0 # 방을 하나 늘리고, 현재 방 인원을 0으로
			
	print(n_room)