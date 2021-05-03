import sys
import heapq

N = int(sys.stdin.readline())

class_info = []
for i in range(N):
	class_info.append(list(map(int,sys.stdin.readline().split())))
class_info = sorted(class_info, key = lambda x: (x[0], x[1]))

pq = []
cnt = 0
for s, e in class_info:
	while pq and s >= pq[0]:
		heapq.heappop(pq)
	heapq.heappush(pq,e)
	
	cnt = max(cnt, len(pq))
	
print(cnt)
