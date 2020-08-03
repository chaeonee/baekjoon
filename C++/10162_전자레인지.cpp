#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	if(T % 10 != 0){
		cout << -1;
		return 0;
	}
	
	int button[3] = {300,60,10}; // 각 버튼을 눌렀을 때 수행되는 시간(단위 모두 초로 일치)
	int num_push[3] = {0,}; // 버튼 누른 횟수
	for(int i = 0; i < 3; i++){ // 시간이 오래걸리는 버튼 먼저 누르기
		num_push[i] = T / button[i]; // 남은 시간이 T일 때, 해당 버튼을 최대 몇 번 누를 수 있는지(몫으로 표현)
		T -= num_push[i]*button[i]; // 버튼 누른만큼 요리 시간 감소(나머지로 표현 가능)
		
		if(T == 0){ // 요리 시간만큼 버튼 모두 눌렀으면
			break; // 더 작은 초 단위의 버튼 볼 필요 없음
		}
	}
	
	for(int i = 0; i < 3; i++){ // 각 버튼을 몇 번 눌렀는지 출력
		cout << num_push[i] << " ";
	}
	
	return 0;
}
