#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	long long int dp[N]; // N의 범위가 90까지.. int 범위를 벗어남(돌려보니 피보나치일 때 46까지만 커버)
	dp[0] = 1; // 초기화
	
	if(N > 1){ // 초기화 (N이 1일때는 인덱스가 배열에 접근할 수 없으므로 조건문에 포함)
		dp[1] = 1;
	}
	
	for(int i = 2; i < N; i++){ // 피보나치 수열 계산
			dp[i] = dp[i-1] + dp[i-2];
	}
	
	cout << dp[N-1];
	
	return 0;
}
