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
		}
		
		deque<Pos> dust;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> room[i][j];
				
				if(room[i][j] == 'o'){
					dust.push_front({i,j,0});
				}
				else if(room[i][j] == '*'){
					dust.push_back({i,j,0});
				}
			}
		}
		
		int n_dust = dust.size();
		int **dist = new int*[n_dust];
		for(int i = 0; i < n_dust; i++){
			dist[i] = new int[n_dust];
		}
		for(int i = 0; i < n_dust; i++){
			for(int j = i; j < n_dust; j++){
				if(i == j){
					dist[i][j] = 0;
					continue;
				}
				int d = getDist(w,h,dust[i],dust[j],room);
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
	while(!q.empty()){
		Pos p = q.front();
		q.pop_front();
		
		for(int d = 0; d < 4; d++){
			int x = p.x+dir[d][0], y = p.y+dir[d][1];
			if(x >= 0 && x < h && y >= 0 && y < w){
				if(visit[x][y] == false && room[x][y] != 'x'){
					if(x == e.x && y == e.y){
						return p.time+1;
					}
					q.push_back({x,y,p.time+1});
					visit[x][y] = true;
				}
			}
		}
	}
	
	return -1;
}

int getTime(int s, int move, int now, int prev, int n_dust, bool visit[], int **dist){
	if(s == n_dust){
		if(move < 0 || move > now){
			move = now;
		}
		return move;
	}
	
	for(int i = 1; i < n_dust; i++){
		if(visit[i] == false && dist[prev][i] != -1){
			visit[i] = true;
			move = getTime(s+1,move,now+dist[prev][i],i,n_dust,visit,dist);
			visit[i] = false;
		}
	}
	
	return move;
}
