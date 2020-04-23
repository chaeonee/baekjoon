#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

void Rotate(int N, deque<int> *board, int x, int d, int k);
void Neighborhood(int N, int M, deque<int> *board, int &sum, int &n_board);

int main() {
	int N, M, T;
	cin >> N >> M >> T;
	
	int sum = 0, n_board = N*M;
	deque<int> *board = new deque<int>[N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int tmp;
			cin >> tmp;
			sum += tmp;
			board[i].push_back(tmp);
		}
	}
	
	
	while(T-- > 0){
		int x, d, k;
		cin >> x >> d >> k;
		Rotate(N,board,x,d,k); // 원판 회전
		Neighborhood(N,M,board,sum,n_board); // 인접한 수 제거 or 원판 수 조정
	}
	
	cout << sum;
	
	return 0;
}

void Rotate(int N, deque<int> *board, int x, int d, int k){ // 원판 회전
	for(int i = x-1; i < N; i += x){ // index가 0부터 시작하기 때문에 deque의 인덱스 하나씩 줄여서 생각하기
		if(d == 0){ // 시계방향
			for(int j = 0; j < k; j++){ // 각 원판을 나타내는 deque의 가장 뒤쪽값을 가장 앞으로 이동 시킴
				int tmp = board[i].back();
				board[i].pop_back();
				board[i].push_front(tmp);
			}
		}
		else if(d == 1){ // 반시계방향
			for(int j = 0; j < k; j++){ // 각 원판을 나타내는 deque의 가장 앞쪽값을 가장 뒤로 이동 시킴
				int tmp = board[i].front();
				board[i].pop_front();
				board[i].push_back(tmp);
			}
		}
	}
}

void Neighborhood(int N, int M, deque<int> *board, int &sum, int &n_board){ // 인접한 숫자 찾기
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	bool **visit = new bool*[N]; // bfs 진행 시 방문 여부를 나타낼 배열
	for(int i = 0; i < N; i++){
		visit[i] = new bool[M];
		memset(visit[i],false,sizeof(bool)*M);
	}
	
	bool flag = false; // 제거된 값이 있는지 여부
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(n_board == 0){ // 원판에 남아있는 숫자가 없다면 더이상 진행할 필요 없음
				return;
			}
			
			int val = board[i][j];
			if(visit[i][j] == true || val == -1){ // 이미 방문한 원판이거나 해당 부분의 값이 존재하지 않을 때는 진행하지 않음
				continue;
			}
			
			visit[i][j] = true; // 방문 여부 표시
			
			deque<Pos> q, q_list; // q: bfs 진행을 위한 큐, q_list 제거할 값의 좌표를 담기 위함
			q.push_back({i,j});
			q_list.push_back({i,j});
			while(!q.empty()){
				Pos p = q.front();
				q.pop_front();
				
				for(int d = 0; d < 4; d++){ // 상하좌우 확인
					int x = p.x+dir[d][0], y = (p.y+dir[d][1]) % M; // @@y값 계산 주의@@ 원판이므로 나머지를 이용해야 함 원판의 M번 index는 0과 동일
					if(y < 0){ // 원판이 -1이 되는 경우 존재(이는 0번째 index에서 하나 전의 값 M-1번째 index를 갖는 원판 값을 의미)
						y += M;
					}
					if(x >= 0 && x < N && y >= 0 && y < M){
						if(visit[x][y] == false && board[x][y] == val){ // 범위 내에 존재하고, 방문한 적 없고, 인접한 값과 동일한 값을 갖는 원판이라면
							q.push_back({x,y});
							q_list.push_back({x,y});
							visit[x][y] = true; // 방문좌표 queue에 담고 방문 여부 표시
						}
					}
				}
			}
			
			if(q_list.size() > 1){ // 인접한 좌표가 1개 이상일 때(1개만 있으면 인접한거 없는 것... 혼자니까^^)
				flag = true; // 제거 진행할 것이므로 제거된 값 있다는 표시
				while(!q_list.empty()){
					Pos p = q_list.front();
					q_list.pop_front();
					
					sum -= val; // 제거된 값 전체 원판의 합에서 빼주기
					n_board--; // 값이 제거되었으므로 판의 개수도 1개 줄이기
					board[p.x][p.y] = -1; // 제거된 원판의 값은 -1로 설정
				}
			}
		}
	}
	
	if(flag == false && n_board != 0){ // 제거된 원판이 없다면 / n_board가 0이면 0으로 나누는 문제점 생길 수 있음(걸러주기)
		float avg = (float)sum/n_board; // 원판의 합의 평균 구하기
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(board[i][j] != -1){ // 원판의 값이 비어있지 않고
					if(board[i][j] > avg){ // 평균 값보다 크다면
						sum--;
						board[i][j]--; // 1 빼주기
					}
					else if(board[i][j] < avg){ //평균 값보다 작다면
						sum++;
						board[i][j]++; // 1 
					}
				}
			}
		}
	}
}
