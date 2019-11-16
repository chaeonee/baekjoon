if __name__ == '__main__':
	N = int(input())

	num = input()
	num = num.split()

	sum = 0
	for i in range(N):
		sum += int(num[i])

	result = 0
	for i in range(N):
		sum -= int(num[i])
		result += int(num[i])*sum

	print(result)
