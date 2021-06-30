import sys

N, M = list(map(int,sys.stdin.readline().split()))
active = list(map(int,sys.stdin.readline().split()))
deactive = list(map(int,sys.stdin.readline().split()))

D = sum(deactive) # 모든 앱을 비활성화 하고 재 실행했을 경우의 비용(최대 비용이 됨)
memory = [[0]*(D+1) for _ in range(N+1)] # n개의 앱 & 비용 c 일 때, 최대로 얻을 수 있는 메모리를 저장할 배열

cost = float('inf') # 필요한 메모리 M 바이트를 확보하기 위한 앱 비활성화의 최소의 비용
for i in range(1,N+1):
	for j in range(D+1):
		memory[i][j] = memory[i-1][j] # 현재 앱을 재 실행시키지 않을 경우(비활성화 X)
		if j-deactive[i-1] >= 0: # 현재 앱을 비활성화 하고 재 실행시킬 비용만큼 있을 때
			memory[i][j] = max(memory[i][j], memory[i-1][j-deactive[i-1]]+active[i-1]) # 현재 앱 비활성화 하는 경우 vs 현재 앱 비활성화 안하는 경우 -> 둘 중 확보되는 메모리 큰 것을 저장
		
		if memory[i][j] >= M: # 확보되는 메모리가 새로운 앱을 실행시키는 것보다 클 경우
			cost = min(cost,j) # 해당 cost 저장(이 때, 최소 비용을 저장해야 하므로, 기존의 비용과 비교하여 더 작으면 갱신)

print(cost)
