#include <iostream>
using namespace std;

int go(int N, int **board, int max, int m_num);
bool slide(int N, int **board, int dir, bool flag);
bool merge(int N, int &max, int **board, int dir, bool flag);
void copy(int N, int **a, int **b);

int main() {
	int N;
	cin >> N;
	
	int **board = new int*[N];
	for(int i = 0; i < N; i++){
		board[i] = new int[N];
	}
	
	int max = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
			
			if(board[i][j] > max){
				max = board[i][j];
			}
		}
	}
	
	max = go(N, board, max, 0);
	
	cout << max;
	
	return 0;
}

int go(int N, int **board, int max, int m_num){
	if(m_num == 5){
		return max;
	}
	
	int **copy_board = new int*[N];
	for(int i = 0; i < N; i++){
		copy_board[i] = new int[N];
	}
	copy(N, copy_board, board);
	
	for(int d = 0; d < 4; d++){
		bool flag = false;
		flag = slide(N, board, d, flag);
		flag = merge(N, max, board, d, flag);
		flag = slide(N, board, d, flag);
		//for(int i=0;i<N;i++){for(int j=0;j<N;j++){cout<<board[i][j]<<" ";}cout<<endl;}cout<<endl;
		
		if(flag == true){
			max = go(N, board, max, m_num+1);
			copy(N, board, copy_board);
		}
	}
	
	return max;
}

bool slide(int N, int **board, int dir, bool flag){
	if(dir == 0){
		for(int i = 1; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] != 0){
					int tmp = i-1;
					while(tmp >= 0){
						if(board[tmp][j] != 0){
							break;
						}
						tmp--;
					}
					if(tmp != i-1){
						flag = true;
						board[tmp+1][j] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	else if(dir == 1){
		for(int i = N-2; i >= 0; i--){
			for(int j = 0; j < N; j++){
				if(board[i][j] != 0){
					int tmp = i+1;
					while(tmp < N){
						if(board[tmp][j] != 0){
							break;
						}
						tmp++;
					}
					if(tmp != i+1){
						flag = true;
						board[tmp-1][j] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	else if(dir == 2){
		for(int j = 1; j < N; j++){
			for(int i = 0; i < N; i++){
				if(board[i][j] != 0){
					int tmp = j-1;
					while(tmp >= 0){
						if(board[i][tmp] != 0){
							break;
						}
						tmp--;
					}
					if(tmp != j-1){
						flag = true;
						board[i][tmp+1] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	else{
		for(int j = N-2; j >= 0; j--){
			for(int i = 0; i < N; i++){
				if(board[i][j] != 0){
					int tmp = j+1;
					while(tmp < N){
						if(board[i][tmp] != 0){
							break;
						}
						tmp++;
					}
					if(tmp != j+1){
						flag = true;
						board[i][tmp-1] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	
	return flag;
}

bool merge(int N, int &max, int **board, int dir, bool flag){
	if (dir == 0){
		for(int i = 1; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] != 0 && board[i][j] == board[i-1][j]){
					flag = true;
					board[i-1][j] *= 2;
					board[i][j] = 0;
					
					if(board[i-1][j] > max){
						max = board[i-1][j];
					}
				}
			}
		}
	}
	else if(dir == 1){
		for(int i = N-2; i >= 0; i--){
			for(int j = 0; j < N; j++){
				if(board[i][j] != 0 && board[i][j] == board[i+1][j]){
					flag = true;
					board[i+1][j] *= 2;
					board[i][j] = 0;
					
					if(board[i+1][j] > max){
						max = board[i+1][j];
					}
				}
			}
		}
	}
	else if(dir == 2){
		for(int j = 1; j < N; j++){
			for(int i = 0; i < N; i++){
				if(board[i][j] != 0 && board[i][j] == board[i][j-1]){
					flag = true;
					board[i][j-1] *= 2;
					board[i][j] = 0;
					
					if(board[i][j-1] > max){
						max = board[i][j-1];
					}
				}
			}
		}
	}
	else{
		for(int j = N-2; j >= 0; j--){
			for(int i = 0; i < N; i++){
				if(board[i][j] != 0 && board[i][j] == board[i][j+1]){
					flag = true;
					board[i][j+1] *= 2;
					board[i][j] = 0;
					
					if(board[i][j+1] > max){
						max = board[i][j+1];
					}
				}
			}
		}
	}
	
	return flag;
}

void copy(int N, int **a, int **b){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			a[i][j] = b[i][j];
		}
	}
}
