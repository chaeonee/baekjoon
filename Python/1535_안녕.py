max_happy = 0

def hi(N,s,hp,happy,s_hp,s_happy):
	global max_happy #최대 행복을 전역변수로 선언해서 바꿔줌
	
	for i in range(s,N): # i번째 사람과 인사했다고 가정
		s_happy += happy[i] # 인사해서 기쁨 증가
		s_hp -= hp[i] # 인사해서 체력 감소
		
		if s_hp > 0: # 세진이의 체력은 0보다 커야함(아니면 죽음..ㅠ)
			max_happy = max(max_happy,s_happy)
			hi(N,i+1,hp,happy,s_hp,s_happy)
			
		s_happy -= happy[i]
		s_hp += hp[i]

if __name__ == '__main__':
	N = int(input())
	hp = list(map(int,input().split()))
	happy = list(map(int,input().split()))
	
	hi(N,0,hp,happy,100,0) # 세진이의 체력 초기값은 100, 세진이의 기쁨 초기 값은 0
	
	print(max_happy)