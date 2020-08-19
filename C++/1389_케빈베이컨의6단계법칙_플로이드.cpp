#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int **dist = new int*[N]; // dist[i][j]: i->j까지의 최단 경로 길이
	for(int i = 0; i < N; i++){
		dist[i] = new int[N];
		for(int j = 0; j < N; j++){
			if(i == j){
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = 10000;
		}
	} // 초기화 dist값을 매우 큰 값으로 설정
	
	for(int i = 0; i < M; i++){
		int p1, p2;
		cin >> p1 >> p2;
		dist[p1-1][p2-1] = 1;
		dist[p2-1][p1-1] = 1;
	} // 연결되어 있음을 표시(방향이 없기 때문에 양쪽 다 표시)
	
	for(int k = 0; k < N; k++){ // 중간에 거쳐 지나가는 번호
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				if(i == j || i == k || j == k){ //자기 자신과의 연결은 고려하지 않아도 됨
					continue;
				}

				int tmp = min(dist[i][j], dist[i][k]+dist[k][j]); // k를 거쳐 지나가는 값과 거치치 않는 방법 비교하여 더 작은 값 구하기
				dist[i][j] = tmp;
				dist[j][i] = tmp; // 최솟값 갱신
			}
		}
	}
	
	int p_num = 0, n_dist = 1000000;
	for(int i = 0; i < N; i++){ //케빈 베이컨의 수가 가장 작은 사람 구하기 위함
		int tmp = 0;
		for(int j = 0; j < N; j++){
			tmp += dist[i][j];
		}
		
		if(n_dist > tmp){ // 케빈 베이컨의 수의 최솟 값 및 케빈 베이컨의 수가 가장 작은 사람 갱신(같을 때는 번호가 작은 사람을 출력해야 하므로 아무 것도 수행하지 않음)
			n_dist = tmp;
			p_num = i;
		}
	}
	
	cout << p_num+1; // index는 0부터 시작하므로 1 증가시켜 출력
	
	return 0;
}
