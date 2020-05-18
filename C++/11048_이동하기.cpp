#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int **candy = new int*[N]; // 각 위치의 사탕 개수를 담기 위한 배열
	int **dp = new int*[N]; // 현재 위치에서 얻을 수 있는 사탕의 최댓값 저장하는 dp배열
	for(int i = 0; i < N; i++){
		candy[i] = new int[M];
		dp[i] = new int[M];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			dp[i][j] = 0;
			cin >> candy[i][j];
		}
	}
	
	int dir[3][2] = {{-1,0},{0,-1},{-1,-1}}; // 현재 위치 바로 이전에 올 수 있는 좌표 표시를 위한 방향
	dp[0][0] = candy[0][0]; // dp[0][0]은 candy[0][0] 값으로 초기화
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int n_candy = candy[i][j]; // 현재 위치의 사탕 수
			for(int d = 0; d < 3; d++){
				int x = i+dir[d][0], y = j+dir[d][1]; // 위, 왼쪽, 왼쪽 대각선 위의 dp 값을 살펴볼 것
				if(x >= 0 && y >= 0){ // 이들이 모두 범위 안에 존재해야 함
					if(dp[x][y]+n_candy > dp[i][j]){ // 위, 왼쪽, 왼쪽 대각선 위 중 최대값을 구해 현재 위치의 사탕 수와 더해 줌
						dp[i][j] = dp[x][y]+n_candy;
					}
				}
			}
		}
	}
	
	cout << dp[N-1][M-1];
	
	return 0;
}
