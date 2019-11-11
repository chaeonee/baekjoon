def getNum(n):
	num = n
	for i in str(n):
		num += int(i)
		
	return num;
	
if __name__ == "__main__":
	isSelf = [False]*10001
	
	for i in range(1,10001):
		num = getNum(i);
		if num < 10001:
			isSelf[num] = True;
		
		if isSelf[i] == False:
			print(i)