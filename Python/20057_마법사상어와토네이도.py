import sys

def moveLeft(N, r, c, grid):
	sand, total_sand = 0, grid[r][c]
	if c-2 >= 0:
		grid[r][c-2] += int(0.05*total_sand)
	else:
		sand += int(0.05*total_sand)
		
	for i in [-1, 1]:
		if 0 <= r+i < N:
			grid[r+i][c] += int(0.07*total_sand)
			
			if 0 <= r+2*i < N:
				grid[r+2*i][c] += int(0.02*total_sand)
			else:
				sand += int(0.02*total_sand)
			
			if c-1 >= 0:
				grid[r+i][c-1] += int(0.1*total_sand)
			else:
				sand += int(0.1*total_sand)
				
			if c+1 < N:
				grid[r+i][c+1] += int(0.01*total_sand)
			else:
				sand += int(0.01*total_sand)
				
		else:
			sand += int(0.07*total_sand)
			sand += int(0.1*total_sand)
			sand += int(0.01*total_sand)
			sand += int(0.02*total_sand)
		
	grid[r][c] -= 2*int(0.07*total_sand)
	grid[r][c] -= 2*int(0.1*total_sand)
	grid[r][c] -= 2*int(0.01*total_sand)
	grid[r][c] -= 2*int(0.02*total_sand)
	grid[r][c] -= int(0.05*total_sand)
	
	if c-1 >= 0:
		grid[r][c-1] += grid[r][c]
	else:
		sand += grid[r][c]
		
	grid[r][c] = 0
	
	return sand, grid

def moveRight(N, r, c, grid):
	sand, total_sand = 0, grid[r][c]
	if c+2 < N:
		grid[r][c+2] += int(0.05*total_sand)
	else:
		sand += int(0.05*total_sand)
		
	for i in [-1, 1]:
		if 0 <= r+i < N:
			grid[r+i][c] += int(0.07*total_sand)
			
			if 0 <= r+2*i < N:
				grid[r+2*i][c] += int(0.02*total_sand)
			else:
				sand += int(0.02*total_sand)
			
			if c-1 >= 0:
				grid[r+i][c-1] += int(0.01*total_sand)
			else:
				sand += int(0.01*total_sand)
				
			if c+1 < N:
				grid[r+i][c+1] += int(0.1*total_sand)
			else:
				sand += int(0.1*total_sand)
				
		else:
			sand += int(0.07*total_sand)
			sand += int(0.1*total_sand)
			sand += int(0.01*total_sand)
			sand += int(0.02*total_sand)
		
	grid[r][c] -= 2*int(0.07*total_sand)
	grid[r][c] -= 2*int(0.1*total_sand)
	grid[r][c] -= 2*int(0.01*total_sand)
	grid[r][c] -= 2*int(0.02*total_sand)
	grid[r][c] -= int(0.05*total_sand)
	
	if c+1 < N:
		grid[r][c+1] += grid[r][c]
	else:
		sand += grid[r][c]
		
	grid[r][c] = 0
	
	return sand, grid

def moveUp(N, r, c, grid):
	sand, total_sand = 0, grid[r][c]
	if r-2 >= 0:
		grid[r-2][c] += int(0.05*total_sand)
	else:
		sand += int(0.05*total_sand)
		
	for i in [-1, 1]:
		if 0 <= c+i < N:
			grid[r][c+i] += int(0.07*total_sand)
			
			if 0 <= c+2*i < N:
				grid[r][c+2*i] += int(0.02*total_sand)
			else:
				sand += int(0.02*total_sand)
			
			if r-1 >= 0:
				grid[r-1][c+i] += int(0.1*total_sand)
			else:
				sand += int(0.1*total_sand)
				
			if r+1 < N:
				grid[r+1][c+i] += int(0.01*total_sand)
			else:
				sand += int(0.01*total_sand)
				
		else:
			sand += int(0.07*total_sand)
			sand += int(0.1*total_sand)
			sand += int(0.01*total_sand)
			sand += int(0.02*total_sand)
		
	grid[r][c] -= 2*int(0.07*total_sand)
	grid[r][c] -= 2*int(0.1*total_sand)
	grid[r][c] -= 2*int(0.01*total_sand)
	grid[r][c] -= 2*int(0.02*total_sand)
	grid[r][c] -= int(0.05*total_sand)
	
	if r-1 >= 0:
		grid[r-1][c] += grid[r][c]
	else:
		sand += grid[r][c]
		
	grid[r][c] = 0
	
	return sand, grid

def moveDown(N, r, c, grid):
	sand, total_sand = 0, grid[r][c]
	if r+2 < N:
		grid[r+2][c] += int(0.05*total_sand)
	else:
		sand += int(0.05*total_sand)
		
	for i in [-1, 1]:
		if 0 <= c+i < N:
			grid[r][c+i] += int(0.07*total_sand)
			
			if 0 <= c+2*i < N:
				grid[r][c+2*i] += int(0.02*total_sand)
			else:
				sand += int(0.02*total_sand)
			
			if r-1 >= 0:
				grid[r-1][c+i] += int(0.01*total_sand)
			else:
				sand += int(0.01*total_sand)
				
			if r+1 < N:
				grid[r+1][c+i] += int(0.1*total_sand)
			else:
				sand += int(0.1*total_sand)
				
		else:
			sand += int(0.07*total_sand)
			sand += int(0.1*total_sand)
			sand += int(0.01*total_sand)
			sand += int(0.02*total_sand)
		
	grid[r][c] -= 2*int(0.07*total_sand)
	grid[r][c] -= 2*int(0.1*total_sand)
	grid[r][c] -= 2*int(0.01*total_sand)
	grid[r][c] -= 2*int(0.02*total_sand)
	grid[r][c] -= int(0.05*total_sand)
	
	if r+1 < N:
		grid[r+1][c] += grid[r][c]
	else:
		sand += grid[r][c]
		
	grid[r][c] = 0
	
	return sand, grid

N = int(sys.stdin.readline())

grid = []
for _ in range(N):
	grid.append(list(map(int,sys.stdin.readline().split())))

m_dir = [[0,-1],[1,0],[0,1],[-1,0]]

sand = 0
r, c, d, n_move = N//2, N//2, 0, 1
while True:
	if r == 0 and c == 0:
		break
	
	for _ in range(n_move):
		r += m_dir[d][0]
		c += m_dir[d][1]
		
		if d == 0:
			tmp, grid = moveLeft(N, r, c, grid)
		elif d == 1:
			tmp, grid = moveDown(N, r, c, grid)
		elif d == 2:
			tmp, grid = moveRight(N, r, c, grid)
		elif d == 3:
			tmp, grid = moveUp(N, r, c, grid)
		sand += tmp
		
		if r == 0 and c == 0:
			break
	
	if d == 1 or d == 3:
		n_move += 1
	
	d = (d+1)%4
	
print(sand)
