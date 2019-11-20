def getMin2(dice):
	s_min = 1000000
	for i in range(0,6):
		for j in range(i+1,6):
			if i+j != 5:
				tmp = dice[i]+dice[j]
				if s_min > tmp:
					s_min = tmp
		
	return s_min

def getMin3(dice):
	s_min = 0
	for i in range(0,3):
		s_min += min(dice[i],dice[5-i])
	return s_min

if __name__ == "__main__":
	N = int(input())
	dice = input()
	
	dice = dice.split()
	dice = [int(i) for i in dice]
	
	result = 0
	if N == 1: # 주사위가 한 개만 있을 때 예외처리
		result = sum(dice)
		result -= max(dice) # 5면만 보이니까 전체에서 가장 큰 면 빼주기
	else:
		n1 = (N-2)*(5*N-6)
		n2 = 4*(2*N-3)
		n3 = 4
		
		#한 개만 보이는 경우-최솟값이 보이게
		result = min(dice)*n1
		#두 개 보이는 경우 - 마주보는 것 제외하고 두 개 선택해서 합이 최소가 되는 것 선택
		result += getMin2(dice)*n2
		#세 개 보이는 경우 - 마주보는 각 쌍에 대해 더 작은 값 선택해서 더함
		result += getMin3(dice)*n3
		
	print(result)