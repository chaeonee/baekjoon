if __name__ == "__main__":
	T = int(input())
    
   # 각 문자열에 알파벳이 각각 몇개 존재하는지 세는 배열 만들기
	s = list(input())
	arr_s = [0]*26
	for i in s:
		arr_s[ord(i)-65] += 1 #ord는 문자를 아스키코드로 바꿔주기 위함
	
	result = 0
	for t in range(T-1):
		w = list(input())
		arr_w = [0]*26
		for i in w:
			arr_w[ord(i)-65] += 1
		
      # s와 w의 길이가 같다면 아예 구성이 같거나 각각 한 개(총 2개)씩 다른 문자 구성 존재
		if len(s) == len(w):
			tmp = 0		
			for i in range(26):
				if arr_s[i] != arr_w[i]:
					tmp += 1
					if tmp > 2: # 다른 문자 구성의 수가 2개 이상이 되면 비슷한 단어 아니기 때문에 더 이상 볼 필요 없음
						break
			if tmp <= 2:
				result += 1
			
      # s와 w의 길이가 다르다면 더 긴 문자열의 구성에서 다른 구성이 1개만 존재해야 함
      # 그래야 긴쪽에서 삭제 or 짧은 쪽에서 추가 해서 비슷한 단어 만들 수 있음
		else:
			tmp = 0		
			for i in range(26):
				if arr_s[i] != arr_w[i]:
					tmp += 1
					if tmp > 1: # 다른 문자 구성의 수가 1개 이상이 되면 비슷한 단어 아니기 때문에 더 이상 볼 필요 없음
						break
			if tmp <= 1:
				result += 1
	
	print(result)