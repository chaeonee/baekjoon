import sys
import heapq

N = int(sys.stdin.readline())

max_heap = [] # 중간 값과 중간 값보다 작은 값들을 저장
min_heap = [] # 중간 값보다 큰 값들을 저장
heapq.heappush(max_heap,-1*int(sys.stdin.readline()))
print(max_heap[0]*-1) # 1개가 들어왔을 때는 들어온 값이 중간 값이 됨

for _ in range(N-1):
	n = int(sys.stdin.readline())
	if n <= max_heap[0]*-1: # 만약 중간 값보다 작은 값이 입력되었다면
		heapq.heappush(max_heap,-1*n) # max heap에 저장
	else: # 중간 값보다 큰 값이 입력되었다면
		heapq.heappush(min_heap,n) # min heap에 저장
	
	if abs(len(max_heap)-len(min_heap)) >= 1: # heap의 크기의 차가 1보다 크다면 heap 수정하여 중간 값 갱신 필요
		if len(max_heap) < len(min_heap): # max heap의 크기가 더 작다면
			heapq.heappush(max_heap,heapq.heappop(min_heap)*-1) # min heap에서 min값을 pop하여 max heap에 push하여 중간 값 갱신
		elif len(max_heap) > len(min_heap)+1: # min heap의 크기가 max heap - 1보다 더 작다면
			heapq.heappush(min_heap,heapq.heappop(max_heap)*-1) # max heap에서 max값을 pop하여 min heap에 push하여 중간 값 갱신
	print(max_heap[0]*-1) # 현재까지의 중간 값 출력
