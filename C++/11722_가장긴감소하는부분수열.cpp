#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int A[N], dp[N] = {0,}, result = 0; // dp: 현재 위치의 가장 긴 감소하는 부분수열의 길이 저장할 배열, result: 가장 긴 감소하는 부분수열의 길이
	for(int n = 0; n < N; n++){
		cin >> A[n];
		
		int max_n = 0; // 앞쪽 배열 중 부분수열의 최대 길이 저장
		for(int i = n-1; i >= 0; i--){ // 현재 값보다 앞쪽에 위치하는 값 탐색
			if(A[n] < A[i] && max_n < dp[i]){ // 현재 값보다 더 크고 부분수열의 길이가 가장 긴 값 찾기
				max_n = dp[i];
			}
		}
		dp[n] = max_n+1; // +1해준 이유: 나 자신까지 포함시켜주기 위함
		
		if(result < dp[n]){ // 가장 긴 감소하는 부분수열을 찾기 위해서는 감소하는 부분수열의 최대값을 찾아야 함
			result = dp[n];
		}
	}
	
	cout << result;
	
	return 0;
}
