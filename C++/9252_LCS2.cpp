#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void getLCS(char s1[], char s2[], int **dp){ // LCS를 구하기 위한 함수
	stack<char> s; // LCS를 담을 stack (문자열이 거꾸로 들어갈 것이기 때문에 stack을 사용하여 넣고 나중에 넣은 것부터 빼기)
	int x = strlen(s2), y = strlen(s1); // 맨 뒤 문자부터 역으로 추적할 것, 따라서 x,y는 dp배열의 마지막 좌표 값
	while(x != 0 && y != 0){ // x나 y 둘 중 하나라도 0이되면 탐색 종료
		if(s2[x-1] == s1[y-1]){ // 만약 두 문자가 같다면
			s.push(s1[y-1]); // 해당 문자 LCS에 추가하고
			x--;
			y--; // 대각선 위로 이동
		}
		else{ // 두 문자가 다를 때는 왼쪽 또는 위쪽으로 이동할 것 만약 둘 다 같다면 왼쪽 이동을 우선순위로 둘 것임
			if(dp[x][y-1] == dp[x][y]){ // 왼쪽 이동
				y--;
			}
			else{ // 위쪽 이동
				x--;
			}
		}
	}
	
	while(!s.empty()){ // stack에 넣은 lcs 빼면서 출력
		cout << s.top();
		s.pop();
	}
}

void lenLCS(char s1[], char s2[]){ // LCS의 길이를 구하기 위한 함수
	int len1, len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	
	int **dp = new int*[len2+1];
	for(int i = 0; i <= len2; i++){
		dp[i] = new int[len1+1];
	} // dp 배열 선언
	
	for(int i = 0; i <= len2; i++){
		for(int j = 0; j <= len1; j++){
			if(i == 0 || j == 0){ // 첫 번째 열과 첫번 째 행은 0(초기화를 먼저 해주고 i와 j를 1부터 진행해도 됨)
				dp[i][j] = 0;
				continue;
			}
			
			if(s1[j-1] == s2[i-1]){ // 만약 같은 문자라면
				dp[i][j] = dp[i-1][j-1] + 1; // 대각선 위쪽 값 + 1
			}
			else{ // 다른 문자라면 위쪽과 왼쪽 값 중에 큰 값 가져옴(왼쪽 값에 우선순위 둘 것임)
				if(dp[i][j-1] >= dp[i-1][j]){ // 왼쪽 값 가져오기
					dp[i][j] = dp[i][j-1];
				}
				else{ // 위쪽 값 가져오기
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	
	cout << dp[len2][len1] << '\n'; // dp 배열 마지막 값이 LCS의 길이가 됨
	
	if(dp[len2][len1] != 0){ // LCS의 길이가 0일때는 LCS를 출력할 필요가 없기 때문에 LCS의 길이가 0보다 클때 getLCS 진행하여 LCS 
		getLCS(s1,s2,dp);
	}
}

int main() {
	char s1[1001], s2[1001];
	cin >> s1 >> s2;
	
	lenLCS(s1,s2);
	
	return 0;
}
