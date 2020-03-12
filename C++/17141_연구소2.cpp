#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y, time;
};

int putVirus(int N, int M, int s, int count, int min_time, int **lab, vector<Pos> virus, vector<Pos> v);
int spread(int N, int M, int count, int **lab, vector<Pos> v);

int main() {
	int N, M;
	cin >> N >> M;
	
	int **lab = new int*[N]; // 연구실 지도를 담을 배열
	for(int i = 0; i < N; i++){
		lab[i] = new int[N];
	}
	
	vector<Pos> virus; // 바이러스가 존재할 수 있는 위치를 표현한 vector
	int count = (N*N)-M; // 바이러스가 퍼질 수 있는 공간의 수
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> lab[i][j];
			
			if(lab[i][j] == 2){
				virus.push_back({i,j,0});
			}
			else if(lab[i][j] == 1){
				count--;
			}
		}
	}

	vector<Pos> v;
	int t = putVirus(N, M, 0, count, 10000000, lab, virus, v);
	
	if (t == 10000000){ // t가 10000000이라면 바이러스가 연구소 전체에 퍼질 수 없다는 의미
		cout << -1;
	}
	else{
		cout << t;
	}
	
	return 0;
}

int putVirus(int N, int M, int s, int count, int min_time, int **lab, vector<Pos> virus, vector<Pos> v){ // 바이러스가 놓여질 수 있는 곳들 중 M개를 선택하기 위한 함수(조합을 구하는 것과 동일)
	if(v.size() == M){ // M개가 선택된다면 바이러스 퍼뜨리기
		int t = spread(N, M, count, lab, v);
		
		if(min_time > t){ // 최소 시간을 구해야 하므로
			min_time = t;
		}
		
		return min_time;
	}
	
	int v_size = virus.size();
	for(int i = s; i < v_size; i++){ // 재귀를 통해 M개의 위치 선정
		v.push_back(virus[i]);
		int t = putVirus(N, M, i+1, count, min_time, lab, virus, v); // 다음 putVirus는 현재 바이러스 다음에 위치하는 것부터 탐색
		v.pop_back();
		
		if(min_time > t){
			min_time = t;
		}
	}
	
	return min_time;
}

int spread(int N, int M, int count, int **lab, vector<Pos> v){ // 바이러스를 퍼뜨리는 시간을 구하기 위한 함수
	bool **visit = new bool*[N]; // 방문 여부 체크 변수
	for(int i = 0; i < N; i++){
		visit[i] = new bool[N];
		memset(visit[i],false,sizeof(bool)*N);
	}
	
	queue<Pos> q; // bfs를 위해 queue 사용
	for(int i = 0; i < M; i++){
		Pos p = v[i];
		visit[p.x][p.y] = true;

		q.push(p);
	}
	
	int t = 0; // 최종적으로 걸리는 시간을 담을 변수
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	while(!q.empty()){
		Pos p = q.front();
		q.pop();
		
		for(int d = 0; d < 4; d++){
			int x = p.x + dir[d][0];
			int y = p.y + dir[d][1];
			if(x >= 0 && x < N && y >= 0 && y < N){
				if(visit[x][y] == false && lab[x][y] != 1){ // 현재 장소에 방문한 적 없고, 벽이 아니라면
					q.push({x,y,p.time+1});
					visit[x][y] = true;
					count--;
					t = p.time+1;
				}
			}
		}
	}
	
	if(count == 0){ // count가 0이어야 모든 공간을 바이러스로 채운 
		return t;
	}
	else{
		return 10000000;
	}
}
