import sys
from collections import deque

N, K = list(map(int,sys.stdin.readline().split()))

belt = deque()
tmp = list(map(int,sys.stdin.readline().split()))
for t in tmp:
	belt.append([t,False])
	if not t:
		K -= 1

step = 0
while K > 0:
	step += 1
	belt.appendleft(belt.pop())
	
	belt[N-1][1] = False
	for i in range(N-2,0,-1):
		if belt[i][1] and not belt[i+1][1] and belt[i+1][0] > 0:
			belt[i][1] = False
			belt[i+1] = [belt[i+1][0]-1,True]
			
			if not belt[i+1][0]:
				K -= 1
	
	belt[N-1][1] = False
	if not belt[0][1] and belt[0][0] > 0:
		belt[0] = [belt[0][0]-1,True]
		
		if not belt[0][0]:
			K -= 1
	
print(step)
