if __name__ == '__main__':
	n = int(input())
	
	in_arr = {} # hash를 이용하기 위해 dictionary 자료형 사용
	for _ in range(n):
		name, state = list(input().split())
		
		if state == 'enter': # 'enter'이면 dictionary에 추가(key: 사람 이름, value: key와 같은 이름을 가진 사람이 몇 명 출근했는지(이 문제에서는 동명이인이 없으므로 value 값은 1이 될 것임))
			in_arr[name] = 1
		elif state == 'leave': # 아니라면 현재 dictionary에서 제거(동명이인이 있는 문제라면 value값도 확인해야 함)
			del in_arr[name]
			
	in_arr = sorted(in_arr.keys(),reverse=True) # 사전의 반대의 순서로 출력하기 위해 sorting 진행
	for key in in_arr:
		print(key)
