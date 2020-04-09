def matMul(N,A1,A2): # 행렬 곱 구하는 함수
	matrix = [[0]*N for _ in range(N)]
	for i in range(N):
		for j in range(N):
			matrix[i][j] = sum([(A1[i][k]*A2[k][j])%1000 for k in range(N)])%1000 # 1000으로 나눈 나머지 구해줘야 됨
	
	return matrix

def matSquared(N,B,A): # 행렬 제곱 구하기 위함
	if B == 1: # A^1 = A
		return A
		
	if B % 2 == 0: A^(짝수) = (A^(짝수/2))^2
		matrix = matSquared(N,B/2,A) # 제곱이므로 한 번만 구하기
		return matMul(N,matrix,matrix) # 구한 값 제곱하기
		
	else: # A^(홀수) = A^1*A^(홀수-1)
		matrix = matSquared(N,B-1,A) # 얘는 다음에 짝수 승으로 넘어갈 것
		return matMul(N,matrix,A)
	
if __name__ == '__main__':
	N, B = list(map(int,input().split()))
	A = [list(map(int,input().split())) for _ in range(N)]
	
	A = matSquared(N,B,A)
	
	for i in range(N):
		for j in range(N):
			print(A[i][j]%1000, end=' ') # 이미 나눠져 있는데 제곱이 수행 안될 때를 대비해서 1000을 또 나눠주자~
		print()
