#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int k;
	cin >> k;
	
	char ineq[k]; // 부등호 담을 배열
	for(int i = 0; i < k; i++){
		cin >> ineq[i];
	}
	
	int min_n[k+1] = {0,}, max_n[k+1] = {0,}; // 최소값은 내 뒤에 연속된 '>' 개수 세야하고 최대값은 내 뒤에 연속된 '<' 세야 함, 그 수를 담을 배열
	for(int i = 0; i < k; i++){
		char c = ineq[i];
		int j = i;
		while(c == '>'){ // 내 뒤에 '>' 세기
			min_n[i]++;
			c = ineq[++j];
		}
		
		c = ineq[i];
		j = i;
		while(c == '<'){ // 내 뒤에 '<' 세기
			max_n[i]++;
			c = ineq[++j];
		}
	}
	
	bool visit[10]; // 방문 확인 배열(한 번 출력한 애는 더 쓰면 안되기 때문)
	memset(visit,false,sizeof(bool)*10);
	for(int i = 0; i < k+1; i++){ // i 번째 큰 수 출력해야함(i는 0부터 시작)
		int tmp = 0, idx;
		for(int n = 9; n >= 0; n--){
			if(visit[n] == false){
				if(tmp == max_n[i]){
					idx = n;
					visit[n] = true;
					break;
				}
				tmp++;
				
			}
		}
		cout << idx;
	}cout << '\n';
	
	memset(visit,false,sizeof(bool)*10); // 최소값에는 최대값 출력과 별개이므로 다시 초기화
	for(int i = 0; i < k+1; i++){ // i 번째 작은 수 출력해야함(i는 0부터 시작)
		int tmp = 0, idx;
		for(int n = 0; n < 10; n++){
			if(visit[n] == false){
				if(tmp == min_n[i]){
					idx = n;
					visit[n] = true;
					break;
				}
				tmp++;
				
			}
		}
		cout << idx;
	}
	
	return 0;
}
