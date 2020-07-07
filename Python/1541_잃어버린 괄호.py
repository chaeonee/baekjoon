import sys

if __name__ == '__main__':
	formula = sys.stdin.readline()
	
	str_num = ''
	oper = []
	num = []
	for f in formula:
		if f == '+' or f == '-': # 연산자 만났을 때
			oper.append(f) # 연산자 저장
			num.append(int(str_num)) # 이전까지 합쳐진 숫자 형태의 문자 숫자로 변환하여 저장
			str_num = '' # 숫자 저장할 문자열 비우기
		else: # 숫자 만났을 때
			str_num += f # 숫자 역시 문자로 받았으므로 문자 concat하듯 합치기
	num.append(int(str_num)) # 마지막 숫자 넣어주기 위함
	
	idx = 0 # 식 계산을 위한 인덱스
	result = num[0] # 가장 앞에 위치한 숫자 초기 값으로 설정
	while idx < len(oper): # 인덱스가 범위를 넘어가기 전까지 루프 수행
		if oper[idx] == '+': # '+' 만났을 때, (현재 위치 앞쪽에 '-'가 없고, '+'를 만난 경우를 의미)
			result += num[idx+1] # 결과 값에 숫자 더해주기(인덱스 주의! 연산자가 숫자보다 1개 적을 것)
			idx += 1 # 인덱스 증가
			continue
		
		# '-' 만난 경우
		sub = num[idx+1] # 부분 합
		tmp_idx = idx + 1 # 부분 합을 위한 인덱스
		while tmp_idx < len(oper) and oper[tmp_idx] == '+': # '-'만나거나 더 이상 계산할 숫자가 없을 때까지(식의 끝)
			sub += num[tmp_idx+1] # 부분 합 구하기
			tmp_idx += 1
		result -= sub # 부분합 모두 구한 후 전체 결과에서 부분 합 빼주고
		idx = tmp_idx # 인덱스 갱신(부분 합 구한 부분 건너 뛰고 다음부터 구해주어야 하기 때문)
		
	print(result)
