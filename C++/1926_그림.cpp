#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
}; // 좌표를 저장하기 위한 struct

int main() {
	int n, m;
	cin >> n >> m;
	
	int **canvas = new int*[n]; // 그림 도화지
	bool **visit = new bool*[n]; // 방문 여부를 확인할 배열
	for(int i = 0; i < n; i++){
		canvas[i] = new int[m];
		visit[i] = new bool[m];
		memset(visit[i],false,sizeof(bool)*m);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> canvas[i][j];
		}
	}
	
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	queue<Pos> q; // bfs를 진행하기 위한 queue
	int max_size = 0, cnt = 0; // max_size: 그림의 최대 영역 크기 구하기 위한 변수, cnt: 그림 영역의 수 구하기 위한 변수
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(canvas[i][j] == 1 && visit[i][j] == false){ // 그림이 그려져 있고 방문한 적 없으면 queue에 push
				cnt++; // 그림의 수 1증가
				visit[i][j] = true; // 방문 했으므로 true
				q.push({i,j});
				
				int tmp_size = 0; // 현재 영역의 크기 구하기 위한 변수
				while(!q.empty()){
					tmp_size++;
					Pos p = q.front();
					q.pop();
					
					for(int d = 0; d < 4; d++){ // 상하좌우 인덱스 계산하기 위함
						int x = p.x+dir[d][0], y = p.y+dir[d][1];
						if(x >= 0 && x < n && y >= 0 && y < m){ // 인덱스가 범위 이내에 존재해야 함
							if(canvas[x][y] == 1 && visit[x][y] == false){ // 그림이 그려져 있고 방문한 적 없어야 함
								visit[x][y] = true;
								q.push({x,y});
							}
						}
					}
				}
				
				if(max_size < tmp_size){ // 현재 영역의 크기와 최대 영역의 크기 비교하면서 최대 영역 크기 구함
					max_size = tmp_size;
				}
			}
		}
	}
	
	cout << cnt << '\n' << max_size;
	
	return 0;
}
