if __name__ == '__main__':
	n = int(input())
	box = list(map(int,input().split()))
	
	max_cnt = 0  # 최대 상자의 개수를 담는 변수
	agg_box = [1]*n # 박스가 몇 개의 박스를 포함하고 있는지(본인도 포함되기 때문에 1로 초기화)
	for i in range(1,n):
		tmp = 0 # 앞에 있는 박스들의 값 중 최대값을 담을 변수
		for j in range(i):
			if box[i] > box[j] and tmp < agg_box[j]: # 현재 박스보다 작고 지금까지 비교한 박스들 중 포함된 박스의 값이 가장 큰 값이라면
				tmp = agg_box[j]

		agg_box[i] = tmp + 1 # 앞에 있는 박스들의 값중 최대값 + 1(본인 포함)
		if agg_box[i] > max_cnt: # 그 중 최대 값을 구하기 위함
			max_cnt = agg_box[i]
			
	print(max_cnt)
