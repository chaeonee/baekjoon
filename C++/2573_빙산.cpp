#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y, sea;
};

bool isWhole(int N, int M, int **pole, queue<Pos> iceberg){ // 빙산이 한 덩어리인지 확인
	queue<Pos> q; // bfs 진행을 위한 queue
	q.push(iceberg.front());
	
	bool **visit = new bool*[N]; // visit을 확인할 배열
	for(int i = 0; i < N; i++){
		 visit[i] = new bool[M];
		 memset(visit[i],false,sizeof(bool)*M);
	}
	
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	
	int num = 0; // 방문한 빙산의 수
	while(!q.empty()){ // 너비우선탐색 진행
		Pos p = q.front();
		visit[p.x][p.y] = true;
		q.pop();
		
		num++;
		for(int d = 0; d < 4; d++){
			int x = p.x+dir[d][0], y = p.y+dir[d][1];
			if(x >= 0 && x < N && y >= 0 && y < M){
				if(pole[x][y] != 0 && visit[x][y] == false){
					visit[x][y] = true;
					q.push({x,y,0});
				}
			}
		}
	}
	
  	// 만약, 한 덩어리라면 bfs 진행했을 때 모든 빙산 방문했을 것
	if(num == iceberg.size()){ // 따라서 방문한 빙산의 수와 전체 빙산의 수가 동일
		return true;
	}
	else{ // 아니라면 한 덩어리가 아님
		return false;
	}
}

void melt(int N, int M, int **pole, queue<Pos> iceberg){
	int time = 0;
	
	while(true){
		if (iceberg.size() < 2){ // 빙산이 1개 또는 0개라면 한 덩어리 일 수 밖에 없음
			time = 0; // 두 덩어리로 나뉠 일 없기 때문에 time을 0으로 설정하고 break
			break;
		}
		
		int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
		
		time++; // 타임 증가시키고 빙산 녹임
		int len = iceberg.size(); // 현재 빙산의 크기만큼 for문 돌것임
		for(int i = 0; i < len; i++){ // 상하좌우 중 바다가 몇 개 존재하는지 세기 위함
			Pos p = iceberg.front();
			iceberg.pop();
			
			for(int d = 0; d < 4; d++){
				int x = p.x+dir[d][0], y = p.y+dir[d][1];
				if(x >= 0 && x < N && y >= 0 && y < M){
					if(pole[x][y] == 0){
						p.sea++; // pole의 값이 0이라면 바다이므로 sea의 수 증가
					}
				}
			}
			
			iceberg.push(p);
		}
		
		for(int i = 0; i < len; i++){ // 모두 녹은 빙산 없애기
			Pos p = iceberg.front();
			iceberg.pop();
			
			pole[p.x][p.y] -= p.sea; // 주변 바다의 수만큼 빙산의 높이 빼주기
			if(pole[p.x][p.y] < 0){ // 만약 빙산의 높이가 0보다 작다면
				pole[p.x][p.y] = 0; // 0으로 바꿔주고 queue에 더 이상 삽입하지 않기(0이하로 내려갈 수 없기 때문)
			}
			else if(pole[p.x][p.y] > 0){ // 만약 빙산이 남아있다면
				p.sea = 0; // sea를 1로 다시 초기화 시킨 후
				iceberg.push(p); // queue에 삽입
			}
		}
		
		if(!iceberg.empty() && isWhole(N,M,pole,iceberg) == false){ // 만약 한 덩어리가 아니면 break(empty조건을 쓴 이유는 만약 empty라면 isWhole에서 확인할 것이 없기 때문에)
			break;
		}
	}
	
	cout << time; // 시간 출력
}

int main() {
	int N, M;
	cin >> N >> M;
	
	int **pole = new int*[N];
	for(int i = 0; i < N; i++){
		pole[i] = new int[M];
	}
	
	queue<Pos> iceberg;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> pole[i][j];
			
			if(pole[i][j] != 0){
				iceberg.push({i,j,0});
			}
		}
	}
	
	melt(N,M,pole,iceberg);
	
	return 0;
}
