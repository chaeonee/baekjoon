#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int SpringSummer(int N, int n_tree, deque<int> **tree, int **land);
int Fall(int N, int n_tree, deque<int> **tree);
void Winter(int N, int **land, int **A);

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	int **A = new int*[N]; // 겨울에 로봇이 추가해줄 양분
	int **land = new int*[N]; // 땅에 남은 양분
	deque<int> **tree = new deque<int>*[N]; //각 위치에 존재하는 나무의 나이
	for(int i = 0; i < N; i++){
		A[i] = new int[N];
		land[i] = new int[N];
		tree[i] = new deque<int>[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
			land[i][j] = 5; // 땅의 양분 초기값 = 5
		}
	}
	
	for(int i = 0; i < M; i++){
		int x,y,age;
		cin >> x >> y >> age;
		tree[x-1][y-1].push_back(age);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!tree[i][j].empty()){
				sort(tree[i][j].begin(),tree[i][j].end()); // 나이 적은 순으로 sorting
			}
		}
	}
	
	for(int k = 0; k < K; k++){
		if(M <= 0){ // 나무가 더이상 남아있지 않다면 진행할 필요 없음
			break;
		}
		M = SpringSummer(N,M,tree,land);
		M = Fall(N,M,tree);
		Winter(N,land,A);
	}
	
	cout << M;
	
	return 0;
}

int SpringSummer(int N, int n_tree, deque<int> **tree, int **land){ // 봄, 여름
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!tree[i][j].empty()){ // 나무가 존재하는 칸에 대해서만 수행
				int t_len = tree[i][j].size();
				int k = 0;
				for(k; k < t_len; k++){
					if(land[i][j] - tree[i][j][k] < 0){ // 나무가 먹을 양분이 부족하다면(sorting되어 있기 때문에 그 뒤의 나무들이 먹기에도 부족)
						break; // 루프 탈출
					}
					land[i][j] -= tree[i][j][k]; // 아니라면 나무가 양분을 먹고
					tree[i][j][k]++; // 나이 한 살 증가
				}
				
				for(k; k < t_len; k++){ // index k 뒤쪽에 있는 나무들은 남아있는 양분보다 나이가 많은 나무들
					n_tree--; // 나무 소멸
					int age = tree[i][j].back();
					tree[i][j].pop_back();
					land[i][j] += age/2; // 죽으면서 본인의 나이의 절반을 땅에게 양분으로 주고 감
				}
			}
		}
	}
	return n_tree;
}

int Fall(int N, int n_tree, deque<int> **tree){ // 가을
	int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // 8개의 번식 방향
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!tree[i][j].empty()){
				int t_len = tree[i][j].size();
				for(int k = 0; k < t_len; k++){
					if(tree[i][j][k] % 5 != 0){
						continue; // 5로 나누어 떨어지지 않으면 번식 불가능
					}
					
					for(int d = 0; d < 8; d++){ // 나누어 떨어진다면 8개의 방향으로 번식
						int x = i+dir[d][0], y = j+dir[d][1];
						if(x >= 0 && x < N && y >= 0 && y < N){ // 대신, 범위 이내의 값이여야 함
							n_tree++; // 나무 추가
							tree[x][y].push_front(1); // 1살짜리 나무가 추가되기 때문에 앞쪽으로 추가 시켜줌
						}
					}
				}
			}
		}
	}
	
	return n_tree;
}

void Winter(int N, int **land, int **A){ // 겨울
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			land[i][j] += A[i][j]; // 로봇이 땅에 정해진 양 만큼의 양분 추가
		}
	}
}
