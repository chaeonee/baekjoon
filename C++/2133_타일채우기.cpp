#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	if(N % 2 != 0){ // N이 홀수라면
		cout << 0; // 0 출력
		return 0;
	}
	
	// N이 짝수일 때(홀수 예외처리 해주었기 때문에 인덱스 N/2로 -> 홀수 없애기)
	N /= 2;
	
	int dp[N+1];
	dp[0] = 1; // dp[0]일 때 1로 초기화
	for(int i = 1; i <= N; i++){
		dp[i] = dp[i-1] * 3; // 이전 경우의 수 * 3(N이 2일 때 경우의 수)
		for(int j = 0; j < i-1; j++){ // 가운데를 가로지르는 경우가 오른쪽에 있는 경우, 오른쪽의 길이가 4~N일 때이므로 왼쪽 경우 0부터 i-2까지 돌아야 함
			dp[i] += dp[j] * 2; // 이전 경우의 수 * 2(가로지르는 경우의 수가 2개임)
		}
	}
	
	cout << dp[N];
	
	return 0;
}
