import sys
from collections import deque

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	
	q = deque()
	for _ in range(N):
		arr = sys.stdin.readline().split()
		if arr[0] == 'push': # push 명령어
			q.append(int(arr[1])) # q에 해당 정수 입력
		elif arr[0] == 'pop': # pop 명령어
			if q: # q가 비어있지 않다면
				print(q.popleft()) # pop 진행(python은 pop할 때 pop한 값도 함께 return됨)
			else: # 비어있다면
				print(-1) # -1 출력
		elif arr[0] == 'size': # size 명령어
			print(len(q)) # 길이 출력(q의 길이가 q의 size가 됨)
		elif arr[0] == 'empty': # empty 명령어
			if q: # q가 비어있지 않다면
				print(0) # 0 출력
			else: # 비어있다면
				print(1) # 1 출력
		elif arr[0] == 'front': # front 명령어
			if q: # q가 비어있지 않다면
				print(q[0]) # q의 맨 앞 값 출력
			else: # 비어있다면
				print(-1) # -1 출력
		elif arr[0] == 'back': # back 명령어
			if q: # q가 비어있지 않다면
				print(q[-1]) # q의 맨 뒷 값 출력
			else: # 비어있다면
				print(-1) # -1 출력
