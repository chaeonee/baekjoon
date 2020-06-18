#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Meadow{
	bool cow = false, v_cow = false, road[4] = {0,};
}; // cow: 소가 있는지 여부, v_cow: 해당 소를 이동시킨적 있는지 여부, road: 상하좌우에 길이 있는지 여부

int main() {
	int N, K, R;
	cin >> N >> K >> R;
	
	Meadow meadow[N][N];
	for(int i = 0; i < R; i++){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		
		// (r1,c1)와 (r2,c2)는 상하좌우로 인접. 따라서, r1과 r2가 1차이 나거나 c1과 c2가 1차이 날 것
		if(r1 - r2 == 1){ // (r1,c1)의 위, (r2,c2)의 아래로 길이 나 있는 경우(하나의 길이지만 기준 위치가 어디냐에 따라 길의 위치도 달라짐) 
			meadow[r1-1][c1-1].road[0] = true; // (r1,c1)의 위에 길 존재
			meadow[r2-1][c2-1].road[1] = true; // (r2,c2)의 아래에 길 존재
		}
		else if(r1 - r2 == -1){ // (r1,c1)의 아래, (r2,c2)의 위로 길이 나 있는 경우
			meadow[r1-1][c1-1].road[1] = true; // (r1,c1)의 아래에 길 존재
			meadow[r2-1][c2-1].road[0] = true; // (r2,c2)의 위에 길 존재
		}
		if(c1 - c2 == 1){ // (r1,c1)의 왼쪽, (r2,c2)의 오른쪽으로 길이 나 있는 경우
			meadow[r1-1][c1-1].road[2] = true; // (r1,c1)의 왼쪽에 길 존재
			meadow[r2-1][c2-1].road[3] = true; // (r2,c2)의 오른쪽에 길 존재
		}
		else if(c1 - c2 == -1){ // (r1,c1)의 오른쪽, (r2,c2)의 왼쪽으로 길이 나 있는 경우
			meadow[r1-1][c1-1].road[3] = true; // (r1,c1)의 오른쪽에 길 존재
			meadow[r2-1][c2-1].road[2] = true; // (r2,c2)의 왼쪽에 길 존재
		}
	}
	
	vector<pair<int,int> > cow;
	for(int i = 0; i < K; i++){
		int r, c;
		cin >> r >> c;
		meadow[r-1][c-1].cow = true; // 해당 위치에 소가 있음을 표시
		cow.push_back(make_pair(r-1,c-1)); // 소의 위치 저장
	}
	
	int result = (K*(K-1))/2; // 모든 쌍의 소가 만나는 경우의 수로 초기
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	for(int k = 0; k < K; k++){ // K개의 소를 이동시키기 위함
		int r = cow[k].first, c = cow[k].second; // 소의 위치
		meadow[r][c].v_cow = true; // 현재 소를 이동시켰음을 표시
		
		bool visit[N][N]; // 해당 소가 농장을 방문했는지의 여부
		for(int i = 0; i < N; i++){
			memset(visit[i],false,N);
		} // 초기화
		
		queue<pair<int,int> > q; // bfs로 소 이동시킬 것 -> queue 선언
		q.push(make_pair(r,c));
		visit[r][c] = true; // 방문 표시
		while(!q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			
			if(meadow[x][y].cow && !meadow[x][y].v_cow){ // 해당 위치에 소가 있고, 이동시킨 적 없는 소라면
				result--; // 해당 소가 다른 소를 만난 것이므로 결과 값을 1 줄임
			}
			
			for(int d = 0; d < 4; d++){ // 상하좌우 탐색
				if(meadow[x][y].road[d] == 1){ // 길을 건너지 않고 만나야 하므로 길이 있는 경우로는 이동하지 않을 것
					continue;
				}
				
				int dx = x+dir[d][0], dy = y+dir[d][1]; // 이동 좌표 계산
				if(dx >= 0 && dx < N && dy >= 0 && dy < N && !visit[dx][dy]){ // 범위 체크 및 방문 체크
					visit[dx][dy] = true; // 방문 표시
					q.push(make_pair(dx,dy));
				}
			}
		}
	}
	
	cout << result;
	
	return 0;
}
