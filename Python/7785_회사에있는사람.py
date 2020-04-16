if __name__ == '__main__':
	n = int(input())
	
	in_arr = {}
	for _ in range(n):
		name, state = list(input().split())
		
		if state == 'enter':
			in_arr[name] = 1
		elif state == 'leave':
			del in_arr[name]
			
	in_arr = sorted(in_arr.keys(),reverse=True)
	for key in in_arr:
		print(key)
