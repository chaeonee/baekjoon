import math
if __name__ == '__main__':
	N = int(input())
	
	S1 = input()
	s1_arr = [0]*26
	for s1 in S1:
		s1_arr[ord(s1)-65] += 1 # 첫 번째 단어의 알파벳 세기
		
	result = 0
	for _ in range(N-1):
		S2 = input()
		s2_arr = [0]*26
		for s2 in S2:
			s2_arr[ord(s2)-65] += 1 # 비교할 단어의 알파벳 세기
		
		if abs(len(s1_arr)-len(s2_arr)) < 2: # 둘의 길이가 1이상 차이날 때는 비슷한 단어가 될 수 없음
			s_sub1 = 0 # 첫 번째 단어에만 존재하는 알파벳의 개수
			s_sub2 = 0 # 비교할 단어에만 존재하는 알파벳의 개수(만약 같은 알파벳이 2개 더 존재하면, 2로 counting)
			result += 1 # 일단, 두 단어가 비슷한 단어라고 가정
			for i in range(26):
				if s1_arr[i] - s2_arr[i] > 0: # 첫 번째 단어에만 존재하는 알파벳이 있을 경우
					s_sub1 += s1_arr[i] - s2_arr[i]
				else: # 비교할 단어에만 존재하는 알파벳이 있을 경우
					s_sub2 += s2_arr[i] - s1_arr[i]
				if s_sub1 > 1 or s_sub2 > 1: # 둘 중 하나라도 1이 넘어간다면 비슷한 단어가 될 수 없음
					result -= 1 # 두 단어가 비슷한 단어라는 가정을 하고 result를 1 증가시켰기 때문에 1 감소 시켜줘야 함
					break # 현재 단어는 더이상 비교할 필요 없기 때문에 break 후 다음 단어 비교
	
	print(result)
