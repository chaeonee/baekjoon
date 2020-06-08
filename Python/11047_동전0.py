import sys

if __name__ == '__main__':
	N, K = list(map(int,sys.stdin.readline().split()))
	
	prev_coin = int(sys.stdin.readline())
	n_coin, r_coin = K, 0 # n_coin: 현재 동전으로 가치를 만들 수 있는 동전의 수, r_coin: 현재 동전보다 더 적은 가치로 만들 수 있는 동전의 수(현재 가치로는 못 만드는) 
	for _ in range(1,N):
		cur_coin = int(sys.stdin.readline())
		
		if cur_coin > K: # 만들고자 하는 가치보다 현재 동전이 더 크면 원하는 가치 만들 수 없으므로
			break # 루프 탈출
		
		r_coin += int(n_coin % (cur_coin / prev_coin)) # 현재 가치로 만들 수 없는 동전의 수 계산(이전까지 42개의 동전이 필요한데 현재 가치가 5배 큰 동전이 들어왔다면 2개의 동전만큼은 커버하지 못할 것... 이것을 나머지로 따로 저장해주기)
		n_coin = int(n_coin / int(cur_coin / prev_coin)) # 현재 가치로 만들 수 있는 동전의 수 계산(이전 가치 50원 이후 가치 100원이면 1/2배만큼의 동전이 필요할 것 -> (현재동전가치/이전동전의가치)만큼 동전의 수 나눠주기)
		
		prev_coin = cur_coin # 이전 동전의 가치 갱신
		
	print(n_coin+r_coin) # 필요한 동전은 동전의 n_coin과 r_coin의 합
