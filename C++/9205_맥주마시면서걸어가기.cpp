#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

struct Pos{
	int x, y;
};

int getDistance(Pos a, Pos b);

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n_conv;
		cin >> n_conv; // 편의점의 수
		
		Pos *spot = new Pos[n_conv+2]; // 집+편의점의수+페스티벌
		for(int i = 0; i < n_conv+2; i++){
			cin >> spot[i].x >> spot[i].y;
		}
		
		bool *visit = new bool[n_conv+2]; // 방문 여부를 확인할 배열(집,편의점,페스티벌)
		memset(visit,false,sizeof(bool)*(n_conv+2));
		int dist[n_conv+2][n_conv+2]; // 각 장소들간의 맨해튼 거리를 담을 배열
		for(int i = 0; i < n_conv+2; i++){
			for(int j = 0; j < n_conv+2; j++){
				if(i == j){ // 만약 같은 거리이면
					dist[i][j] =200000; // 엄청 먼 거리로 설정
					continue;
				}
				dist[i][j] = getDistance(spot[i],spot[j]);
			}
		}
		
		queue<int> q;
		q.push(0);
		visit[0] = true; // 집을 시작으로 bfs 진행
		
		string result = "sad"; // 결과를 담을 배열
		while(!q.empty()){
			int n = q.front();
			q.pop();
			
			if(n == n_conv+1){ // 만약 페스티벌에 도착했다면
				result = "happy"; // happy 저장
			}
			
			for(int i = 0; i < n_conv+2; i++){
				if(visit[i] == false && dist[n][i] <= 1000){ // 방문한 적 없고 거리가 1000이내라면(1000으로 설정한 이유는 맥주가 다 떨어지지 않을 수 있는 거리가 1000이기 때문)
					visit[i] = true; // 방문 여부 표시
					q.push(i);
				}
			}
		}
		
		cout << result << '\n';
	}
	
	return 0;
}

int getDistance(Pos a, Pos b){
	return (int)abs((double)a.x-(double)b.x) + (int)abs((double)a.y-(double)b.y); // 각 좌표 간의 맨해튼 거리
}
