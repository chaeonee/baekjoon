import sys
from collections import deque, defaultdict


def getUSADO(s, k, N, USADO):
	visit = [False]*N
	visit[s] = True
	
	cnt = 0
	q = deque([s])
	while q:
		n = q.popleft()
		for i, cur_u in USADO[n]:
			if not visit[i] and cur_u >= k:
				cnt += 1
				visit[i] = True
				q.append(i)
				
	return cnt
	
N, Q = list(map(int,sys.stdin.readline().split()))

USADO = defaultdict(list)
for _ in range(N-1):
	p, q, r = list(map(int,sys.stdin.readline().split()))
    
	USADO[p-1].append([q-1,r])
	USADO[q-1].append([p-1,r])
	
for _ in range(Q):
	k, v = list(map(int,sys.stdin.readline().split()))
	print(getUSADO(v-1,k,N,USADO))
