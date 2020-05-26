#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int **dp = new int*[N];
	for(int i = 0; i < N; i++){
		dp[i] = new int[11];
		memset(dp[i],0,sizeof(int)*11);
	} // 행은 자리수, 열은 맨 앞 자리의 수를 나타냄(초기 덧셈을 위한 열(1개) + 0~9 -> 총 11개)
	
	for(int i = 1; i < 11; i++){
		dp[0][i] = i;
	} // 초기 값 설정
	
	for(int i = 1; i < N; i++){
		for(int j = 1; j < 11; j++){
			int tmp = dp[i-1][10] - dp[i-1][j-1]; // dp[i-1][n]은 i-1자리수에서 0~n까지 경우의 수의 합을 의미 -> 따라서 j~n의 경우의 수의 합을 구하려면 dp[i-1][n] - dp[i-1][j-1] 계산 필요
			if(tmp < 0){ // c++은 음수 나머지가 생길 수 있음 이럴 때는 양수 나머지로 바꿔주기 위해 몫을 하나 더 빼준다고 생각하자!(python은 이것 고려할 필요 없음)
				tmp += 10007; // 몫 -1 하므로써 나머지가 +됨
			}
			dp[i][j] = (dp[i][j-1] + tmp) % 10007; // 둘을 더해서 나머지 나눈 값 저장
		}
	}
	
	cout << dp[N-1][10]; // 가장 마지막 값이 N자리의 오르막 수의 갯수
	
	return 0;
}
