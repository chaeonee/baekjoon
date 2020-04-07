#include <iostream>
#include <cstring>
using namespace std;

double p;

void move(int N, int s, int x, int y, bool **visit, double p_dir[], double cur){
	if(s == N){ // N번의 이동이 끝나면 확률 더해줌
		p += cur;
		return;
	}
	
	int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; // 동서남북
	for(int i = 0; i < 4; i++){ // 동서남북 이동하기 위함
		int nx = x+dir[i][0], ny = y+dir[i][1]; // 이동 후 좌표
		if(nx >= 0 && nx < 2*N+1 && ny >= 0 && ny < 2*N+1){ // 이동 후 좌표가 범위 내에 있고
			if(visit[nx][ny] == false){ // 방문한 적 없으면
				visit[nx][ny] = true;  // 방문 표시 후
				move(N,s+1,nx,ny,visit,p_dir,cur*p_dir[i]); // 재귀
				visit[nx][ny] = false; // 모두 방문 했으면 다음 경우의 수 생각해야 하기 때문에 방문 표시 취소(백트래킹)
			}
		}
	}
}

int main() {
	int N;
	double p_dir[4];
	cin >> N;
	for(int i = 0; i < 4; i++){
		cin >> p_dir[i];
		p_dir[i] /= 100; // 0~100사이의 퍼센트 값을 0~1사이의 확률로 바꾸기 위해 100으로 나눠주기
	}
	
	bool **visit = new bool*[2*N+1];
	for(int i = 0; i < 2*N+1; i++){
		visit[i] = new bool[2*N+1];
		memset(visit[i],false,sizeof(bool)*(2*N+1));
	}
	
	visit[N][N] = true; // 방문 여부 표시
	
	move(N,0,N,N,visit,p_dir,1);
	
	cout << fixed;
	cout.precision(10); // 10^-9 오차까지 허용하기 때문에 10자리까지는 출력해줘야 함
	cout << p;
	
	
	return 0;
}
