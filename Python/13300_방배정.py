import math # 올림(ceil)을 사용하기 위함

if __name__ == '__main__':
	N, K = list(map(int,input().split()))
	
	arr = [[0]*7 for _ in range(2)] # 그룹 별 학생 수를 세기 위한 배열(행: 성별, 열: 학년)
	for _ in range(N): # 학생의 그룹에 해당하는 배열 값 1증가
		S, Y = list(map(int,input().split()))
		arr[S][Y] += 1
		
	n_room = 0 # 방의 수를 세기 위한 변수
	for i in range(2):
		for j in range(7):
			n_room += int(math.ceil(arr[i][j]/K)) # K명까지 한 방을 쓸 수 있으므로 배열의 각 값을 K를 나눈 값의 합이 방의 수(나머지가 있을 경우, 올림해주어야 함)
	
	print(n_room)