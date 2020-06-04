#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Switch{
	bool light; // 불이 켜져있는지 여부
	vector<pair<int, int> > on; // 현재 위치에서 켤 수 있는 불의 위치를 담을 벡터
};

int main() {
	int N, M;
	cin >> N >> M;
	
	Switch room[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			room[i][j].light = false;
		}
	}
	room[0][0].light = true; // 초기화 (1,1)은 처음에 켜져있다고 했으니 (0,0)은 true로
	
	for(int i = 0 ;i < M; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		room[x1-1][y1-1].on.push_back(make_pair(x2-1,y2-1));
	} // 0~N-1로 인덱싱 했으므로 1씩 빼줘야 함(문제에서는 1~N 범위
	
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
	
	queue<pair<int, int> > q; // bfs를 위한 queue
	q.push(make_pair(0,0)); // 초기 값 queue에 넣기
	
	bool visit[N][N]; // 방문 여부 표시
	for(int i = 0; i < N; i++){
		memset(visit[i],false,N);
	} // 초기화
  
	int cnt = 1; // 불이 켜져 있는 방의 수 - (0,0)은 처음부터 켜져있으므로 cnt의 값이 1부터 시작
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		bool flag = false; // 현재 위치에서 불 켰는지 
		for(int i = 0; i < room[x][y].on.size(); i++){
			if(!room[room[x][y].on[i].first][room[x][y].on[i].second].light){ // 이미 불켜져 있는 곳은 켤 필요 없음 안켜져 있는 곳일 때
				flag = true; // 불킬 것이므로 flag true로
				cnt++; // 불이 켜져 있는 방의 수 1 증가
				room[room[x][y].on[i].first][room[x][y].on[i].second].light = true; // 불켜기
			}
		}
		
		if(flag){ // 불이 켜졌다면 새로운 경로 추가된 것과 같음 -> visit 배열 초기화 해줘서 다시 탐색 할 수 있도록
			for(int i = 0; i < N; i++){
				memset(visit[i],false,N);
			}
		}
		
		for(int i = 0; i < 4; i++){ // bfs, 상하좌우 이동
			int dx = x+dir[i][0], dy = y+dir[i][1];
			if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 범위 체크
				if(room[dx][dy].light && !visit[dx][dy]){ // 불이 켜져 있어야하고 방문한 적 없어야 함
					q.push(make_pair(dx,dy));
					visit[dx][dy] = true;
				}
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
