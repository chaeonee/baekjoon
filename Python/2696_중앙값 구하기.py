import sys
import math
import heapq

if __name__ == '__main__':
	T = int(sys.stdin.readline())
	for _ in range(T):
		M = int(sys.stdin.readline())
		
		num = []
		for i in range(int(math.ceil(M/10))): # 10줄씩 입력되기 때문에 10줄씩 받아서 합쳐줄 수 있어야 함
			tmp = list(map(int,sys.stdin.readline().split()))
			for x in tmp:
				num.append(x)
		
		mid = [] # 홀수번째 수일 때마다 중앙값을 넣을 배열
		min_heap = [] # min heap
		max_heap = [] # max heap
		for i in range(M):
			if len(max_heap) == len(min_heap): # min heap의 크기와 max heap의 크기가 같다면,
				heapq.heappush(max_heap,-num[i]) # max heap에 push(max heap이 min heap의 크기와 같거나 1 커야하기 때문)
			else: # min heap의 크기와 max heap의 크기가 같지 않을 경우(max heap의 크기가 1만큼 큰 경우),
				heapq.heappush(min_heap,num[i]) # max heap에 push(min heap과 max heap의 크기는 1이상 차이날 수 없기 때문)
			
			if len(min_heap) != 0 and min_heap[0] < -max_heap[0]: # min heap의 root보다 max heap의 root의 값이 더 클 경우
				tmp = heapq.heappop(max_heap)
				heapq.heappush(max_heap, -heapq.heappop(min_heap))
				heapq.heappush(min_heap, -tmp) # min heap의 root와 max heap의 root 값을 바꿔주어야 함(swap)
			
			if i % 2 == 0: # heap에 추가한 수가 홀수 번째 수일 때,(인덱스가 0부터 시작하기 때문에 인덱스가 짝수여야 홀수 번째 수가 됨)
				mid.append(-max_heap[0]) # 중앙 값 추가
				
		print(len(mid)) # 출력할 중앙값의 개수
		for i in range(len(mid)): # 중앙값 출력
			if (i+1) % 10 == 0 or i == len(mid) - 1: # 10줄씩 출력해야 하므로 10줄이 넘어갈 때마다 다음 줄로 넘어가도록 함(마지막 수도... 다음 입력을 위해)
				print(mid[i])
			else:
				print(mid[i], end=' ')
