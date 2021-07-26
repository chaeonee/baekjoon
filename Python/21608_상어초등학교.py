import sys

def check(N, friends, room):
	dirs = [[0,-1],[0,1],[-1,0],[1,0]]
	
	n = [-1,-1]
	x, y = -1, -1
	for i in range(N):
		for j in range(N):
			if room[i][j]:
				continue
			
			tmp = [0,0]
			for di, dj in dirs:
				di += i
				dj += j
				if 0 <= di < N and 0 <= dj < N:
					if room[di][dj] == 0:
						tmp[1] += 1
					elif room[di][dj] in friends:
						tmp[0] += 1
						
			if n[0] < tmp[0]:
				x, y = i, j
				n = [t for t in tmp]
			elif n[0] == tmp[0] and n[1] < tmp[1]:
				x, y = i, j
				n = [t for t in tmp]
	
	return x, y
	
def getSatisfaction(N, friends, room):
	dirs = [[0,-1],[0,1],[-1,0],[1,0]]
	
	sat = 0
	for i in range(N):
		for j in range(N):
			cnt = 0
			if room[i][j] not in friends.keys():
				continue
			friend = friends[room[i][j]]
			for di, dj in dirs:
				di += i
				dj += j
				if 0 <= di < N and 0 <= dj < N and room[di][dj] in friend:
					cnt += 1
					
			sat = sat if cnt == 0 else sat + (10**(cnt-1))			
	
	return sat

N = int(sys.stdin.readline())
room = [[0]*N for _ in range(N)]

friends = {}
for _ in range(N**2):
	num = list(map(int,sys.stdin.readline().split()))
	friends[num[0]] = num[1:]
	
	x, y = check(N,friends[num[0]],room)
	room[x][y] = num[0]
	
print(getSatisfaction(N,friends,room))
