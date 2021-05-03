#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Vacuum{
	int r, c, dir;
};

int main() {
	int N, M;
	cin >> N >> M;
	
	int **area = new int*[N];
	int **visit = new int*[N];
	for(int i = 0; i < N; i++){
		area[i] = new int[M];
		visit[i] = new int[M];
		memset(visit[i],0,sizeof(int)*M);
	}
	
	Vacuum v;
	cin >> v.r >> v.c >> v.dir;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> area[i][j];
		}
	}
	
	int left[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};//NESW
	int behind[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};//NESW
	int rotate[4] = {3,0,1,2};//NESW
	
	queue<Vacuum> q;
	q.push(v);
	
	int result = 0;
	int rotate_num = 0;
	while(!q.empty()){//0: 북, 1: 동, 2: 남, 3: 서
		v = q.front();
		q.pop();
		
		if(rotate_num == 4){
			if(area[v.r+behind[v.dir][0]][v.c+behind[v.dir][1]] == 1){//뒤가 벽일 경우
				if(visit[v.r][v.c] == 0){
					result++;
				}
				break;
			}
			else{
				if(visit[v.r][v.c] == 0){
					result++;
					visit[v.r][v.c] = 1;
				}
				rotate_num = 0;
				
				Vacuum vac;
				vac.r = v.r+behind[v.dir][0];
				vac.c = v.c+behind[v.dir][1];
				vac.dir = v.dir;
				
				q.push(vac);
			}
		}
			
		else{
			if(visit[v.r+left[v.dir][0]][v.c+left[v.dir][1]] == 0
				&& area[v.r+left[v.dir][0]][v.c+left[v.dir][1]] == 0){//왼쪽 갈 수 있는 경우
				if(visit[v.r][v.c] == 0){
					result++;
					visit[v.r][v.c] = 1;
				}
				rotate_num = 0;
				
				Vacuum vac;
				vac.r = v.r+left[v.dir][0];
				vac.c = v.c+left[v.dir][1];
				vac.dir = rotate[v.dir];
				
				q.push(vac);
			}
			else if(visit[v.r+left[v.dir][0]][v.c+left[v.dir][1]] == 1 
				|| area[v.r+left[v.dir][0]][v.c+left[v.dir][1]] == 1){//벽이거나 청소 한 경우
				rotate_num++;
				
				Vacuum vac;
				vac.r = v.r;
				vac.c = v.c;
				vac.dir = rotate[v.dir];
				
				q.push(vac);
			}
		}
	}
	
	cout << result;
	
	return 0;
}
