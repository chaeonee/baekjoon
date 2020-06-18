#include <iostream>
#include <queue>
using namespace std;

struct Pos{
	int x, y, dir, num;
}; // x좌표, y좌표, 방향, 명령횟수

Pos Go(int k, int x, int y, int dir);
int Turn(int turn_dir, int dir);

int main() {
	int M, N;
	cin >> M >> N;
	
	int map[M][N];
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	Pos start, end;
	cin >> start.x >> start.y >> start.dir; // 시작 좌표 및 방향
	cin >> end.x >> end.y >> end.dir; // 도착 좌표 및 방향
	start.x--; start.y--; start.dir--; start.num = 0;
	end.x--; end.y--; end.dir--; // 좌표가 1부터 시작하는 문제와 달리 좌표가 0부터 시작하도록 하였으므로 1씩 빼부면서 초기화
	
	bool plant[4][M][N]; // 현재 위치의 방향이 동서남북일 때의 방문 체크 따로 해 주어야 하기 때문에 3차원 배열 이용
	for(int k = 0; k < 4; k++){
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				plant[k][i][j] = false;
			}
		}
	} // 초기화
	
	queue<Pos> q;
	q.push(start);
	plant[start.dir][start.x][start.y] = true; // 시작점 queue에 넣고 방문 표시
	while(!q.empty()){ // bfs 진행
		Pos p = q.front();
		q.pop();
		
		if(p.x == end.x && p.y == end.y && p.dir == end.dir){ // 도착점에 도착하면
			cout << p.num; // 명령 횟수 출력 후(bfs로 진행하므로 이 때 출력된 명령 횟수가 최솟값)
			break; // 반복문 탈출
		}
		
		for(int k = 1; k <= 3; k++){ // 현재 향하고 있는 방향으로 k칸 이동(k는 1부터 3)
			Pos tmp_p = Go(k,p.x,p.y,p.dir);
			if(tmp_p.x < 0 || tmp_p.x >= M || tmp_p.y < 0 || tmp_p.y >= N || map[tmp_p.x][tmp_p.y] == 1){
				break;
			} // 이동 결과가 공장 범위를 넘어가거나 벽을 만나 더 이상 이동할 수 없다면 이동 종료
			
			if(plant[tmp_p.dir][tmp_p.x][tmp_p.y] == false){ // 현재 위치에 현재 방향으로 방문한 적 없다면
				tmp_p.num = p.num+1; // go 명령 사용 -> 명령 횟수 1 증가
				q.push(tmp_p);
				plant[tmp_p.dir][tmp_p.x][tmp_p.y] = true; // 방문 표시
			}
		}
		
		for(int d = 0; d <= 1; d++){ // 오른쪽, 왼쪽으로 회전
			int c_dir = Turn(d,p.dir);
			if(plant[c_dir][p.x][p.y] == false){ // 현재 위치에 현재 방향으로 방문한 적 없다면
				q.push({p.x,p.y,c_dir,p.num+1}); // turn 명령 사용 -> 명령 횟수 1 증가
				plant[c_dir][p.x][p.y] = true; // 방문 표시
			}
		}
	}
	
	return 0;
}

Pos Go(int k, int x, int y, int dir){ // 현재 향하고 있는 방향으로 k칸 이동한 좌표 구하는 함수
	Pos p;
	switch(dir){
		case 0: // 동쪽을 향하고 있는 경우
		p.x = x;
		p.y = y+k; // 열이 증가하는 방향(동쪽)으로 이동
		break;
		
		case 1: // 서쪽을 향하고 있는 경우
		p.x = x;
		p.y = y-k; // 열이 감소하는 방향(서쪽)으로 이동
		break;
		
		case 2: // 남쪽을 향하고 있는 경우
		p.x = x+k; // 행이 증가하는 방향(남쪽)으로 이동
		p.y = y;
		break;
		
		case 3: // 북쪽을 향하고 있는 경우
		p.x = x-k; // 행이 감소하는 방향(북쪽)으로 이동
		p.y = y;
		break;
	}	
	p.dir = dir;
	
	return p;
}

int Turn(int turn_dir, int dir){ // 현재 방향을 기준으로 오른쪽(0), 왼쪽(1) 90° 회전한 방향 구하는 함수
	int c_dir;
	if(turn_dir == 0){ // 오른쪽으로 90° 회전한 방향
		int d[4] = {2,3,1,0}; // {동,서,남,북} -> {남,북,서,동}
		c_dir = d[dir];
	}
	else{ // 왼쪽으로 90° 회전한 방향
		int d[4] = {3,2,0,1}; // {동,서,남,북} -> {북,남,동,서}
		c_dir = d[dir];
	}
	
	return c_dir;
}
