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
} // 아래쪽에 있는 뿌요부터 밑쪽으로 내리기 위해 존재하는 뿌요들 정렬 필요(이는 정렬 조건)

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
			} // 뿌요가 있으면 deque에 추가
		}
	}
	
	cout << Puyopuyo(board,dq);
	
	return 0;
}

int Puyopuyo(char **board, deque<Pos> dq){ // 뿌요뿌요 
	bool flag = true;
	int cnt = 0;
	while(flag == true && !dq.empty()){
		flag = false;
		
		for(int l = 0; l < dq.size(); l++){
			Pos dq_pos = dq[l];
			char col = board[dq_pos.x][dq_pos.y]; // 현재 뿌요의 색깔 담기 위함
			if(col == '.'){ // 비어있으므로 건너 뛰기
				continue;
			}
			
			bool **visit = new bool*[12];
			for(int i = 0; i < 12; i++){
				visit[i] = new bool[6];
				memset(visit[i],false,sizeof(bool)*6);
			}
			
			int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //상하좌우
			
			queue<Pos> puyo;
			deque<Pos> boom;
			puyo.push(dq_pos);
			boom.push_back(dq_pos);
			visit[dq_pos.x][dq_pos.y] = true;
			
			int c = 0;
			while(!puyo.empty()){ //bfs로 같은색 뿌요 주변에 몇 개인지 세기
				Pos p = puyo.front();
				puyo.pop();
				c++;
				
				for(int d = 0; d < 4; d++){
					int x = p.x+dir[d][0], y = p.y+dir[d][1];
					if(x >= 0 && x < 12 && y >= 0 && y < 6){
						if(visit[x][y] == false && board[x][y] == col){ // 같은 색이고 방문한적 없는 뿌요라면
							puyo.push({x,y}); // 큐에 넣기
							boom.push_back({x,y}); // 터뜨려야 되는 뿌요를 담기 위한 deque
							visit[x][y] = true;
						}
					}
				}
			}
			
			if(c >= 4){ // 연결된 뿌요가 4개 이상이므로 deque에 저장된 뿌요 제거
				board = Boom(board,boom);
				flag = true;
			}
		}
		
		if(flag == true){ // 제거를 했다면
			cnt++; // 연속으로 터진 횟수 1증가
			board = Move(board,dq); // 터진 자리 채우기 위해 move 수행
		}
	}
	return cnt; // 연속으로 몇 번 터
}

char** Boom(char** board, deque<Pos> dq){ // 뿌요를 터뜨리기 위함
	for(int i = 0; i < dq.size(); i++){
		board[dq[i].x][dq[i].y] = '.'; // 터진 뿌요는 제거되기 때문에 '.'으로 바뀜
	}
	
	return board;
}

char** Move(char **board, deque<Pos> &dq){ // 뿌요를 가능한 가장 아래쪽으로 이동시키기 위함
	int s = dq.size();
	for(int i = 0; i < s; i++){
		Pos p = dq.back();
		dq.pop_back();
		if(board[p.x][p.y] == '.'){ // 비어있으면(이미 터진 뿌요) 아무런 행동 하지 않음
			continue;
		}
		
		// 아니라면
		int j = p.x+1; // 열은 고정시킨 채 행의 위치 아래로 이동하면서 탐색
		for(j; j < 12; j++){
			if(board[j][p.y] != '.'){ // 비어있어야 이동할 수 있음 '.'가 아니라면 더이상 이동할 수 없는 것
				break;
			}
		}
		
		if(j > p.x+1){ // j가 p.x+1면 이동할 수 없는 것이고 이보다 커야 한 칸 이상 이동하는 것
			board[j-1][p.y] = board[p.x][p.y];
			board[p.x][p.y] = '.';
			p.x = j-1; 
		} // 이동
		
		dq.push_front(p); // 이동 후, 이동된 뿌요의 위치 다시 deque에 삽입
	}
	
	sort(dq.begin(),dq.end(),cmp); // 아래쪽 뿌요부터 담겨있어야 오류 없이 아래로 이동시킬 수 있음 -> sorting 필요
	return board;
}
