#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num = 0; // 테스트 케이스 번호
	int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
	while(true){
		int N;
		cin >> N;
		
		if(N == 0){
			break;
		} // N이 0이면 종료
		
		num++; // 테스트 케이스 번호 1 증가
		int rupee[N][N]; /// 도둑루피의 크기
		int cost[N][N]; // 현재 위치의 최소 cost
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> rupee[i][j];
				cost[i][j] = 1000000;
			}
		} // 입력 및 초기화
		
		cost[0][0] = rupee[0][0]; // 시작점 초기화
		queue<pair<int, int> > q;
		q.push(make_pair(0,0)); // bfs를 위한 queue 선언 및 초기화
		while(!q.empty()){ // bfs 진행
			int x = q.front().first, y = q.front().second;
			q.pop();
			
			for(int d = 0; d < 4; d++){ // 상하좌우 이동
				int dx = x+dir[d][0], dy = y+dir[d][1]; // 이동 후 좌표
				if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 범위 체크
					if(cost[dx][dy] > cost[x][y]+rupee[dx][dy]){ // 방문 체크 대신에 현재 위치의 코스트와 갱신될 cost(이전 위치의 cost+현재 도둑루피의 크기) 비교 / 더 작은 cost가 들어오면
						cost[dx][dy] = cost[x][y]+rupee[dx][dy];
						q.push(make_pair(dx,dy)); // cost 갱신 및 queue에 추가
					}
				}
			}
		}
		
		cout << "Problem " << num << ": " << cost[N-1][N-1] << '\n'; // 최종 목적지가 (N-1,N-1)이므로 (N-1,N-1)의	cost 출력
	}
  
	return 0;
}
