#include <iostream>
#include <cstring>
using namespace std;

void dfs(int s, int k, int d, int lotto[], bool visit[]); // 로또 숫자 선택을 위한 함수
void getLotto(int k, int lotto[], bool visit[]); // 로또 숫자 출력을 위한 함수

int main() {
	while(1){
		int k;
		cin >> k;

		if(k == 0){ // 0을 입력 받으면 종
			break;
		}
		
		int lotto[k];
		for(int i = 0; i < k; i++){
			cin >> lotto[i];
		}
		
		bool visit[k]; // 입력 받은 숫자를 사용하는 지 확인하기 위한 배열
		memset(visit,false,sizeof(bool)*k); // 초기화
		dfs(0,k,0,lotto,visit);
		cout << '\n';
	}
	
	return 0;
}

void dfs(int s, int k, int d, int lotto[], bool visit[]){
	if(d == 6){ // 깊이가 6이면 6개 모두 선택된 것
		getLotto(k,lotto,visit); // 따라서, 출력하고 종료
		return;
	}
	
	for(int i = s; i < k; i++){ // 한 층에 하나만 선택되도록 for문으로 선택
		visit[i] = true;
		dfs(i+1,k,d+1,lotto,visit); // 사전 순으로 선택되어야 하기 때문에 다음 선택은 현재 위치보다 뒷 쪽에 있는 숫자 선택
		visit[i] = false; // 백트래킹을 위함
	}
}

void getLotto(int k, int lotto[], bool visit[]){
	for(int i = 0; i < k; i++){
		if(visit[i] == true){ // 방문한 적이 있으면 출력
			cout << lotto[i] << ' ';
		}
	}
	
	cout << '\n';
}