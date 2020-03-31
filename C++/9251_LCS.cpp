#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s1[1001], s2[1001];
	cin >> s1 >> s2;
	
	int N, M;
	N = strlen(s1);
	M = strlen(s2);
	
	int **dp = new int*[M+1];
	for(int i = 0; i < M+1; i++){
		dp[i] = new int[N+1];
	} // 2개의 문자열의 길이 + 1의 크기만큼 2차원 dp배열 만들기
	for(int i = 0; i < M+1; i++){
		dp[i][0] = 0;
	} // 첫 번째 열 0으로 초기화
	for(int i = 0; i < N+1; i++){
		dp[0][i] = 0;
	} // 첫 번째 행 0으로 초기화
	
	for(int i = 1; i < M+1; i++){
		for(int j = 1; j < N+1; j++){ // 첫 번째 행, 열은 0으로 고정하고 1부터 시작
			if(s1[j-1] == s2[i-1]){ // 문자열 같을 때
				dp[i][j] = dp[i-1][j-1]+1; // 배열의 대각선 값 + 1
			}
			else{ // 문자열 다를 때는 배열의 위 또는 왼쪽 값 중 큰 것 가져오기(같다면 왼쪽값 가져오기로 함)
				if(dp[i][j-1] >= dp[i-1][j]){
					dp[i][j] = dp[i][j-1];
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	
	cout << dp[M][N]; // dp배열의 마지막 값(오른쪽 아래 값)이 최종 LCS의 길이
	
	return 0;
}
