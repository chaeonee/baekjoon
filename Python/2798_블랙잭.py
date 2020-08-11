import sys

def blackJack(N, M, card, pick, depth, cur, max_sum):
	if depth == 3: # 3개의 카드를 선택했다면(합이 M보다 크면 재귀를 진행할 수 없기 때문에 해당 단계에 들어온 합들은 모두 M을 넘지 않을 것)
		max_sum = max(cur, max_sum) # 현재까지의 합과 저장된 최대 합을 비교하여 최대 합 갱신
		return max_sum
		
	for i in range(N):
		cur += card[i] # 현재 합 계산
		if cur <= M and not pick[i]: # 계산한 현재 합이 M을 넘지 않고, 현재 카드가 선택한 적 없는 카드라면
			pick[i] = True # 카드 선택 표시
			max_sum = blackJack(N,M,card,pick,depth+1,cur,max_sum) # 다음 카트 선택하기 위한 재귀 진행
			pick[i] = False # 카드 선택 취소(백트래킹)
		cur -= card[i] # 더한 값 다시 빼주기(백트래킹)
		
	return max_sum

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	card = list(map(int,sys.stdin.readline().split()))
	pick = [False]*N # 카드를 선택했는지 여부
	
	print(blackJack(N,M,card,pick,0,0,0))
