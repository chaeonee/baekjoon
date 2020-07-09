#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

int meetSwan(int R, int C, int **melt, vector<Pos> swan);
void meltIce(int R, int C, char **lake, int **visit, queue<Pos> water);

int main() {
	int R, C;
	cin >> R >> C;
	
	char **lake = new char*[R];
	int **melt = new int*[R];
	for(int i = 0; i < R; i++){
		lake[i] = new char[C];
		melt[i] = new int[C];
		memset(melt[i],0,C);
	}
	
	vector<Pos> swan; // 백조의 위치를 담을 vector
	queue<Pos> water; // 물의 위치를 담을 queue
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> lake[i][j];
			
			if(lake[i][j] == '.'){ // 물인 경우
				water.push({i,j}); // 물의 위치 추가
			}
			else if(lake[i][j] == 'L'){ // 백조의 경우
				water.push({i,j}); // 백조는 물 위에 위치하므로 물 위치도 추가
				swan.push_back({i,j}); // 백조 위치 추가
			}
		}
	}
	
	meltIce(R,C,lake,melt,water); // 얼음 녹이는 전처리

	cout << meetSwan(R,C,melt,swan); // 백조 만나는 날 계산
	
	return 0;
}

int meetSwan(int R, int C, int **melt, vector<Pos> swan){
	Pos swan1 = swan[0], swan2 = swan[1]; // 백조 위치
	
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	
	bool **visit = new bool*[R];
	for(int i = 0; i < R; i++){
		visit[i] = new bool[C];
		memset(visit[i],0,C);
	}
	visit[swan1.x][swan1.y] = true; // 방문 배열 선언 및 초기화
	
	int day = 0; // 백조들이 만나는 날
	
	queue<Pos> q;
	q.push(swan1);
	while(true){
		queue<Pos> next_q; // 다음 날에 녹을 수 있는 얼음(빙하) 담아 놓는 queue
		while(!q.empty()){ // BFS 진행
			Pos p = q.front();
			q.pop();
			
			if(p.x == swan2.x && p.y == swan2.y){ // 다른 백조 만나면
				return day; // 만난 날 표시
			}
			
			for(int d = 0; d < 4; d++){ // 상하좌우 이동
				int dx = p.x+dir[d][0], dy = p.y+dir[d][1]; // 좌표 계산
				if(dx >= 0 && dx < R && dy >= 0 && dy < C){ // 범위 체크
					if(melt[dx][dy] <= day && visit[dx][dy] == false){ // 현재 날짜 또는 현자 날짜 이전에 얼음이 녹았으며, 방문한적 없는 곳이라면
						q.push({dx,dy}); // queue에 추가하여 탐색
						visit[dx][dy] = true; // 방문 표시
					}
					else if(melt[dx][dy] == day+1 && visit[dx][dy] == false){ // 방문한 적 없고, 다음 날에 얼음이 녹을 예정이라면
						next_q.push({dx,dy}); // 다른 queue에 넣어 놓기
						visit[dx][dy] = true; // 방문 표시
					}
				}
			}
		}
		day++; // 만날 수 있는 날 하루 증가
		q = next_q; // queue 갱신
	}
	
	return day;
}

void meltIce(int R, int C, char **lake, int **melt, queue<Pos> water){ // 얼음 녹이기
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	
	while(!water.empty()){ // 물이 비어있을 때 까지, visit 배열 대신 얼음이 녹는 날을 표시
		Pos p = water.front();
		water.pop();
		
		for(int d = 0; d < 4; d++){ // 물의 상하좌우 확인
			int dx = p.x+dir[d][0], dy = p.y+dir[d][1]; // 좌표 계산
			if(dx >= 0 && dx < R && dy >= 0 && dy < C){ // 범위 체크
				if(melt[dx][dy] == 0 && lake[dx][dy] == 'X'){ // 얼음이 아직 녹지 않았을 경우 
					water.push({dx,dy});
					melt[dx][dy] = melt[p.x][p.y]+1; // 얼음이 녹는 날 표시
				}
			}
		}
	}
}
