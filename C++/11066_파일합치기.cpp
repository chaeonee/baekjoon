#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int N;
		cin >> N;
		int *arr = new int[N]; // 비용 넣을 것
		int **dp = new int*[N]; // dp[i][j]는 i부터 j까지 합칠 때의 비용
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			dp[i] = new int[N];
			memset(dp[i],0,sizeof(int)*N);
		}
		
		for(int i = 0; i < N-1; i++){
			dp[i][i+1] = arr[i]+arr[i+1]; // 주 대각선에서 하나 차이 나는 대각선은 두 값의 합으로 초기화
		}
		
		int dist = 2;
		int i = 0;
		while(i+dist < N){ // 대각선으로 행렬 이동하기 위함
			for(i; i < N; i++){
				int j = i+dist;
				if(j >= N){
					break;
				}
				int tmp = 100000000;
				for(int k = i; k < j; k++){
					if(dp[i][k]+dp[k+1][j] < tmp){
						tmp = dp[i][k]+dp[k+1][j]; // i <= k < j 순회하면서 가장 작은 값 구해서 tmp에 저장하기
					}
				}
				dp[i][j] = tmp; // 가장 작은 값과 i~j의 arr값을 모두 더해줌
				for(int k = i; k <= j; k++){
					dp[i][j] += arr[k];
				}
			}
			i = 0;
			dist++;
		}
		
		cout << dp[0][N-1] << '\n';
	}
	return 0;
}
