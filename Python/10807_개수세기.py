if __name__ == '__main__':
	N = int(input())
	num = list(map(int,input().split()))
	v = int(input())
	
	print(num.count(v)) # 배열 num 안에 v가 몇 개 있는지 세기