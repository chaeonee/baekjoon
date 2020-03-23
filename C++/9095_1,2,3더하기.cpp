#include <iostream>
using namespace std;

int getSum(int n, int cnt){
	if(n == 0){ // n == 0: 1,2,3으로 이루어진 더하기 모두 완성
		return cnt+1;
	}
	
	for(int i = 1; i <= 3; i++){
		if(n-i >= 0){ // n-i가 0보다 작으면 최종적으로 n보다 큰 덧셈 만들어짐, 따라서 조건문으로 걸러줌
			cnt = getSum(n-i,cnt); // +i로 만들어주고 n에서 i빼줌(이를 재귀적으로 수행)
		}
	}
	
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		
		cout << getSum(n,0) << "\n";
	}
	
	return 0;
}
