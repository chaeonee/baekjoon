if __name__ == '__main__':
	S = input()
	
	dic = {} # 해당 알파벳을 키로 갖는 dictonary 생성할 것임(value는 등장 횟수(음수가 될 수도 있음))
	for s in S:
		if s in dic.keys(): # 키가 존재 한다면 이미 등장한 알파벳이므로 등장 횟수를 1 늘려주면 됨
			dic[s] += 1
		else: # 키가 존재하지 않으면 새로 등장하는 알파벳이므로 새로 생성
			dic[s] = 1
	
	S = input()
	for s in S:
		if s in dic.keys(): # 두 번째 문자열도 첫 번째 문자열과 동일하지만 등장 횟수를 1 줄여주는 형태
			dic[s] -= 1
			if dic[s] == 0: # 두 문자열을 통해 알파벳이 상쇄되면 사전에서 제거
				del(dic[s])
		else: # 새로운 알파벳이면 새로 생성(-1로)
			dic[s] = -1
			
	count = 0
	for val in dic.values(): # 첫 번째 문자열은 양수, 두 번째 문자열은 음수로 측정하였기 때문에 절대값의 합을 구해주어야 함
		count += abs(val)
		
	print(count)