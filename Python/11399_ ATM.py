import sys

N = int(sys.stdin.readline())
P = sorted(list(map(int,sys.stdin.readline().split())))

pre, time = 0, 0
for p in P:
	time += pre + p
	pre = pre + p
	
print(time)
