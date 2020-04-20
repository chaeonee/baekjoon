#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

struct Pos{
	int x, y, time;
};

int getDist(int w, int h, Pos s, Pos e, char **room);
int getTime(int s, int move, int now, int prev, int n_dust, bool visit[], int **dist);

int main() {
	while(true){
		int w, h;
		cin >> w >> h;
		
		if(w == 0 && h == 0){
			break;
		}
		
		char **room = new char*[h];
		for(int i = 0; i < h; i++){
			room[i] = new char[w];
		} // 방 정보 담기
		
		deque<Pos> dust;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> room[i][j];
				
				if(room[i][j] == 'o'){
					dust.push_front({i,j,0}); // 로봇 청소기
				}
				else if(room[i][j] == '*'){
					dust.push_back({i,j,0}); // 먼지
				}
			}
		}
		
		int n_dust = dust.size();
		int **dist = new int*[n_dust];
		for(int i = 0; i < n_dust; i++){
			dist[i] = new int[n_dust];
		}
		for(int i = 0; i < n_dust; i++){
			for(int j = i; j < n_dust; j++){ // 로봇청소기+각각의먼지 간의 거리 모두 구하기
				if(i == j){
					dist[i][j] = 0;
					continue;
				}
				int d = getDist(w,h,dust[i],dust[j],room); // 거리 구하기
				dist[i][j] = d;
				dist[j][i] = d;
			}
		}
		
		bool visit[n_dust] = {0, };
		cout << getTime(1,-1,0,0,n_dust,visit,dist) << '\n';
	}
	
	return 0;
}

int getDist(int w, int h, Pos s, Pos e, char **room){
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	bool **visit = new bool*[h];
	for(int i = 0; i < h; i++){
		visit[i] = new bool[w];
		memset(visit[i],false,sizeof(bool)*w);
	}
	visit[s.x][s.y] = true;
	
	deque<Pos> q;
	q.push_back(s);
	while(!q.empty()){ // s와 e 간의 최소 거리 구하기 위해 bfs 수행
		Pos p = q.front();
		q.pop_front();
		
		for(int d = 0; d < 4; d++){
			int x = p.x+dir[d][0], y = p.y+dir[d][1];
			if(x >= 0 && x < h && y >= 0 && y < w){
				if(visit[x][y] == false && room[x][y] != 'x'){
					if(x == e.x && y == e.y){
						return p.time+1; // 목적지에 도달하면 바로 최단거리 return
					}
					q.push_back({x,y,p.time+1});
					visit[x][y] = true;
				}
			}
		}
	}
	
	return -1; // 목적지에 도달하지 못하였기 때문에 -1 return
}

// 무조건 가까운 곳으로 이동한다고 최단거리가 되는 것 아님 -> 먼지들 방문 순서를 순열을 이용하여 모두 구해야 함(dfs를 위해 재귀, 백트래킹 이용할 것)
int getTime(int s, int move, int now, int prev, int n_dust, bool visit[], int **dist){
	if(s == n_dust){ // 모든 먼지 방문했을 때
		if(move < 0 || move > now){ // move를 -1로 초기화하였음 -> move < 0 조건 추가 & 최소 경로 구하여햐 하므로 최소 경로이면 갱신 필요
			move = now;
		}
		return move;
	}
	
	for(int i = 1; i < n_dust; i++){
		if(visit[i] == false && dist[prev][i] != -1){ // 방문한 적 없는 먼지여야 함 & 거리가 -1이면 이동할 수 없는 경로이므로 pruning
			visit[i] = true;
			move = getTime(s+1,move,now+dist[prev][i],i,n_dust,visit,dist);
			visit[i] = false;
		}
	}
	
	return move;
}
