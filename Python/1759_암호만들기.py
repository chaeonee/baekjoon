import sys

def getPwd(L,C,letter,pwd,c,v,s):
	if len(pwd) == L: # 암호의 길이 조건을 만족하고
		if c <= 0 and v <= 0: # 최소 2번의 자음, 최소 1번의 모음을 사용했을 때
			print(pwd) # 암호 조건 만족하므로 출력
		return
	
	i = s # 시작 위치 지정을 위한 인덱스 값
	for x in letter[s:]:
		pwd += x # 현재 문자 값 암호에 추가
		i += 1 # 인덱스 값 1 증가
		if x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u': # 현재 문자가 모음일 때
			getPwd(L,C,letter,pwd,c,v-1,i) # 재귀(모음의 최소 사용 값 1 감소)
		else: # 현재 문자가 자음일 때
			getPwd(L,C,letter,pwd,c-1,v,i) # 재귀(자음의 최소 사용 값 1 감소)
		pwd = pwd[:-1] # 현재 추가한 문자 제거
	
if __name__ == '__main__':
	L, C = list(map(int,sys.stdin.readline().split()))
	letter = sys.stdin.readline().split()
	letter = sorted(letter)
	
	getPwd(L,C,letter,'',2,1,0)
