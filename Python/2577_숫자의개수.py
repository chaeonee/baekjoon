if __name__ == '__main__':
	A = int(input())
	B = int(input())
	C = int(input())
	
	mul = str(A * B * C) # 세 수의 곱을 문자열로 바꿈
	
	arr = [0]*10 # 0~9까지의 수가 몇개 있는지 세기 위한 배열
	for m in mul:
		arr[int(m)] += 1 # 문자열이기 때문에 인덱스로 입력할 때는 int로 형변환 필요
	
	for i in arr:
		print(i)