def getNum(n): # 생성자가 주어지면 생성자로부터 만들어지는 수 return
	num = n
	for i in str(n):
		num += int(i) # 생성자 + 생성자의 각 자리수(생성자를 str로 보고 하나씩 탐색 후, int로 형변환 하여 더함)
		
	return num;
	
if __name__ == "__main__":
	isSelf = [True]*10001 # 셀프 넘버인지 아닌지 확인하는 배열(True: 셀프 넘버, False: 셀프 넘버 아님)
	
	for i in range(1,10001):
		num = getNum(i);
		if num < 10001: # num이 10000이하의 수라면 셀프 넘버 후보에서 제외
			isSelf[num] = False;
		
		if isSelf[i] == True: # 셀프 넘버라면 출력
			print(i)
