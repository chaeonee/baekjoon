#include <iostream>
#include <algorithm>
using namespace std;

struct Egg{
	int s, w;
}; // 계란의 내구성, 무게를 담을 struct

void breakingEgg(int N, int s, Egg *egg, int &n_broken, int cur_broken);

int main() {
	int N;
	cin >> N;
	
	Egg *egg = new Egg[N];
	for(int i = 0; i < N; i++){
		cin >> egg[i].s >> egg[i].w;
	}
	
	int n_broken = 0; // 깨진 계란의 최대값 담을 변수
	breakingEgg(N,0,egg,n_broken,0);
	cout << n_broken;
	
	return 0;
}

void breakingEgg(int N, int s, Egg *egg, int &n_broken, int cur_broken){
	if(s == N){ // 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우
		return; // 더 이상 진행하지 않고 종료
	}
	
	if(egg[s].s <= 0){ // 현재 들고 있는 계란이 깨진 계란일 경우
		breakingEgg(N,s+1,egg,n_broken,cur_broken); // 다음 계란으로 넘어가기
		return;
	}
	
	// 현재 들고 있는 계란이 깨지지 않은 계란일 경우
	for(int i = 0; i < N; i++){ // 계란 선택
		if(i == s || egg[i].s <= 0){ // 선택한 계란이 들고 있는 계란과 같은 계란이거나, 깨진 계란일 경우
			continue; // 아무 것도 수행하지 않고 다음 계란 선택하러 이동..ㅎ
		}
		
		egg[i].s -= egg[s].w;
		egg[s].s -= egg[i].w; // 충돌하면 상대 계란의 무게만큼 내구성 감소
		
		int sub = 0; // 현재 충돌로 인해 몇 개의 계란이 깨졌는지
		if(egg[i].s <= 0){ // 선택한 계란이 깨졌는지 확인
			sub++;
		}
		if(egg[s].s <= 0){ // 들고 있던 계란이 깨졌는지 확인
			sub++;
		}
		cur_broken += sub; // 현재 충돌로 인해 깨진 계란만큼 깨진 계란의 수 증가
		n_broken = max(n_broken,cur_broken); // 깨진 계란의 최대 개수 갱신
		
		breakingEgg(N,s+1,egg,n_broken,cur_broken); // 현재 들고 있는 계란 놓고 다음 계란 들기
		
		egg[i].s += egg[s].w;
		egg[s].s += egg[i].w;
		cur_broken -= sub; // 백트래킹
	}
}
