def hanoi(N,s,m,e):
	if N == 1:
		print(str(s)+" "+str(e))
		return
	N -= 1
	hanoi(N,s,e,m)
	print(str(s)+" "+str(e))
	hanoi(N,m,s,e)

if __name__ == "__main__":
	N = int(input())
	
	print(pow(2,N)-1)
	
	hanoi(N,1,2,3)