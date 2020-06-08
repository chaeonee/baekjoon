#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int dp[n] = {0,};
	dp[0] = 1;
	
	if(n > 1){
		dp[1] = 3;
	} // n이 1일 때 초기화 에러를 막기 위함
	
	for(int i = 2; i < n; i++){ // 타일의 가로 길이 1 or 2 -> n-1, n-2 이용 / n-2의 경우의 수 2*1와 2*2, 2개 이므로 *2 필요
		dp[i] = (dp[i-1] + ((dp[i-2]) * 2) % 10007) % 10007;
	}
	
	cout << dp[n-1];
	
	return 0;
}
