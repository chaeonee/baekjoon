from collections import Counter

if __name__ == "__main__":
	S = input()
	
	S = Counter(S.upper()) # 모두 대문자로 바꿔서 알파벳 개수 세기
	
	if len(S) > 1: #종류가 2개 이상이면 가장 많이 등장한 것 2개만 비교
		S = S.most_common(2)
		if(S[0][1] == S[1][1]): #가장 많이 등장한 것의 등장 횟수 동일하면 '?'
			print('?')
		else: # 등장 횟수 다르면 가장 많이 등장한 것 출력
			print(S[0][0])
	else: # 종류가 1개면 무조건 출력
		S = S.most_common(1)
		print(S[0][0])