if __name__ == '__main__':
	N = int(input())
	
	for _ in range(N):
		a,b = list(input().split())
		a = sorted(a)
		b = sorted(b) # a와 b를 알파벳 오름차순으로 정렬
		
		if a == b: # a와 b가 동일해야 strfry를 통해 얻어질 수 있는 결과가 됨
			print("Possible")
		else:
			print("Impossible")
