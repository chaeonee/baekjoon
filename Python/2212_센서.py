import sys

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	K = int(sys.stdin.readline())
	
	sensor = list(map(int,sys.stdin.readline().split()))
	sensor.sort() # 센서의 위치 오름차순으로 정렬
	
	gap = []
	for i in range(1,N):
		gap.append(sensor[i]-sensor[i-1]) # 센서들 간의 거리 구하기
	gap.sort(reverse=True) # 센서들 간의 거리가 큰 값이 앞으로 올 수 있도록 내림차순으로 정렬
	
	len_area = sensor[-1]-sensor[0] # 초기 값: 전체 센서의 범위
	for i in range(K-1): # 집중국의 수가 K개 만들어지려면 K-1번 나눠주면 됨
		if i >= N-1: # 집중국의 수가 센서의 수보다 많을 때는 센서의 수만큼만 나눠주고 멈추기
			break
		len_area -= gap[i] # 센서 사이의 거리만큼 집중국 수신 가능 영역이 줄어듦
	
	print(len_area)
