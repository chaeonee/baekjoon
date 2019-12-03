def getLotto(lotto,visit): # 로또 번호 출력하는 함수
	for i in range(len(visit)): # visit 함수 돌면서
		if visit[i] == True: # visit이 true이면 포함되어있다는 의미
			print(lotto[i], end=' ') # 출력(python의 print는 마지막이 \n으로 끝나기 때문에 마지막 문자 ' '으로 바꿔주고)
	print() # 출력 다 되면 다음 줄로

def dfs(s,e,d,lotto,visit): # 로또 번호 6개 출력하기 위한 dfs (s: 시작점, e: 배열의 종료 지점, d: 깊이, lotto: 로또 번호 집합, visit: 로또 번호 방문 여부 판단 배열)
	if d == 6: # 깊이가 6이면(6개 모두 선택 완료함을 의미)
		getLotto(lotto,visit) # 로또 번호 출력
		return
	
	for i in range(s,e): # 시작부터 끝까지 돌면서 수행(각 깊이에서 추가 누구를 추가 시킬 것인가?)
		visit[i] = True # 현재 내 자신 포함
		dfs(i+1,e,d+1,lotto,visit) # 사전 순으로 출력해야하기 때문에 다음에는 내 뒤쪽의 번호가 추가되어야 함(따라서, i+1이 시작점이 됨)
		visit[i] = False # 백트래킹을 위해 현재 내 자신 포함 여부 없앰(깊이 당 한 번호만 포함될 수 있음)

if __name__ == '__main__': # 백트래킹을 이용하여 풀이
	while True:
		lotto = list(map(int,input().split()))
		
		if lotto[0] == 0: # 0이 들어오면 종료
			break
		
		visit = [False]*lotto[0] # 방문 여부 판단 배열 false로 초기화
		dfs(0,lotto[0],0,lotto[1:],visit) # lotto 배열의 맨 앞은 집합의 수이므로 lotto는 1부터 사용
		print() # 띄어쓰기를 위함