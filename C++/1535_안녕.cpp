#include <iostream>
#include <algorithm>
using namespace std;

void hi(int N, int s, int hp[],int happy[], int s_hp, int s_happy, int& max_happy);

int main() {
	int N;
	cin >> N;
	
	int hp[N];
	for(int i = 0; i < N; i++){
		cin >> hp[i];
	}
	
	int happy[N];
	for(int i = 0; i < N; i++){
		cin >> happy[i];
	}
	
	int h = 0; //최대 기쁨
	hi(N,0,hp,happy,100,0,h);
	
	cout << h;
	
	return 0;
}

// 가능한 모든 경우의 수 구하는 문제처럼 풀기(순서 상관 없는)
void hi(int N, int s, int hp[],int happy[], int s_hp, int s_happy, int& max_happy){
	for(int i = s; i < N; i++){
		s_hp -= hp[i]; // 인사해서 체력 감소
		s_happy += happy[i]; .// 인사해서 기쁨 증가
		if(s_hp > 0){ // 세진이의 체력이 0보다 작거나 같으면 죽으니까 클 때만 비교, 작아지면 인사할 필요 없으니까 재귀 진행x
			max_happy = max(max_happy,s_happy);
			hi(N,i+1,hp,happy,s_hp,s_happy,max_happy);
		}
		s_hp += hp[i];
		s_happy -= happy[i];
	}
}