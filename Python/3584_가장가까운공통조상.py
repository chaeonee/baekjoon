import sys

def findAnscestor(node, tree):
	anscestor = [node]
	while tree[node]['p'] != None:
		node = tree[node]['p']
		if node != None:
			anscestor.append(node)
	return anscestor

T = int(sys.stdin.readline())
for _ in range(T):
	N = int(sys.stdin.readline())
	
	tree = {}
	for _ in range(N-1):
		p, c = list(map(int,sys.stdin.readline().split()))
		
		if p not in tree.keys():
			tree[p] = {'p':None, 'c':[]}
		if c not in tree.keys():
			tree[c]	= {'p':None, 'c':[]}
			
		tree[p]['c'].append(c)
		tree[c]['p'] = p
			
	n1, n2 = list(map(int,sys.stdin.readline().split()))
	a1, a2 = findAnscestor(n1,tree), findAnscestor(n2,tree)
	
	anscestor = 0
	for i in a1:
		for j in a2:
			if i == j:
				anscestor = i
				break
		if anscestor:
			break
		
	print(anscestor)
