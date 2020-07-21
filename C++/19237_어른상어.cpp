#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct Pos{
	int num, x, y, dir;
}; // 상어의 위치를 담을 구조체(상어의 번호, 행, 열, 방향)

struct Grid{
	int num, k;
	bool being;
}; // 상어의 흔적을 남기기 위한 구조체(상어의 번호, 냄새가 없어지기까지 얼마나 남았는지, 실제로 상어가 존재하는지)

bool cmp(Pos &a, Pos &b){
	return a.num < b.num;
} // 상어의 번호대로 deque를 정렬하기 위한 함수(오름차순으로 정렬)

int main() {
	int N, M, k;
	cin >> N >> M >> k;
	
	Grid **area = new Grid*[N];
	for(int i = 0; i < N; i++){
		area[i] = new Grid[N];
	} // 각 위치별 상어의 냄새 정보를 남기기 위한 배열
	
	deque<Pos> shark, smell; // 현재 존재하는 상어와 상어의 냄새가 남아있는 좌표를 담을 deque 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> area[i][j].num; // 해당 위치에 상어의 번호 입력
			area[i][j].num--; // 0부터 시작하게 하려고
			area[i][j].being = false; // 일단 상어가 없다고 가정
			
			if(area[i][j].num != -1){ // 해당 위치에 상어가 존재할 때
				area[i][j].k = k; // 냄새 k로 초기화
				area[i][j].being = true; // 상어가 있음을 표시
				shark.push_back({area[i][j].num,i,j,-1}); // 상어 정보 담기
			}
		}
	}
	
	sort(shark.begin(),shark.end(),cmp); // 상어의 번호대로 정렬 진행
	
	for(int i = 0; i < M; i++){
		Pos p = shark.front();
		shark.pop_front();
		
		cin >> p.dir;
		p.dir--;

		shark.push_back(p);
	} // 상어의 번호 별 상어의 방향 갱신
	
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	int shark_dir[M][4][4]; // 해당 상어의 이동 우선순위 담을 배열(상어가 상하좌우 위치를 가질 때, 이동 방향의 우선순위)
	for(int i = 0; i < M; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				cin >> shark_dir[i][j][k];
				shark_dir[i][j][k]--;
			}
		}
	}
	
	int n_shark = M, sec = 0; // 남아있는 상어의 수, 상어가 1마리 남기까지 걸리는 시간
	while(n_shark > 1 && sec <= 1000){
		sec++;
		
		int qsize = shark.size();
		while(qsize--){ // 상어를 이동시키기 위한 while
			Pos p = shark.front();
			shark.pop_front();
			
			area[p.x][p.y].being = false; // 상어가 이동할 것이기 때문에 현재 위치 상어가 없다고 수정
			
			smell.push_back(p); // 해당 위치는 상어의 흔적만 남게될 것
			
			bool flag = false; // 상하좌우에 빈 공간이 있는지를 나타냄
			for(int d = 0; d < 4; d++){
				int dx = p.x+dir[shark_dir[p.num][p.dir][d]][0];
				int dy = p.y+dir[shark_dir[p.num][p.dir][d]][1]; // 해당 번호의 상어의 방향에 따라 이동 방향 결정
				
				if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 범위 체크
					if(area[dx][dy].k == 0 && area[dx][dy].num == -1){ // 해당 공간이 비어있는 경우(상어도 없고 상어 흔적도 없고)
						shark.push_back({p.num,dx,dy,shark_dir[p.num][p.dir][d]}); // 이쪽으로 상어 이동
						flag = true; // 빈 공간이 있음을 표시 후
						break; // 이동 종료
					}
				}
			}
			
			if(flag){ // 빈공간으로 이동했으므로
				continue; // 더 이상 볼필요 없고 다음 상어 이동시키러...
			}
			
			// 빈공간이 없을 때는 현재 상어 본인의 흔적이 있는 곳으로 이동해야 함
			for(int d = 0; d < 4; d++){
				int dx = p.x+dir[shark_dir[p.num][p.dir][d]][0];
				int dy = p.y+dir[shark_dir[p.num][p.dir][d]][1]; // 해당 번호의 상어의 방향에 따라 이동 방향 결정
				
				if(dx >= 0 && dx < N && dy >= 0 && dy < N){ // 범위 체크
					if(area[dx][dy].num == p.num){ // 해당 공간이 현재 상어의 흔적이 있는 공간이라면
						shark.push_back({p.num,dx,dy,shark_dir[p.num][p.dir][d]}); // 이쪽으로 상어 이동
						break; // 더 이상 이동하지 않아도 됨
					}
				}
			}
		}
		
		qsize = shark.size();
		while(qsize--){ // 실제로 상어를 이동시킴
			Pos p = shark.front();
			shark.pop_front();
			
			if(area[p.x][p.y].being){ // 이미 상어가 있다면(더 숫자가 작은 상어가 존재하는 것임 -> 초기에 정렬했으니까)
				n_shark--; // 현재 상어는 소멸
				continue;
			}
			
			// 현재 위치에 상어가 없다면
			area[p.x][p.y].being = true;
			area[p.x][p.y].num = p.num;
			area[p.x][p.y].k = k;
			shark.push_back(p); // 현재 상어를 위치시킴
		}
		
		qsize = smell.size();
		while(qsize--){ // 상어의 냄새를 갱신하기 위함
			Pos p = smell.front();
			smell.pop_front();
			
			if(area[p.x][p.y].being){ // 현재 상어가 있는 위치라면.. 냄새 갱신할 필요 없음(상어가 이미 새로운 냄새 뿌렸으니까)
				continue;
			}
			
			// 상어가 없는 곳이라면
			area[p.x][p.y].k--; // 상어의 냄새의 유효 시간 1 줄여 줌
			if(area[p.x][p.y].k == 0){ // 상어의 냄새가 없어졌다면
				area[p.x][p.y].num = -1; // 상어도 없으므로 상어의 흔적 아예 없애기
				continue;
			}
			
			// 상어의 냄새 안 없어졌으면 다음 초에 또 흔적 줄여야 함 -> deque에 다시 추가
			smell.push_back(p);
		}
	}
	
	if(sec > 1000){ // 시간 초과로 루프를 탈출했다면
		sec = -1; // 걸린 시간 -1로 수정
	}
	
	cout << sec; // 걸린 시간 출력
	
	return 0;
}
