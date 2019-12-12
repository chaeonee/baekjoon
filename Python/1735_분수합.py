def gcd(a, b): # 최대 공약수 구하는 함
	while(b != 0):
		tmp = a%b
		a = b
		b = tmp
		
	return a

if __name__ == '__main__':
	part = []
	for _ in range(2):
		part.append(list(map(int,input().split())))
		
	g = gcd(part[0][1], part[1][1]) # 최대공약수 구하기(분모 구하기 위)
	
	result = [0]*2
	a1 = part[0][1]/g
	a2 = part[1][1]/g
	
	result[0] = int(part[0][0] * a2 + part[1][0] * a1) # 분자(교차곱의 합)
	result[1] = int(a1 * a2 * g) # 분모(최소공배수)
	
	g = gcd(result[0],result[1]) # 약분을 위한 최대공약수 구하기
	if g != 1: # 최대 공약수가 1이면 약분할 필요 없고, 1이 아니면 약분 필요
		result[0] /= g
		result[1] /= g
	
	print(str(int(result[0])) + ' ' + str(int(result[1])))