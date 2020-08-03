import sys

def breakingEgg(N, s, egg, n_broken, cur_broken):
	if s == N: # 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우
		return n_broken # 종료
	
	if egg[s][0] <= 0: # 현재 선택된 계란이 이미 깨진 계란인 경우
		n_broken = breakingEgg(N,s+1,egg,n_broken,cur_broken) # 한 칸 옆 계란 선택
		return n_broken
	
	for i in range(N): # 깨지지 않은 계란 찾기
		if i == s or egg[i][0] <= 0: # 현재 들고 있는 계란이거나, 깨진 계란 선택했을 경우
			continue # 건너 뛰기

		# 깨지지 않은 다른 계란 선택했을 때		
		egg[i][0] -= egg[s][1]
		egg[s][0] -= egg[i][1] # 서로 충돌했기 때문에 내구성 감소(상대방의 무게만큼)
		
		sub = 0 # 깨진 계란의 수 세기
		if egg[i][0] <= 0: # 선택한 계란 깨졌는지 확인
			sub += 1
		if egg[s][0] <= 0: # 들고 있는 계란 깨졌는지 확인
			sub += 1
		cur_broken += sub # 현재 충돌로 인해 깨진 계란만큼 깨진 계란의 수 증가
		
		if n_broken < cur_broken:
			n_broken = cur_broken # 깨진 계란의 수의 최댓값 확인하여 갱신(max 함수 쓰니까 시간초과..ㅠ)
		n_broken = breakingEgg(N,s+1,egg,n_broken,cur_broken) # 현재 계란 내려 놓고 오른쪽 옆에 있는 계란 선택
		
		egg[i][0] += egg[s][1]
		egg[s][0] += egg[i][1]
		cur_broken -= sub # 백트래킹
		
	return n_broken
	

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	egg = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
	
	n_broken = breakingEgg(N,0,egg,0,0)

	print(n_broken)
