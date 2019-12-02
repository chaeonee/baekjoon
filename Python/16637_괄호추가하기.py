def getNum(num,oper,bracket): #숫자 계산하는 함수
	queue = []
	flag = False # 괄호가 열려 있는지 여부
	for i in range(len(bracket)):
		if bracket[i] == 1: # 현재 위치 괄호가 선택되었으면
			queue.append("-1") #괄호를 의미함(괄호 열기)
			queue.append(num[i]) # 숫자와
			queue.append(oper[i]) # 연산자 추가
			flag = True # 괄호가 열려있다는 의미
		else:
			if flag == True: # 현재 위치 괄호가 선택되지 않았지만 괄호가 열려있을 경우
				queue.append(num[i]) # 숫자 추가 후
				queue.append("-1") #괄호를 의미함 (괄호 닫기)
				queue.append(oper[i]) # 연산자 추가
				flag = False # 괄호를 닫았으니 괄호가 닫혀있다는 의미로 false
			else: # 괄호 선택되지도 않고 열려있지도 않은 경우
				queue.append(num[i]) # 숫자와
				queue.append(oper[i]) # 연산자 추가
				
	if flag == True: # 마지막 숫자에 대해 괄호 열려 있으면
		queue.append(num[len(bracket)]) # 숫자 추가하고
		queue.append("-1") #괄호를 의미함(괄호 닫기)
	else: # 괄호 열려 있지 않으면
		queue.append(num[len(bracket)]) # 괄호 없이 숫자만 추가
		
	f = "" # 계산을 위한 문자열
	while queue: #queue가 빌 때 까지
		n = queue.pop(0)
		
		if n == "-1": # 괄호를 만나면
			tmp = ""
			while True: # 괄호 안을 먼저 계산하기 위한 while
				t = queue.pop(0)
				
				if t == "-1": # 괄호 만나면(괄호가 닫힘) while 탈
					break
				
				tmp += t
				
			f += str(eval(tmp)) # 앞쪽 계산이 되지 않은 문자열과 tmp 값을 계산
			f = str(eval(f)) #계산한 결과로 tmp 갱신
		
		else: # 괄호 없을 때
			if n == "+" or n == "-" or n == "*": # 연산자를 만나면
				f += n # 아직 계산할 수 없으니 문자열에 추가
			else: # 숫자 만나면
				f += n # 숫자 문자열로 추가하고
				f = str(eval(f)) # 계산 진행
				
	return eval(f)
	
def calDfs(s, e, result, num, oper, bracket): # 괄호 선택하는 함수
	if s == e: #s와 e가 같으면 괄호 사용 위치 모두 선택했다는 뜻
		tmp = getNum(num, oper, bracket)
		result = max(result,tmp) # 계산하여 최댓값 취함
		return result
		
	result = max(result, calDfs(s+1, e, result, num, oper, bracket)) # 앞쪽 괄호가 선택된 것과 관계없이 현재 괄호 선택 안될 수 있음
	if bracket[s-1] == 0 or s == 0: # 앞쪽 괄호 선택되면 현재 괄호 선택 불가능(따라서 현재 괄호 선택하려면 앞쪽 괄호 선택 안됐는지 확인해야 함)
		bracket[s] = 1
		result = max(result, calDfs(s+1, e, result, num, oper, bracket)) # 최댓값 선택
		bracket[s] = 0
		
	
	return result

if __name__ == '__main__':
	N = int(input())
	S = input()
	
	num = []
	oper = []
	for i in range(N):
		if i%2 == 0: # 숫자
			num.append(S[i])
		else: # 연산자
			oper.append(S[i])
			
	bracket = [0]*len(oper)
	print(calDfs(0,len(oper), -float('inf'), num, oper, bracket))