if __name__ == '__main__':
	N, K = list(map(int,input().split()))
	
	rank = []
	for _ in range(N):
		rank.append(list(map(int,input().split())))
	
     # 금메달이 가장 많은 국가가 가장 먼저, 같다면 은메달, 그것도 같다면 동메달이 많은 순서대로 sorting하려면 역순으로 sorting 해야함
     # 동메달로 sorting하고 은메달 수로 sorting 하면 동메달 순서는 유지된 채 은메달로 sorting되기 때문(금메달도 마찬가지)
     # 메달이 많은 국가를 가장 먼저 오게 하기 위해 오름차순이 아닌 내림차순으로 정렬
	rank = sorted(rank,key=lambda x:-x[3])
	rank = sorted(rank,key=lambda x:-x[2])
	rank = sorted(rank,key=lambda x:-x[1])
	
	
	rank_now = 1
	if rank[0][0] != K: # rank[0][0]이 K와 같으면 1등이라는 이야기
		rank_next = 1 # 공동 등수가 있을 때를 대비한 변수, 같은게 것이 있으면 등수는 증가하지 않지만 그 뒤에 오는 것의 등수 같은 것의 수만큼 건너 뛰어야 하기 때문
		for i in range(1,N): # 이전과 비교하여 같으면 공동 등수로 출력해 줘야함(이전과 비교하기 위해 1부터)
			if rank[i][1:] == rank[i-1][1:]: # 같으면 등수는 그대로이고 이후 등수에만 영향 미침
				rank_next += 1
			else: # 다르면 등수 변환
				rank_now += rank_next
				rank_next = 1
			
			if rank[i][0] == K: # 원하는 등수면 break
				break
		
	print(rank_now)