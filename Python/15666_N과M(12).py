def getPermutation(M,s,depth,arr,perm):
	if depth == M: # 길이 M인 순열 만들어지면
		for p in perm: # 출력
			print(p,end=' ')
		print()
		return
	
	for i in range(s,len(arr)): # 중복 가능하므로 방문 표시하지 않음
		perm.append(arr[i])
		getPermutation(M,i,depth+1,arr,perm) # 재귀
		perm.pop()

if __name__ == '__main__':
	N, M = list(map(int,input().split()))
	arr = list(set(list(map(int,input().split())))) # 중복 제거 후
	arr.sort() # 정렬
	
	getPermutation(M,0,0,arr,[])
