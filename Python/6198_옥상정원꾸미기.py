if __name__ == '__main__':
	N = int(input())
	height = [int(input()) for _ in range(N)] # 건물들의 높이
	
	num = [0]*N # 현재 건물 위치에서 볼 수 있는 건물들의 수를 담을 배열
	stack = [N-1]
	for i in range(N-2,-1,-1):
		cnt = 0
		while stack and height[stack[-1]] < height[i]: # stack이 비어있지 않아야 하며, stack의 맨 위(top)의 건물 높이가 현재 건물 높이보다 낮아야 함
			cnt += 1 # 현재 건물보다 낮은 건물 개수 세기(stack 내에 존재하는 건물들 중 현재 건물보다 낮은 건물들의 개수 구하기)
			num[i] += num[stack.pop()] # 현재 건물보다 낮은 건물들에서 볼 수 있는 건물들의 개수 더하기(stack 내에 존재하지 않는 건물들 중 현재 건물보다 낮은 건물들의 개수 구하기)
			
		num[i] += cnt # stack 내에 존재하는 낮은 건물의 수
		
		stack.append(i) # 모두 계산 후 현재 건물의 index를 stack에 추가
        
	print(sum(num)) # 각 위치에서 볼 수 있는 건물들의 수 모두 더하기
