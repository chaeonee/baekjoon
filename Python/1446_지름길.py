import sys

if __name__ == '__main__':
	N, D = list(map(int,sys.stdin.readline().split()))
	
	shortcut = [list(map(int,sys.stdin.readline().split())) for _ in range(N)] # 지름길 정보 시작점, 끝점, 지름길길이 순으로 저장됨
	shortcut = sorted(shortcut, key=lambda x:(x[1],x[0])) # 지름길 정보를 끝점을 기준으로 정렬(끝점이 같으면 시작점으로)
	
	i = -1 # index를 위한 i
	drive = [D]*N # 해당 지름길을 이용할 때(이전 지름길도 포함하여), 운전해야하는 최단 거리 저장
	for s, e, l in shortcut:
		i += 1
		
		if e > D: # 만약 끝 점이 목적지보다 멀면
			break # 더 이상 초기화 그만하고 루프 탈출(이후 값들도 끝점이 목적지보다 멀 것)
		
		r_short = min(e-s, l) # 지름길이 원래 길보다 긴 경우를 대비(지름길이 더 길면 지름길로 갈 필요 없음)
		drive[i] = D-(e-s)+r_short
		
	
	result = drive[0] # 운전할 최단 거리를 첫 번째 지름길만 사용했을 때의 거리로 초기화
	for i in range(1,N):
		s, e, l = shortcut[i]
		if e > D: # 만약 끝 점이 목적지보다 멀면
			break # 이후 끝점들도 목적지 이후 값일 것이기 때문에 루프 탈출(역주행이 안되기 때문)
		
		for j in range(i): # 이전 지름길 이용하는 경우 중 가장 짧은 거리에 현재 지름길 이용하는 경우 계산하기 위함
			if s < shortcut[j][1]: # 현재 시작점보다 이전 지름길의 끝점이 더 큰 값을 가질 때 -> 이는 경로가 겹치는 경우(역주행이 안되기 때문)
				break # 더 이상 볼 필요 없음(이후 경우의 끝점도 현재 시작점보다 더 큰 값을 가질 것이므로)
			
			r_short = min(e-s, l) # 지름길이 원래 길보다 긴 경우를 대비(지름길이 더 길면 지름길로 갈 필요 없음)
			drive[i] = min(drive[i], drive[j]-(e-s)+r_short) # 최솟값으로 갱신
		
		result = min(result, drive[i]) # 운전해야 하는 거리의 최솟값 저장
	
	print(result, end='')
