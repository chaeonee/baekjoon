#include <iostream>
#include <deque>
using namespace std;

struct Pos{
	int x, y;
}; // 위치 나타내기 위함

struct Dir{
	int num, dir;
}; // 해당 말의 번호와 방향 나타내기 위함

void moveWhite(int idx, Pos p, int x, int y, deque<Dir> **chess, Pos *pos);
void moveRed(int idx, Pos p, int x, int y, deque<Dir> **chess, Pos *pos);

int main() {
	int N, K;
	cin >> N >> K;
	
	int **board = new int*[N];
	deque<Dir> **chess = new deque<Dir>*[N]; //해당 위치에 존재하는 말들을 담을 deque 배열
	for(int i = 0; i < N; i++){
		board[i] = new int[N];
		chess[i] = new deque<Dir>[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	Pos *pos = new Pos[K]; // K개의 말의 위치 저장
	for(int k = 0; k < K; k++){
		int x, y, dir;
		cin >> x >> y >> dir;
		chess[x-1][y-1].push_back({k,dir-1});
		pos[k] = {x-1,y-1};
	}
	
	int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; // 1,2,3,4 방향
	int r_dir[4] = {1,0,3,2}; // 방향이 반대로 바뀔 때의 인덱스
	
	int turn = 0; // 수행한 턴의 수를 나타낼 변수
	while(turn++ < 1000){ // 1000번 이상 진행되면 더이상 진행하지 
		for(int k = 0; k < K; k++){ // 말을 순서대로 이동
			Pos p = pos[k];
			int idx = 0; 
			for(idx; idx < chess[p.x][p.y].size(); idx++){ // 말이 현재 위치에서 몇번째 순서에 위치하는지 알아야 함
				if(chess[p.x][p.y][idx].num == k){
					break;
				}
			}
			int x = p.x+dir[chess[p.x][p.y][idx].dir][0], y = p.y+dir[chess[p.x][p.y][idx].dir][1]; // 현재 말이 이동해야 하는 방향으로 이동한 좌표
			if(x >= 0 && x < N && y >= 0 && y < N){ // 범위 내에 있을 때
				if(board[x][y] == 0){ // 흰색으로 이동하려고 할 때
					moveWhite(idx,p,x,y,chess,pos);
					if(chess[x][y].size() >= 4){ // 종료조건: 4개 이상의 말이 모여있을 때
						cout << turn; // 턴 출력 후 종료
						return 0;
					}
				}
				else if(board[x][y] == 1){ 빨간색으로 이동하려고 할 때
					moveRed(idx,p,x,y,chess,pos);
					if(chess[x][y].size() >= 4){ // 종료조건: 4개 이상의 말이 모여있을 때
						cout << turn; // 턴 출력 후 종료
						return 0;
					}
				}
				else if(board[x][y] == 2){ 파란색으로 이동하려고 할 때
					chess[p.x][p.y][idx].dir = r_dir[chess[p.x][p.y][idx].dir]; // 현재 말의 방향을 반대로 바꿔줘야 함(이전에 선언해놓은 배열 이용)
					x = p.x+dir[chess[p.x][p.y][idx].dir][0], y = p.y+dir[chess[p.x][p.y][idx].dir][1]; // 새롭게 이동할 좌표
					if(x >= 0 && x < N && y >= 0 && y < N){ // 범위 내에 있을 때
						if(board[x][y] == 0){ // 흰색으로 이동하려고 할 때
							moveWhite(idx,p,x,y,chess,pos);
						}
						else if(board[x][y] == 1){ // 빨간색으로 이동하려 할 때
							moveRed(idx,p,x,y,chess,pos);
						}
						if(chess[x][y].size() >= 4){ // 종료조건: 4개 이상의 말이 모여있을 때
							cout << turn; // 턴 출력 후 종료
							return 0;
						} // 파란색을 만난 후, 파란색을 또 만났거나 범위를 벗어난 경우, 아무것도 수행하지 않음
					}
				}
			}
			else{ // 범위를 벗어난 경우(파란색과 동일)
				chess[p.x][p.y][idx].dir = r_dir[chess[p.x][p.y][idx].dir]; // 현재 말의 방향을 반대로 바꿔줘야 함(이전에 선언해놓은 배열 이용)
				x = p.x+dir[chess[p.x][p.y][idx].dir][0], y = p.y+dir[chess[p.x][p.y][idx].dir][1]; // 새롭게 이동할 좌표
				if(x >= 0 && x < N && y >= 0 && y < N){ // 범위 내에 있을 때
					if(board[x][y] == 0){ // 흰색으로 이동하려고 할 때
						moveWhite(idx,p,x,y,chess,pos);
					}
					else if(board[x][y] == 1){ // 빨간색으로 이동하려 할 때
						moveRed(idx,p,x,y,chess,pos);
					}
					if(chess[x][y].size() >= 4){ // 종료조건: 4개 이상의 말이 모여있을 때
						cout << turn; // 턴 출력 후 종료
						return 0;
					} // 범위를 벗어나 방향을 바꾼 후, 파란색을 만났거나 범위를 또 벗어난 경우, 아무것도 수행하지 않음
				}
			}
		}
	}
	
	if(turn > 1000){ // 1000번 수행했는데도 게임이 종료되지 않았으면 
		turn = -1; // -1 출력
	}
	
	cout << turn;
	
	return 0;
}

void moveWhite(int idx, Pos p, int x, int y, deque<Dir> **chess, Pos *pos){ // 흰색으로 이동할 때
	deque<Dir> tmp; 
	int c_size = chess[p.x][p.y].size();
	for(idx; idx < c_size; idx++){ // 순서를 그대로 유지해야 하므로 뒤쪽부터 해당 말까지 거꾸로 뽑은 후,
		Dir dir = chess[p.x][p.y].back();
		chess[p.x][p.y].pop_back();
		tmp.push_back(dir);
	}
	
	while(!tmp.empty()){ // 다시 앞쪽말부터 쌓아줌(뒤쪽부터 뽑을 때, push_back으로 이어 붙였으므로 앞쪽말부터 쌓으려면 pop_back하여 쌓아주어야 함)
		Dir dir = tmp.back();
		tmp.pop_back();
		chess[x][y].push_back(dir);
		pos[dir.num] = {x,y}; // 이동된 위치값으로 
	}
}

void moveRed(int idx, Pos p, int x, int y, deque<Dir> **chess, Pos *pos){ // 빨간색으로 이동할 때
	int c_size = chess[p.x][p.y].size();
	for(idx; idx < c_size; idx++){ // 순서를 뒤집어야 하므로 뒤쪽부터 해당 말까지 거꾸로 뽑아서 이동할 위치에 말 쌓아줌
		Dir dir = chess[p.x][p.y].back();
		chess[p.x][p.y].pop_back();
		chess[x][y].push_back(dir);
		pos[dir.num] = {x,y}; // 이동된 위치값으로 변경
	}
}
