#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y, time;
};

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int w, h;
		cin >> w >> h;
		
		char **map = new char*[h];
		bool **visit = new bool*[h]; // 상근이의 방문 여부
		for(int i = 0 ; i < h; i++){
			map[i] = new char[w];
			visit[i] = new bool[w];
			memset(visit[i],false,sizeof(bool)*w);
		}
		
		queue<Pos> fire, person; // 불의 좌표, 상근이의 좌표
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
				
				if(map[i][j] == '*'){
					fire.push({i,j,0});
				}
				else if(map[i][j] == '@'){
					person.push({i,j,0});
					visit[i][j] = true;
				}
			}
		}
		
		int time = 0;
		int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우(북남서동)
		while(!person.empty() && time == 0){
   			//불을 먼저  후 상근이 이동시키기(최단거리이므로 bfs 이용)
			if(!fire.empty()){
				int f_len = fire.size(); // 현재 존재하는 불은 모두 퍼뜨려야 하므로 fire의 길이만큼씩 탐색
				for(int i = 0; i < f_len; i++){
					Pos p = fire.front();
					fire.pop();
					
					for(int d = 0; d < 4; d++){
						int x = p.x+dir[d][0], y = p.y+dir[d][1];
						if(x >= 0 && x < h && y >= 0 && y < w){ // 범위 안에 존재하면서
							if(map[x][y] == '.' || map[x][y] == '@'){ // 벽, 이미 불이 퍼진곳이 아니라면
								map[x][y] = '*'; // 불 퍼뜨리고
								fire.push({x,y}); // 다음 위치 저장
							}
						}
					}
				}
			}
			int p_len = person.size(); // 불 퍼뜨리는 것과 같이 상근이가 1초에 이동할 수 있는 경우의 수 다 생각해 주어야 함
			for(int i = 0; i < p_len; i++){
				Pos p = person.front();
				person.pop();
        
				if(p.x == 0 || p.y == 0 || p.x == h-1 || p.y == w-1){ // 벽쪽에 위치하고 있을 때는 상근이가 탈출할 수 있음
					time = p.time+1; // 시간 저장 후 break
					break;
				}
				
				for(int d = 0; d < 4; d++){ // 상근이 상하좌우로 이동
					int x = p.x+dir[d][0], y = p.y+dir[d][1];
					if(x >= 0 && x < h && y >= 0 && y < w){ // 범위 내에 존재하고
						if((map[x][y] == '.' || map[x][y] == '@') && visit[x][y] == false){ // 불 또는 벽이 아니면서 방문한 적 없다면
							visit[x][y] = true;
							person.push({x,y,p.time+1}); // 방문 후 방문 표시
						}
					}
				}
			}
		}
		
		if(time == 0){ // time이 0이면 탈출로를 발견하지 못했다는 의미(탈출로 발견했을 때만 시간 저장하기 때문)
			cout << "IMPOSSIBLE\n"; //IMPOSSIBLE 출력
		}
		else{ // 아니라면 탈출로 발견
			cout << time << '\n'; // time 
		}
	}
	
	return 0;
}
