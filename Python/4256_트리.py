import sys

def postorder(preorder, inorder, root, l, r):
	k = inorder.index(preorder[0]) # 현재 노드가 pre-order에서 어디에 위치하는지 확인
	root.append(preorder.pop(0)) # 현재 subtree의 root를 root라는 이름의 stack에 삽입
	
	if l < r:
		if preorder and l < k:
			postorder(preorder,inorder,root,l,k-1) # 현재 노드를 중심으로 왼쪽 subtree 탐색
		if preorder and k < r: # 현재 노드를 중심으로 오른쪽 subtree 탐색
			postorder(preorder,inorder,root,k+1,r)
		
	print(root.pop(), end = ' ') # 탐색이 끝나면 현재 노드(local root) pop 하면서 출력
	
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	preorder = list(map(int,sys.stdin.readline().split()))
	inorder = list(map(int,sys.stdin.readline().split()))
	
	postorder(preorder,inorder,[],0,n-1)
	print()
