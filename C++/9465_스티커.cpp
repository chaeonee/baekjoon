#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		
		int sticker[2][n+1];
		for(int i = 0; i < 2; i++){
			for(int j = 1; j <= n; j++){
				cin >> sticker[i][j];
			}
		}
		
		int score[2][n];
		score[0][0] = 0;
		score[1][0] = 0;
		score[0][1] = sticker[0][1];
		score[1][1] = sticker[1][1]; // 0의 위치는 0으로, 1의 위치는 각 위치의 점수로 초기화
		
		for(int i = 2; i <= n; i++){
			score[0][i] = sticker[0][i] + max(score[1][i-1],score[1][i-2]);
			score[1][i] = sticker[1][i] + max(score[0][i-1],score[0][i-2]);
		} // 대각선 위 또는 두 번째 대각선 위 중 더 큰 값과 현재 위치의 점수를 더해 줌
		  // (더 이전의 대각선과 같은 행의 두 칸 이상 차이나는 열은 다른 곳에서 이미 정보를 담고 있기 때문에 이 둘만 확인하면 )
		
		cout << max(score[0][n], score[1][n]) << '\n'; // 마지막 열 둘 중에 최댓 값을 취함
		
	}
	
	return 0;
}