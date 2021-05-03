import sys
from itertools import permutations

N, K = list(map(int,sys.stdin.readline().split()))

kit = list(map(int,sys.stdin.readline().split()))
kit_order = list(permutations(kit,N))

cnt = 0
for permute in kit_order:
	cnt += 1
	weight = 500
	for p in permute:
		weight += p - K
		
		if weight < 500:
			cnt -= 1
			break
	
print(cnt)
