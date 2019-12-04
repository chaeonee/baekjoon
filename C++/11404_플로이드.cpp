#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	int **cost = new int*[n];
	for(int i = 0; i < n; i++){
		cost[i] = new int[n];
		memset(cost[i],0,sizeof(int)*n);
	}
	
	for(int i = 0; i < m; i++){
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		if(cost[x][y] == 0){ // 0은 연결되어 있지 않음을 뜻함
			cost[x][y] = c;
		}
		else{
			if(cost[x][y] > c){
				cost[x][y] = c; // cost가 작을수록 좋기 때문에 노선이 여러 개라면 가장 적은 비용을 갖는 경로만 사용
			}
		}
	}
	
	// 출발점과 도착점을 바꿔가며 수행 -> 거쳐갈 점을 바꿔가며 n번 반복(총 n^3만큼 루프 돎)
	for(int k = 0; k < n; k++){ // 거쳐갈 점
		for(int i = 0; i < n; i++){ // 출발점
			for(int j = 0; j < n; j++){ // 도착점
				if(i == k || j == k || i == j){// 이는 출발점과 도착점이 같은 경우를 말함(i = k, j = k는 거쳐갈 점과 출발,도착점이 같다는 뜻임으로 부분적으로 봤을 때는 출발점 도착점 같은 것과 같음)
					continue; // 출발점과 도착점이 같은 경우는 없기 때문에 수행하지 않고 넘어감
				}
				
				if(cost[i][j] == 0){ // 직접 연결이 없는 경우
					if(cost[i][k] != 0 && cost[k][j] != 0){ // 직접 연결 안되더라고 k로 거쳐갈 수 있으면 거쳐가자(직접 연결이 없기 때문에 비교 필요 없음)
						cost[i][j] = cost[i][k] + cost[k][j];
					}
				}
				else{ // 직접 연결이 있는 경우
					if(cost[i][k] != 0 && cost[k][j] != 0){ // 직접 연결이 있더라도 돌아오는게 더 비용이 저렴할 수 있음 -> 거쳐서 오는 경우와 직접 오는 경우의 비용 비교
						cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]); // 비교해서 작은 것 취함(0인 경우는 위의 if에서 걸러지기 때문에 0이여서 작은 경우는 없음)
					}
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << cost[i][j] << " ";
		}
		cout << '\n';
	}
	
	
	return 0;
}