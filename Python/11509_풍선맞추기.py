if __name__ == "__main__":
	N = int(input())
	H = input().split()
	H = [int(i) for i in H]

	arrow = 0
	h = [0]*1000001 # 특정 높이에 풍선이 있는지 확인할 배열
	for i in H:
		h[i] += 1 # 먼저 현재 높이 존재함을 표시
		if h[i+1] == 0: # 만약 나보다 1 큰 수가 왼쪽에 없었으면
			arrow += 1 # 화살 하나 추가
		else: # 만약 나보다 1 큰 수가 왼쪽에 있었으면
			h[i+1] -= 1 # 풍선 터뜨리고 높이 줄어들기 때문에 h[i+1]높이는 더 이상 사용 불가

	print(arrow)
