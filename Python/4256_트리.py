import sys

def postorder(preorder, inorder, root, l, r):
	k = inorder.index(preorder[0])
	root.append(preorder.pop(0))
	
	if l < r:
		if preorder and l < k:
			postorder(preorder,inorder,root,l,k-1)
		if preorder and k < r:
			postorder(preorder,inorder,root,k+1,r)
		
	print(root.pop(), end = ' ')
	
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	preorder = list(map(int,sys.stdin.readline().split()))
	inorder = list(map(int,sys.stdin.readline().split()))
	
	postorder(preorder,inorder,[],0,n-1)
	print()
