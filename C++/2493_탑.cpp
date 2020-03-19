#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int top[N];
	for(int i = 0; i < N; i++){
		cin >> top[i];
	}
	
	for(int i = 0; i < N; i++){
		int receive = 0; // 앞 쪽에 현재 탑보다 높은 탑 없으면 0으로 출력하기 위해 0으로 초기화
		for(int j = i-1; j >= 0; j--){
			if(top[i] < top[j]){ // 내 앞쪽에 나보다 높은 탑 있으면 멈추고 위치 출력하기
				receive = j+1;
				break;
			}
		}
		cout << receive << " ";
	}
	
	return 0;
}
