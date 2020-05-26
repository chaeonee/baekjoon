#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	
	bool **area = new bool*[M];
	for(int i = 0; i < M; i++){
		area[i] = new bool[N];
		memset(area[i],false,N);
	}
	
	for(int i = 0; i < K; i++){ // 직사각형 영역의 area 값 true로 바꿔주기
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1 = M-y1;
		y2 = M-y2; // 문제는 왼쪽 아래가 (0,0) 코드에서는 왼쪽 위가 (0,0) -> y좌표의 값 y = M 대칭시켜줘야 함
		
		for(int y = y2; y < y1; y++){
			for(int x = x1; x < x2; x++){
				area[y][x] = true;
			}
		}
	}
	
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
	
	vector<int> n_area; // 영역의 넓이를 담을 벡터
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(area[i][j] == false){ // 사각형이 채워져 있지 않거나 방문하지 않은 점을 시작으로
				queue<pair<int, int> > q;
				q.push(make_pair(i,j));
				area[i][j] = true; // bfs 수행
				
				int cnt = 0; // 현재 영역의 넓이
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					
					cnt++;
          
					for(int d = 0; d < 4; d++){
						int dy = y+dir[d][0], dx = x+dir[d][1];
						if(dy >= 0 && dy < M && dx >= 0 && dx < N && area[dy][dx] == false){ // 영역 내에 존재해야 하고 방문한 적 없어야 함
							q.push(make_pair(dy,dx));
							area[dy][dx] = true;
						}
					}
					
				}
				
				n_area.push_back(cnt); // 현재 영역의 넓이 push
			}
		}
	}
	
	sort(n_area.begin(),n_area.end()); // 영역의 넓이를 오름 차순으로 정렬
	cout << n_area.size() << '\n'; // 벡터의 크기가 영역의 개수가 됨
	for(int i = 0; i < n_area.size(); i++){
		cout << n_area[i] << " "; // 정렬된 영역의 넓이 출력
	}
	
	return 0;
}
