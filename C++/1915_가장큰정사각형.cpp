#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int arr[n][m], dp[n][m]; // dp: 해당 위치를 오른쪽 끝으로 하는 정사각형 중 가장 큰 정사각형의 변의 길이
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &arr[i][j]);
			dp[i][j] = 0;
		}
	} // 입력 받기 및 초기화
	
	int s_max = 0; // 한 변 길이의 최대 값 저장하기 위한 변수
	for(int i = 0; i < m; i++){
		if(arr[0][i]){
			dp[0][i] = 1;
			s_max = 1;
		}
	} // 초기화: arr의 값이 1이라면 한 변의 길이가 1인 정사각형 만들 수 있음 -> 한 변 길이의 최댓값을 1로 갱신해주어야 함
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j]){ // 현재 위치가 1이여야 현재 위치를 오른쪽 아래로 하는 정사각형 만들 수 있음
				if(j == 0){ // j가 0인 경우 현재 위치가 오른쪽 끝인 정사각형의 한 변의 길이는 1(본인만 포함) 
					dp[i][j] = 1;
					continue;
				}
				
				if(arr[i-1][j] && arr[i][j-1] && arr[i-1][j-1]){ // 현재 위치의 위, 왼쪽, 대각선 위가 모두 1인지 확인
					dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1; // 모두 1이라면 위, 왼쪽, 대각선 위 중 최솟값 + 1이 최댓값이 됨(정사각형이 되려면 범위의 모든 값이 1이여야 하고, 범위의 모든 값이 1로 채워지려면 이들의 최솟값만큼이 되어야 함)
				}
				else{ // 모두 1이 아니라면
					dp[i][j] = 1; // 현재 위치만 포함하는 정사각형이 현재 위치에서 만들 수 있는 정사각형의 최대
				}
			}
			
			if(s_max < dp[i][j]){ // 최댓값 비교 후 갱신
				s_max = dp[i][j];
			}
		}
	}
	
	cout << s_max*s_max; // 구한 최댓값은 변의 길이이므로, 제곱을 해 줘야 넓이가 됨
	
	return 0;
}
