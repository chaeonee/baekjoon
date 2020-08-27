#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	char board[N][M];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
	
	int num = 5000; // 다시 칠할 체스판 칸의 수 중 최솟값을 저장
	for(int x = 0; x < N-7; x++){
		for(int y = 0; y < M-7; y++){ // 체스판 왼쪽 위의 좌표(8*8 크기의 체스판을 만들어야 하기 때문에 시작점 뒤에 최소 7칸은 존재해야 함)
			char col; // 체스판의 해당 칸에 칠해야 하는 색깔
			
			int tmp = 0; // 다시 칠할 체스판 칸의 수
			for(int i = x; i < x+8; i++){
				if(i%2 == 0){
					col = 'W';
				}
				else{
					col = 'B';
				} // 짝수 행은 흰색으로 시작, 홀수 행은 검정색으로 시작
				for(int j = y; j < y+8; j++){
					if(board[i][j] != col){ // 체스판의 현재 칸의 색이 원래 칠해져야 하는 색과 다른 색이면
						tmp++; // 다시 칠해야 함
					}
					
					// 인접한 칸이 같은 색이면 안되기 때문에
					if(col == 'B'){ // 해당 칸의 색이 검정색이면
						col = 'W'; // 다음 칸은 흰색으로 바꿔줘야 함
					}
					else{ // 해당 칸의 색이 흰색이면
						col = 'B'; // 다음 칸은 검정색으로 바꿔줘야 함
					}
				}
			}
			
			if(num > tmp){
				num = tmp;
			} // 다시 칠할 체스판의 칸의 수의 최솟값 갱신
			
			tmp = 0;
			for(int i = x; i < x+8; i++){
				if(i%2 == 0){
					col = 'B';
				}
				else{
					col = 'W';
				} // 짝수 행은 검정색으로 시작, 홀수 행은 흰색으로 시작
				for(int j = y; j < y+8; j++){
					if(board[i][j] != col){ // 체스판의 현재 칸의 색이 원래 칠해져야 하는 색과 다른 색이면
						tmp++; // 다시 칠해야 함
					}
					
					// 인접한 칸이 같은 색이면 안되기 때문에
					if(col == 'W'){ // 해당 칸의 색이 흰색이면
						col = 'B'; // 다음 칸은 검정색으로 바꿔줘야 함
					}
					else{ // 해당 칸의 색이 검정색이면
						col = 'W'; // 다음 칸은 흰색으로 바꿔줘야 함
					}
				}
			}
			
			if(num > tmp){
				num = tmp;
			} // 다시 칠할 체스판의 칸의 수의 최솟값 갱신
		}
	}
	
	cout << num;
	
	return 0;
}
