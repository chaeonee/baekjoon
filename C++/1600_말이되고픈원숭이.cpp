#include <iostream>
#include <queue>
using namespace std;

struct Pos{
	int x, y, num, k;
}; // 원숭이의 x좌표 y좌표, 걸린시간, K의 크기

int main() {
	int K, W, H;
	cin >> K;
	cin >> W >> H;
	
	int board[H][W];
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> board[i][j];
		}
	}
	bool visit[K+1][H][W]; // 방문 여부... visit을 2차원으로 쓰면 앞쪽에서 말처럼 모두 이동하면 뒤에서는 말처럼 이동하지 못하는 경우가 생김 -> 말처럼 이동할 수 있는 횟수도 담을 수 있도록 3차원 visit 필요
	for(int k = 0; k < K+1; k++){
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				visit[k][i][j] = false;
			}
		}
	} // 초기화
	
	int dir[12][2] = {{-1,0},{1,0},{0,-1},{0,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}}; // 상하좌우 & 말이 이동하는 경로
	
	queue<Pos> q;
	q.push({0,0,0,K}); // bfs를 한 queue와 queue를 (0,0)으로 초기화
	
	int num = -1; // 도착지까지 가는 데 걸리는 시간
	while(!q.empty()){
		Pos p = q.front();
		q.pop();
		
		if(p.x == H-1 && p.y == W-1){ // 도착지에 도착하면 while문 종료.. 이를 만나지 못하면 도착하지 못했다는 것이므로 -1이 나중에 출력될 것
			num = p.num;
			break;
		}
		
		int d_len = 4; // 상하좌우로는 항상 이동할 수 있기 때문에 4로 초기화
		if(p.k > 0){ // 만약 말처럼 이동할 수 있는 경우 d_len의 값 12로(상하좌우+말처럼 이동하는 경우)
			d_len = 12;
		}
		for(int d = 0; d < d_len; d++){
			int x = p.x+dir[d][0], y = p.y+dir[d][1];
			if(x >= 0 && x < H && y >= 0 && y < W){
				if(d < 4){ // 상하좌우로 이동할 때
					if(visit[p.k][x][y] == false && board[x][y] == 0){ // k값은 그대로 유지되기 때문에(말처럼 이동안했으니까) visit[p.k][x][y]로 방문 확인 & 장애물이 존재하지 않을 때
						q.push({x,y,p.num+1,p.k});
						visit[p.k][x][y] = true;
					}
				}
				else{ // 말처럼 이동할 때
					if(visit[p.k-1][x][y] == false && board[x][y] == 0){ // / 말처럼 이동할 수 있는 경우 1감소 -> visit[p.k-1][x][y]로 방문 확인 & 장애물이 존재하지 않을 때
						q.push({x,y,p.num+1,p.k-1});
						visit[p.k-1][x][y] = true;
					}
				}
			}
		}
	}
	
	cout << num;
	
	return 0;
}
