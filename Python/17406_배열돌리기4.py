import sys
from itertools import permutations

def rotate(arr, oper_info):
	r, c, s = oper_info
	while s:
		start_x, start_y = r-s, c-s
		end_x, end_y = r+s, c+s
		
		cur = arr[start_x][start_y]
		for i in range(start_y+1, end_y+1):
			tmp = arr[start_x][i]
			arr[start_x][i] = cur
			cur = tmp
			
		for i in range(start_x+1, end_x+1):
			tmp = arr[i][end_y]
			arr[i][end_y] = cur
			cur = tmp
			
		for i in range(end_y-1, start_y-1, -1):
			tmp = arr[end_x][i]
			arr[end_x][i] = cur
			cur = tmp
			
		for i in range(end_x-1, start_x-1, -1):
			tmp = arr[i][start_y]
			arr[i][start_y] = cur
			cur = tmp
		
		s -= 1
		
	return arr
	
def getMin(arr):
	r_min = float('inf')
	for a in arr:
		r_min = min(r_min,sum(a))
	return r_min

N, M, K = list(map(int,sys.stdin.readline().split()))

arr = []
for _ in range(N):
	arr.append(list(map(int,sys.stdin.readline().split())))
	
oper = []
for _ in range(K):
	tmp = list(map(int,sys.stdin.readline().split()))
	tmp[0] -= 1
	tmp[1] -= 1
	oper.append(tmp)

r_min = float('inf')

p_order = list(permutations([i for i in range(K)], K))
for order in p_order:
	tmp_arr = [[i for i in j] for j in arr]
	for o in order:
		tmp_arr = rotate(tmp_arr,oper[o])
	
	r_min = min(r_min, getMin(tmp_arr))
	
print(r_min)
