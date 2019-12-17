#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	int dp[k+1];
	for(int i = 0; i <= k; i++){
		dp[i] = 987654321; // 큰 값으로 초기화
	}
	
	dp[0] = 0; // dp[0]은 0으로 초기화
	for(int c = 0; c < n; c++){
		int coin;
		cin >> coin;
		
		for(int i = coin; i <= k; i++){ // 구하고자하는 가치가 현재 동전 가치보다 커야 동전을 사용할 수 있음
			dp[i] = min(dp[i],1+dp[i-coin]); // 현재 가치의 동전을 사용한 경우와 그렇지 않은 경우 중 더 작은 값을 dp에 저장
		}
	}
	
	if(dp[k] == 987654321){ // 만약 dp의 값이 갱신되지 않고 큰 값으로 남아 있다면, 현재 가지고 있는 동전으로 원하는 가치를 만들 수 없다는 의미
		dp[k] = -1; // dp[k]를 -1로 갱신
	}
	
	cout << dp[k];
	
	return 0;
}