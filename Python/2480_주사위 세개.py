import collections

if __name__ == '__main__':
	num = list(map(int,input().split()))
	
	c = collections.Counter(num) # 같은 수 몇 개인지 알기 위함
	
	if c[num[0]] == 3: # 모두 같은 수
		print(10000+num[0]*1000)
	elif c[num[0]] == 2 or c[num[1]] == 2: # 하나만 다를 경우
		if c[num[0]] == 2:
			print(1000+num[0]*100)
		else:
			print(1000+num[1]*100)
	elif c[num[0]] == 1 and c[num[1]] == 1: # 모두 다를 경우
		num.sort()
		print(num[2]*100)