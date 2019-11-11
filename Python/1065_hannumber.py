if __name__ == "__main__":
	N = int(input())
	
	num = 0
	
	if N < 100:
		num = N # 100보다 작은 수는 모두 한수
		
	else:
		num = 99 # 100보다 작은 수는 모두 한수
		for i in range(100,N+1): # 100 이상의 수부터 한수 여부 확인
			diff = int(str(i)[1]) - int(str(i)[0]) # 첫 번째 두 번째 자리 수의 차를 기준으로 비교
			flag = True # True면 한수, False 이면 한수 아님
			for digit in range(2,len(str(i))):
				if diff != int(str(i)[digit]) - int(str(i)[digit-1]): # 다음 자리 수의 차와 기준 비교하여 다르면
					flag = False # 한수 아님
					break
			
			if flag == True: # 한수라면
				num += 1
				
	print(num)