#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int **kb = new int*[N]; // kb[i][j]: i->j까지의 최단 경로 길이
	bool **connected = new bool*[N]; // connected[i][j]: i와 j가 연결되었는지 여부
	for(int i = 0; i < N; i++){
		connected[i] = new bool[N];
		memset(connected[i],false,N);
		kb[i] = new int[N];
		memset(kb[i],0,sizeof(int)*N);
	} // 초기화
	
	for(int i = 0; i < M; i++){
		int p1, p2;
		cin >> p1 >> p2;
		connected[p1-1][p2-1] = true;
		connected[p2-1][p1-1] = true;
	} // 연결되어 있음을 표시(방향이 없기 때문에 양쪽 다 표시)
	
	for(int i = 0; i < N; i++){ // i를 시작으로 나머지까지의 최단 거리를 구하고자 함
		queue<pair<int, int> > q;
		q.push(make_pair(i,0)); // 도착지점 및 해당 지점까지의 거리
		
		bool visit[N] = {false, }; // 방문 체크
		visit[i] = true;
		while(!q.empty()){ // BFS 수행
			int num = q.front().first, step = q.front().second;
			q.pop();
			
			for(int j = 0; j < N; j++){
				if(!visit[j] && connected[num][j]){ // 방문한 적 없고 연결된 점 넣기 
					kb[i][j] = step+1;
					kb[j][i] = step+1; // 최단거리
					q.push(make_pair(j,step+1)); // 다음 탐색을 위해 queue에 넣기
					visit[j] = true; // 방문 체크
				}
			}
		}
	}
	
	int p_num = 0, n_kb = 1000000;
	for(int i = 0; i < N; i++){ //케빈 베이컨의 수가 가장 작은 사람 구하기 위함
		int tmp = 0;
		for(int j = 0; j < N; j++){
			tmp += kb[i][j];
		}
		
		if(n_kb > tmp){ // 케빈 베이컨의 수의 최솟 값 및 케빈 베이컨의 수가 가장 작은 사람 갱신(같을 때는 번호가 작은 사람을 출력해야 하므로 아무 것도 수행하지 않음)
			n_kb = tmp;
			p_num = i;
		}
	}
	
	cout << p_num+1; // index는 0부터 시작하므로 1 증가시켜 출력
	
	return 0;
}
