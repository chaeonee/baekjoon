#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	char grid[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> grid[i][j];
		}
	} // 그림 색깔 받기
	
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
	
	int area = 0; // 구역의 수
	bool visit[N][N]; // 방문 여부 표시
	for(int i = 0; i < N; i++){
		memset(visit[i],false,N);
	} // 초기화
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){ // 적록색약이 아닐 경우의 구역의 수 먼저 구하기
			if(!visit[i][j]){ // 방문한 적 없다면
				area++; // 구역 1증가
				visit[i][j] = true; // 방문 표시 후 bfs 진행
				
				queue<pair<int, int> > q; // bfs를 위한 queue 선언
				q.push(make_pair(i,j));
				while(!q.empty()){ // queue가 빌 때까지 bfs 진행(bfs로 한 번에 탐색된 곳은 하나의 구역)
					int x = q.front().first, y = q.front().second;
					q.pop();
					
					char col = grid[x][y];
					for(int d = 0; d < 4; d++){ // 상하좌우 이동
						int dx = x+dir[d][0], dy = y+dir[d][1]; // 이동 좌표 계산
						if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 범위 확인
							if(!visit[dx][dy] && grid[dx][dy] == col){ // 방문여부 확인 & 색깔 동일한지 확인
								visit[dx][dy] = true;
								q.push(make_pair(dx,dy));
							}
						}
					}
				}
			}
			if(grid[i][j] == 'G'){ // 적록색약은 초록과 빨강이 동일하게 보일 것이기 때문에 초록색을 모두 빨간색으로 교체(같은 색으로 처리하기 위해)
				grid[i][j] = 'R';
			}
		}
	}
	
	cout << area << " "; // 적록색약이 아닌 사람이 봤을 때의 구역 수
	
	area = 0;
	for(int i = 0; i < N; i++){
		memset(visit[i],false,N);
	} // 구역 및 visit 배열 다시 초기화(적록색약인 사람의 경우 구하기 위해)
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){ // 적록 색약인 경우 탐색 시작
			if(!visit[i][j]){ // 방문한 적 없다면
				area++; // 구역 1증가 후 bfs 진행
				visit[i][j] = true;
				
				queue<pair<int, int> > q;
				q.push(make_pair(i,j));
				while(!q.empty()){ // bfs 진행
					int x = q.front().first, y = q.front().second;
					q.pop();
					
					char col = grid[x][y];
					for(int d = 0; d < 4; d++){ // 상하좌우 이동
						int dx = x+dir[d][0], dy = y+dir[d][1]; // 이동 좌표 계산
						if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 이동좌표 범위 확인
							if(!visit[dx][dy] && grid[dx][dy] == col){ // 방문여부 체크 및 같은 색인지 확인
								visit[dx][dy] = true;
								q.push(make_pair(dx,dy));
							}
						}
					}
				}
			}
		}
	}
	
	cout << area; // 적록색약인 사람이 봤을 때의 구역 수 출력
	
	return 0;
}
