import sys
input = sys.stdin.readline

if __name__ == '__main__':
	N = int(input())
	
	n = 0 # 카드 팩에 들어있는 카드의 수
	cost = [0]*(N+1) # N개의 카드를 구매하기 위해 지불해야 하는 금액의 최댓값
	for c in list(map(int,input().split())):
		n += 1
		for i in range(n,N+1): # n개가 들어있는 카드 팩을 가지면 최종적으로 n개 이상의 카드만 가질 수 있음 -> cost[n] 이상만 비교
			cost[i] = max(cost[i], c+cost[i-n]) # 저장된 금액과 현재 카드 팩을 사용했을 때의 최대 금액을 비교해서 더 큰 금액을 저장
			
	print(cost[N])
