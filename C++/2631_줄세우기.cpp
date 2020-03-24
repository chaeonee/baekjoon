#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int max = 0, child[N], dp[N]; // max: 최대 길이를 저장할 변수, child: 아이들의 번호를 순서대로 저정할 배열, dp: 가장 긴 부분 수열의 길이를 저장하기 위한 배열
	for(int n = 0; n < N; n++){
		cin >> child[n];
		dp[n] = 1; // 자기 자신만 부분 수열에 포함될 때의 길이가 1이므로 1로 초기화
		
		for(int i = 0; i <n; i++){ // 현재 아이의 앞쪽에 있는 아이들의 번호 확인
			if(child[n] > child[i] && dp[n] < dp[i]+1){ // 번호가 앞쪽 번호이고 현재 가장 긴 부분 수열보다 더 길다면
				dp[n] = dp[i]+1; // 가장 긴 부분 수열의 길이 수정(+1은 자기 자신)
			}
		}
		
		if(dp[n] > max){ // 최대값 저장해 놓기 위함
			max = dp[n];
		}
	}
	
	cout << N-max; // 아이들이 최소로 움직이기 위해서는 가장 긴 부분 수열을 구하고 가장 긴 부분 수열에 포함되지 않는 아이들만 이동, 따라서 전체 아이들 수에서 가장 긴 부분 수열에 포함되는 아이들의 수를 빼주기 
	
	return 0;
}
