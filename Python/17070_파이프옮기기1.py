import sys

N = int(sys.stdin.readline())

house = []
for _ in range(N):
	house.append(list(map(int,sys.stdin.readline().split())))
	
cnt = [[[0]*N for _ in range(N)] for _ in range(3)]
cnt[0][0][1] = 1

for i in range(N):
	for j in range(1,N):
		if house[i][j] or (i == 0 and j == 1):
			continue
		
		if j-1 >= 0:
			cnt[0][i][j] += cnt[0][i][j-1] + cnt[2][i][j-1]
		if i-1 >= 0:
			cnt[1][i][j] += cnt[1][i-1][j] + cnt[2][i-1][j]
		if i-1 >= 0 and j-1 >= 0 and not house[i-1][j] and not house[i][j-1]:
			cnt[2][i][j] += cnt[0][i-1][j-1]+cnt[1][i-1][j-1]+cnt[2][i-1][j-1]
		
print(cnt[0][N-1][N-1]+cnt[1][N-1][N-1]+cnt[2][N-1][N-1])
