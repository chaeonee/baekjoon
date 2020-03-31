#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int dp[N+1]; // 크기가 N+1인 dp배열(0까지 포함, 0의 값은 변화하지 않을 것임) 
	for(int i = 0; i <= N; i++){
		dp[i] = 1;
	} // dp 배열 1로 모두 초기화(k가 1일 때)
	
	for(int k = 1; k < K; k++){
		for(int i = 1; i <= N; i++){
			dp[i] = (dp[i]+dp[i-1])%1000000000; // 현재 위치의 dp배열 값 이전 위치의 dp배열 값을 더한 후 1000000000로 나눈 나머지 값을 저장
		}
	}
	
	cout << dp[N];
	
	return 0;
}
