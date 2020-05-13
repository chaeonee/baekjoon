import sys

def getDist(x1,y1,x2,y2): # 좌표간의 거리(L1) 구하기 위한 함수
	return abs(x1-x2)+abs(y1-y2)

def getChickenDist(house,pick): # 도시의 치킨거리 구하기 위한 함수
	min_dist = 0
	for hx, hy in house: # 각 집에서
		tmp = 100000
		for cx, cy in pick: # 가장 가까운 치킨집과의 거리 구하기
			tmp = min(tmp,getDist(hx,hy,cx,cy))
		
		min_dist += tmp # 각 집과 가장 가가운 치킨집과의 거리의 합 구하기
	
	return min_dist

def Choice(M,house,chicken,s,depth,min_dist,pick):
	if depth == M: # 치킨집을 M개 모두 고르면
		min_dist = min(min_dist,getChickenDist(house,pick)) # 치킨 거리 구하기 -> 구한 치킨 거리가 최소 치킨 거리라면 min_dist 갱신
		return min_dist
		
	c_len = len(chicken)
	for i in range(s,c_len): # 백트래킹
		pick.append(chicken[i]) # 치킨집 선택
		min_dist = Choice(M,house,chicken,i+1,depth+1,min_dist,pick) # 다음 치킨집은 뒤쪽 인덱스를 갖는 치킨집만 선택하기
		pick.pop() # 치킨집 선택 취소
		
	return min_dist

if __name__ == '__main__':
	N, M = list(map(int,sys.stdin.readline().split()))
	street = [list(map(int,sys.stdin.readline().split())) for i in range(N)]
	
	house = []
	chicken = []
	for i in range(N):
		for j in range(N):
			if street[i][j] == 1: # 집 좌표
				house.append([i,j])
			elif street[i][j] == 2: # 치킨집 좌표
				chicken.append([i,j])
	
	min_dist = 100000		
	if len(chicken) <= M: # 치킨집의 개수가 M개 이하라면(사실상 M개일 경우) 치킨집 따로 선택할 필요없이 치킨 거리 구하기만 하면 됨
		min_dist = min(min_dist,getChickenDist(house,chicken))
	else: # 아니라면 남길 치킨 집 먼저 계산 후 치킨 거리 계산
		min_dist = Choice(M,house,chicken,0,0,min_dist,[])
		
	print(min_dist)
