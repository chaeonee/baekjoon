#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Pos{
	int x, y, len;
};

int main() {
	int N;
	cin >> N;
	
	int sea[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> sea[i][j];
		}
	} // 바다와 섬 정보 담을 배열
	
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
	
	int bridge = 100000; // 놓아야 하는 다리의 수 초기화(최소값을 구할 것이기 때문에 큰 값으로 초기화)
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(sea[i][j] == 0){ // 바다라면 건너뛰기
				continue;
			}
			
			bool flag = false; // 섬의 가장자리 여부 판단하는 flag(한 면이라도 바다랑 닿아 있으면 가장자리로 판단)
			for(int d = 0; d < 4; d++){
				int di = i+dir[d][0], dj = j+dir[d][1];
				if(di >= 0 && di < N && dj >= 0 && dj < N){
					if(sea[di][dj] == 0){ // 상하좌우 중 바다가 한 면이라도 포함되어 있으면 가장자리
						flag = true;
					}
				}
			}
			
			if(flag == false){ // 섬의 가장자리 아니라면 다리 놓을 수 없기 때문에 건너뛰기
				continue;
			}
			
			bool visit[N][N]; // 방문 체크 배열
			for(int k = 0; k < N; k++){
				memset(visit[k],false,N);
			} // 초기화
			
			queue<Pos> q;
			q.push({i,j,0});
			visit[i][j] = true;
			while(!q.empty()){ // 현재 위치와 같은 섬에 포함되는 칸 모두 방문여부 true로 바꿔줌(다리를 그쪽으로 놓지 않게 하기 위해)
				Pos p = q.front();
				q.pop();
				
				for(int d = 0; d < 4; d++){
					int dx = p.x+dir[d][0], dy = p.y+dir[d][1];
					if(dx >= 0 && dx < N && dy >= 0 && dy < N){
						if(visit[dx][dy] == false && sea[dx][dy] == 1){ // 방문한 적 없고 붙어있는 땅일 경우 같은 섬
							visit[dx][dy] = true;
							q.push({dx,dy,0});
						}
					} 
				}
			}
			
			q.push({i,j,-1}); // 다리를 놓을 때 현재 위치와 도착 위치 포함되면 안됨 -> -1부터 시작(=1-2)
			while(!q.empty()){ // 가장 가까운 다른 섬의 위치 찾기 위한 bfs
				Pos p = q.front();
				q.pop();
				
				if(p.len >= 0 && sea[p.x][p.y] == 1){ // 현재 위치가 아닌 다른 육지일 경우(다른 섬)
					if(bridge > p.len){ // 다리 길이 비교하여 더 작은 값으로 갱신
						bridge = p.len;
					}
					break;
				}
				
				for(int d = 0; d < 4; d++){ // 상하좌우
					int dx = p.x+dir[d][0], dy = p.y+dir[d][1]; // 이동 좌표 계산
					if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 범위 체크
						if(visit[dx][dy] == false){ // 방문한 적 없다면
							visit[dx][dy] = true; // 방문 체크하고
							q.push({dx,dy,p.len+1}); // 큐에 추가하여 탐색
						}
					} 
				}
			}
		}
	}
	
	cout << bridge;
	
	return 0;
}
