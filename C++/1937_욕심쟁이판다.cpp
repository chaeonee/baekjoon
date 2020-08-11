#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos{
	int n_bamboo, x, y;
}; // 대나무의 수, 좌표 값

bool operator<(Pos a, Pos b){
	return a.n_bamboo < b.n_bamboo;
} // priority queue를 대나무 수의 내림차순을 기준으로 정렬하기 위함

int main() {
	int n;
	cin >> n;
	
	priority_queue<Pos> q; // priority queue
	int **bamboo = new int*[n]; // 대나무의 수를 저장할 배열
	int **day = new int*[n]; // 현재 위치에서 팬더가 살 수 있는 최대 일수를 저장하기 위한 배열
	for(int i = 0; i < n; i++){
		bamboo[i] = new int[n];
		day[i] = new int[n];
		for(int j = 0; j < n; j++){
			cin >> bamboo[i][j];
			q.push({bamboo[i][j],i,j});
			day[i][j] = 1; // 일수는 1로 초기화(현재 위치에서만 살 수 있을 때)
		}
	}
	
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	int lifespan = 0; // 판다가 최대한 살 수 있는 일수
	while(!q.empty()){ // 대나무의 수가 가장 많은 좌표부터 탐색 진행
		int x = q.top().x, y = q.top().y;
		q.pop(); // priority queue의 가장 앞쪽 좌표 pop(대나무의 수가 가장 많은 좌표)
		
		for(int d = 0; d < 4; d++){ // 상하좌우 이동
			int dx = x+dir[d][0], dy = y+dir[d][1]; // 이동 후 좌표 계산
			if(dx >= 0 && dx < n && dy >= 0 && dy < n){ // 범위 체크
				if(bamboo[x][y] < bamboo[dx][dy]){ // 현재 좌표보다 이동할 좌표가 더 큰 좌표라면
					day[x][y] = max(day[x][y],day[dx][dy]+1); // 현재 저장된 생존 일수와 이동좌표의 생존일수 +1을 비교하여 더 큰 값 저장
				}
			}
		}
		lifespan = max(lifespan,day[x][y]); // 계산 후, 판다가 최대한 살 수 있는 일수 비교 후 저장
	}
	
	cout << lifespan;
	
	return 0;
}
