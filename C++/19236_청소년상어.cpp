#include <iostream>
#include <algorithm>
using namespace std;

struct Fish{
	bool being = true;
	int x, y, dir;
};

void getFish(Fish *fish, int **sea, int taken);
void moveFish(Fish *fish, int **sea);
void copyInfo(Fish *fish, Fish *tmp_fish, int **sea, int **tmp_sea);

int max_taken; // 상어가 먹을 수 있는 물고기 번호의 합의 최댓값을 담을 변수
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Fish *fish = new Fish[17]; // 각 번호의 물고기가 잡아먹히지 않았는지와 물고기의 좌표, 방향(0번 물고기는 상어)
	int **sea = new int*[4]; // 바다 공간, 물고기의 번호가 적혀있음
	for(int i = 0; i < 4; i++){
		sea[i] = new int[4];
		for(int j = 0; j < 4; j++){
			int num, dir;
			cin >> num >> dir;
			if(i == 0 && j == 0){ // 상어가 (0,0)에 있는 물고기를 잡어먹고 시작하기 때문에 (0,0)은 상어의 위치
				max_taken = num; // (0,0)의 물고기 번호가 물고기 번호의 합의 초기값이 될 것
				sea[i][j] = 0; // 상어 표시
				
				fish[num].being = false; // 상어에게 잡어먹혔으므로 살아있지 않음으로 표시
				fish[num].x = 0;
				fish[num].y = 0;
				fish[num].dir = 0;
				
				// 상어의 위치 기록
				fish[0].being = true;
				fish[0].x = i;
				fish[0].y = j;
				fish[0].dir = dir-1;
				continue;
			}
			
			// 상어가 아닌 경우 -> 물고기의 위치 및 방향 기록
			sea[i][j] = num;
			
			fish[num].being = true;
			fish[num].x = i;
			fish[num].y = j;
			fish[num].dir = dir-1;
		}
	}
	
	int taken = max_taken;
	getFish(fish,sea,taken);
	
	cout << max_taken;
	
	return 0;
}

void getFish(Fish *fish, int **sea, int taken){ // 상어가 물고기를 잡아먹는 것을 구현
	max_taken = max(max_taken,taken);
	
	Fish *tmp_fish = new Fish[17];
	int **tmp_sea = new int*[4];
	for(int i = 0; i < 4; i++){
		tmp_sea[i] = new int[4];
	} // 초기화를 위한 값을 저장하기 위한 배열
	
	moveFish(fish,sea); // 물고기 이동
	
	copyInfo(fish,tmp_fish,sea,tmp_sea); // 초기화를 위해 값을 저장해 놓음(복사)
	
	int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}}; // 문제에서 주어진 방향(상하좌우와 대각선)
	for(int i = 1; i < 4; i++){ // 4X4 영역이므로 상어는 3칸이상 이동하지 못함 -> 따라서 3번까지만 이동)
		int x = fish[0].x+(dir[fish[0].dir][0]*i), y = fish[0].y+(dir[fish[0].dir][1]*i); // 상어의 이동 좌표 계산
		if(x >= 0 && x < 4 && y >= 0 && y < 4){ // 범위 밖을 벗어나지 않는 경우
			if(sea[x][y] == -1){ // 이동하려는 좌표에 물고기가 없는 경우
				continue; // 이동할 수 없음
			}
			
			int tmp_num = sea[x][y]; // 이동 좌표에 있는 물고기 번호
			
			fish[tmp_num].being = false; // 해당 물고기 잡아먹기 때문에 살아있지 않음으로 표시
			sea[x][y] = 0; // 상어가 물고기 자리 차지
			sea[fish[0].x][fish[0].y] = -1; // 원래 상어 자리는 비게 됨
			fish[0].x = x;
			fish[0].y = y; // 상어의 위치 좌표 갱신
			fish[0].dir = fish[tmp_num].dir; // 잡아먹은 물고기 방향으로 상어 방향 변경
			taken += tmp_num; // 잡아 먹은 물고기 번호의 합에 현재 잡아 먹은 물고기 번호 더해줌 
			
			getFish(fish,sea,taken); // 다음 이동을 위한 재귀
			
			copyInfo(tmp_fish,fish,tmp_sea,sea); // 이전 상태로 복귀
			taken -= tmp_num; // 잡아 먹은 물고기 번호의 합도 이전 상태로 복귀
		}
		else{ // 범위 밖을 벗어나는 경우 상어는 집에감 -> 더 이상 탐색하지 않음
			break;
		}
	}
}

void moveFish(Fish *fish, int **sea){ // 물고기를 이동시키기 위한 함수
	int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}}; // 이동 방향(상하좌우, 대각선)
	for(int i = 1; i <= 16; i++){ // 물고기 번호가 작은 순서대로 이동
		if(!fish[i].being){ // 살아있지 않으면 이동할 필요 없음
			continue;
		}
		
		int x = fish[i].x, y = fish[i].y, f_dir = fish[i].dir; // 물고기의 현재 위치와 방향
		for(int d = 0; d < 8; d++){ // 이동하지 못하는 경우 방향을 바꿔야 함(반시계로)
			int dx = x+dir[f_dir][0], dy = y+dir[f_dir][1]; // 물고기가 이동할 좌표 계산
			if(dx >= 0 && dx < 4 && dy >= 0 && dy < 4){ // 범위 체크
				if(sea[dx][dy] != -1 && sea[dx][dy] != 0){ // 상어가 아닌 물고기가 있는 경우
					fish[sea[dx][dy]].x = x;
					fish[sea[dx][dy]].y = y;
					sea[x][y] = sea[dx][dy]; // 이동할 위치에 있는 물고기를 현재 물고기의 위치로 바꾸기
					
					fish[i].x = dx;
					fish[i].y = dy;
					fish[i].dir = f_dir;
					sea[dx][dy] = i; // 현재 물고기 이동
					
					break;
				}
				else if(sea[dx][dy] == -1){ // 이동할 위치에 아무 물고기도 없는 경우
					fish[i].x = dx;
					fish[i].y = dy;
					fish[i].dir = f_dir;
					sea[dx][dy] = i; // 위치 이동 및 방향 설정
					sea[x][y] = -1; // 이동 전 위치는 비게 됨
					
					break;
				}
			}
			f_dir = (f_dir+1) % 8; // 현재 위치로 이동할 수 없는 경우이므로 방향 바꿔줘야 함(반시계로 이동)
		}
	}
}

void copyInfo(Fish *fish, Fish *tmp_fish, int **sea, int **tmp_sea){ // 정보 복사를 위한 함수
	for(int i = 0; i < 17; i++){
		tmp_fish[i] = fish[i];
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			tmp_sea[i][j] = sea[i][j];
		}
	}
}
