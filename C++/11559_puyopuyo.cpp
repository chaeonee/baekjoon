#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

bool cmp(Pos &a, Pos &b){
	if(a.x == b.x){
		return a.y < b.y;
	}
	return a.x < b.x;
}

int Puyopuyo(char **board, deque<Pos> dq);
char** Boom(char** board, deque<Pos> dq);
char** Move(char **board, deque<Pos> &dq);

int main() {
	char **board = new char*[12];
	for(int i = 0; i < 12; i++){
		board[i] = new char[6];
	}
	
	deque<Pos> dq;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 6; j++){
			cin >> board[i][j];
			
			if(board[i][j] != '.'){
				dq.push_back({i,j});
			}
		}
	}
	
	cout << Puyopuyo(board,dq);
	
	return 0;
}

int Puyopuyo(char **board, deque<Pos> dq){
	bool flag = true;
	int cnt = 0;
	while(flag == true && !dq.empty()){
		flag = false;
		
		for(int l = 0; l < dq.size(); l++){
			Pos dq_pos = dq[l];
			char col = board[dq_pos.x][dq_pos.y];
			if(col == '.'){
				continue;
			}
			
			bool **visit = new bool*[12];
			for(int i = 0; i < 12; i++){
				visit[i] = new bool[6];
				memset(visit[i],false,sizeof(bool)*6);
			}
			
			int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
			
			queue<Pos> puyo;
			deque<Pos> boom;
			puyo.push(dq_pos);
			boom.push_back(dq_pos);
			visit[dq_pos.x][dq_pos.y] = true;
			
			int c = 0;
			while(!puyo.empty()){
				Pos p = puyo.front();
				puyo.pop();
				c++;
				
				for(int d = 0; d < 4; d++){
					int x = p.x+dir[d][0], y = p.y+dir[d][1];
					if(x >= 0 && x < 12 && y >= 0 && y < 6){
						if(visit[x][y] == false && board[x][y] == col){
							puyo.push({x,y});
							boom.push_back({x,y});
							visit[x][y] = true;
						}
					}
				}
			}
			
			if(c >= 4){
				board = Boom(board,boom);
				flag = true;
			}
		}
		
		if(flag == true){
			cnt++;
			board = Move(board,dq);
		}
	}
	return cnt;
}

char** Boom(char** board, deque<Pos> dq){
	for(int i = 0; i < dq.size(); i++){
		board[dq[i].x][dq[i].y] = '.';
	}
	
	return board;
}

char** Move(char **board, deque<Pos> &dq){
	int s = dq.size();
	for(int i = 0; i < s; i++){
		Pos p = dq.back();
		dq.pop_back();
		if(board[p.x][p.y] == '.'){
			continue;
		}
		
		int j = p.x+1;
		for(j; j < 12; j++){
			if(board[j][p.y] != '.'){
				break;
			}
		}
		
		if(j > p.x+1){
			board[j-1][p.y] = board[p.x][p.y];
			board[p.x][p.y] = '.';
			p.x = j-1;
			
		}
		
		dq.push_front(p);
	}
	
	sort(dq.begin(),dq.end(),cmp);
	return board;
}
